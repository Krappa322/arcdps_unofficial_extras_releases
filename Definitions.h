#pragma once

#include "KeyBindStructs.h"

#include <cstdint>
#include <Windows.h>

enum class UserRole : uint8_t
{
	SquadLeader = 0,
	Lieutenant = 1,
	Member = 2,
	Invited = 3,
	Applied = 4,
	None = 5,
	Invalid = 6 // Internal only
};

struct UserInfo
{
	const char* AccountName; // Null terminated account name, including leading ':'. Only valid for the duration of the call

	// Unix timestamp when the user joined the squad (or 0 if time could not be determined)
	__time64_t JoinTime;

	UserRole Role; // Role in squad, or ::None if the user was removed from the squad

	// Subgroup the user is in (0 when no subgroup could be found, which is either the first subgroup or no subgroup)
	uint8_t Subgroup;

	// Whether this player is ready or not (in a squad ready check). Role == UserRole::SquadLeader and ReadyStatus == true
	// implies that a ready check was just started. Similarly, Role == UserRole::SquadLeader and ReadyStatus == false
	// implies that a ready check either finished or was cancelled. If everyone in the squad had an event sent with
	// ReadyStatus == true then that means that the ready check finished successfully (after which there will be events
	// sent for each user where their ReadyStatus == false)
	bool ReadyStatus;

	uint8_t _Unused1 = 0; // padding
	uint32_t _Unused2 = 0; // padding

	UserInfo(const char* pAccountName, __time64_t pJoinTime, UserRole pRole, uint8_t pSubgroup, bool pReadyStatus)
		: AccountName{pAccountName}
		, JoinTime{pJoinTime}
		, Role{pRole}
		, Subgroup{pSubgroup}
		, ReadyStatus{pReadyStatus}
	{
	}
};

enum class Language : int32_t
{
	English = 0,
	French = 2,
	German = 3,
	Spanish = 4,
	Chinese = 5
};

enum class ChannelType : uint8_t
{
	Party = 0,
	Squad = 1,
	_Reserved = 2,
	Invalid = 3
};

struct SquadMessageInfo
{
	// A unique identifier for the channel this chat message was sent over. Can be used to, for example, differentiate
	// between squad messages sent to different squads
	uint32_t ChannelId;

	// Whether the message is sent in a party or a squad. Note that messages sent to the party chat while in a squad will
	// have the type ChannelType::Squad
	ChannelType Type;

	// The subgroup the message was sent to, or UINT8_MAX if it was sent to the entire squad.
	uint8_t Subgroup;

	// The lowest bit of this field will be set to 1 if the message is a broadcast, and 0 if it is not a broadcast. The
	// upper bits of this field may be used in a later version and MUST NOT be interpreted
	uint8_t IsBroadcast;

	uint8_t _Unused1 = 0; // padding

	// Null terminated iso8601 formatted string denoting when this message was received by the server, e.g.
	// "2022-07-09T11:45:24.888Z". This is the "absolute ordering" for chat messages, however the time can potentially
	// differ several seconds between the client and server because of latency and clock skew.
	// The string is only valid for the duration of the call.
	const char* Timestamp;
	uint64_t TimestampLength;

	// Null terminated account name of the player that sent the message, including leading ':'.
	// The string is only valid for the duration of the call.
	const char* AccountName;
	uint64_t AccountNameLength;

	// Null terminated character name of the player that sent the message.
	// The string is only valid for the duration of the call.
	const char* CharacterName;
	uint64_t CharacterNameLength;

	// Null terminated string containing the content of the message that was sent.
	// The string is only valid for the duration of the call.
	const char* Text;
	uint64_t TextLength;
};

struct NpcMessageInfo
{
	// Null terminated character name of the NPC or the player character.
	// The string is only valid for the duration of the call.
	const char* CharacterName;
	uint64_t CharacterNameLength;

	// Null terminated string of the message said by an npc or the user character.
	// The string is only valid for the duration of the call.
	const char* Message;
	uint64_t MessageLength;
};

struct ExtrasAddonInfo
{
	// Version of the api, gets incremented whenever a function signature or behavior changes in a breaking way.
	// Current version is 2.
	uint32_t ApiVersion = 0;

	// Highest known version of the ExtrasSubscriberInfo struct. Also determines the size of the pSubscriberInfo buffer
	// in the init call (the buffer is only guaranteed to have enough space for known ExtrasSubscriberInfo versions)
	// Current version is 3.
	uint32_t MaxInfoVersion = 0;

	// Null terminated string version of unofficial_extras addon, gets changed on every release.
	// The string is valid for the lifetime of the unofficial_extras dll.
	const char* StringVersion = nullptr;

	// Null terminated account name of the logged in player, including leading ':'.
	// The string is only valid for the duration of the init call.
	const char* SelfAccountName = nullptr;

	// The handle to the unofficial_extras module.
	// Use this to call the exports of the DLL.
	HMODULE ExtrasHandle = nullptr;
};

enum ChatMessageType
{
	// Called for party/squad messages. 
	Squad = 0,

	// Called for NPC Channel (selectable in ingame-chat as "NPC")
	NPC = 1,
};

union ChatMessageInfo2
{
	// party/squad messages
	SquadMessageInfo* SquadMessage;
	NpcMessageInfo* NpcMessage;
};

typedef void (*SquadUpdateCallbackSignature)(const UserInfo* pUpdatedUsers, uint64_t pUpdatedUsersCount);
typedef void (*LanguageChangedCallbackSignature)(Language pNewLanguage);
typedef void (*KeyBindChangedCallbackSignature)(KeyBinds::KeyBindChanged pChangedKeyBind);
typedef void (*ChatMessageCallbackSignature)(const SquadMessageInfo* pChatMessage);
typedef void (*ChatMessageInfoSignature2)(ChatMessageType pMessageType, ChatMessageInfo2 pChatMessage);

struct ExtrasSubscriberInfoHeader
{
	// The version of the following info struct
	// This has to be set to the version you want to use.
	uint32_t InfoVersion = 0;

	uint32_t _Unused1 = 0; // padding
};

// InfoVersion = 1
struct ExtrasSubscriberInfoV1 : ExtrasSubscriberInfoHeader
{
	// Null terminated name of the addon subscribing to the changes. Must be valid for the lifetime of the subscribing addon.
	// Set to `nullptr` if initialization fails
	const char* SubscriberName = nullptr;

	// Called whenever anything in the squad changes. Only the users that changed are sent.
	// If a user is removed from the squad, it will be sent with Role == UserRole::None
	SquadUpdateCallbackSignature SquadUpdateCallback = nullptr;

	// Called whenever the language is changed. Either by Changing it in the UI or by pressing the Right Ctrl (default) key.
	// Will also be called directly after initialization, with the current language, to get the startup language.
	LanguageChangedCallbackSignature LanguageChangedCallback = nullptr;

	// Called whenever a KeyBind is changed.
	// By changing it in the ingame UI, by pressing the translation shortcut or with the Presets feature of this plugin.
	// It is called for every keyBind separately.
	//
	// After initialization this is called for every current keybind that exists.
	// If you want to get a single keybind, at any time you want, call the exported function.
	KeyBindChangedCallbackSignature KeyBindChangedCallback = nullptr;
};

// InfoVersion = 2
struct ExtrasSubscriberInfoV2 : ExtrasSubscriberInfoV1
{
	// Called whenever a chat message is sent in your party/squad
	ChatMessageCallbackSignature ChatMessageCallback = nullptr;
};

// InfoVersion = 3
struct ExtrasSubscriberInfoV3 : ExtrasSubscriberInfoV2
{
	// Called on different chat messages.
	// See `ChatMessageType` for the available chats.
	ChatMessageInfoSignature2 ChatMessageCallback2 = nullptr;
};

// This function must be exported by subscriber addons as 'arcdps_unofficial_extras_subscriber_init'.
// It's called once at startup. Can be called before or after arcdps calls mod_init.
//
// The callee MUST verify that pExtrasInfo->ApiVersion is the version it expects (which is the current ApiVersion when
// the callee was written). The callee MUST verify that pExtrasInfo->MaxInfoVersion is equal to or higher than the
// ExtrasSubscriberInfo struct version it intends to use (to ensure that the buffer has enough room for the info
// struct). The callee MAY use the pExtrasInfo->MaxInfoVersion field to dynamically determine which info version to use,
// in order to gain backwards compatibility. If any of these verifications fail, the callee SHOULD return without
// modifying the buffer pointed to by pSubscriberInfo.
//
// The callee MUST populate the buffer pointed to by pSubscriberInfo with one of the ExtrasSubscriberInfo structs
// above. If initialization fails, the callee SHOULD leave the buffer untouched to indicate initialization failure
typedef void (*ExtrasSubscriberInitSignature)(const ExtrasAddonInfo* pExtrasInfo, void* pSubscriberInfo);
