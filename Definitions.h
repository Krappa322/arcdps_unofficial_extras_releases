#pragma once

#include <cstdint>
#include <ctime>

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

enum class Language
{
	English = 0,
	French = 2,
	German = 3,
	Spanish = 4,
	Chinese = 5
};

struct ExtrasAddonInfo
{
	// Version of the api, gets incremented whenever a function signature or behavior changes in a breaking way.
	// Current version is 1.
	uint32_t ApiVersion = 0;

	uint32_t _Unused = 0; // padding

	// Null terminated string version of unofficial_extras addon, gets changed on every release. The string is valid for the lifetime
	// of the unofficial_extras dll.
	const char* StringVersion = nullptr;

	// Null terminated account name of the logged in player, including leading ':'. The string is only valid for the duration of the init call.
	const char* SelfAccountName = nullptr;
};

typedef void (*SquadUpdateCallbackSignature)(const UserInfo* pUpdatedUsers, uint64_t pUpdatedUsersCount);
typedef void (*LanguageChangedCallbackSignature)(Language pNewLanguage);
struct ExtrasSubscriberInfo
{
	// Null terminated name of the addon subscribing to the changes. Must be valid for the lifetime of the subcribing addon. Set to
	// nullptr if initialization fails
	const char* SubscriberName = nullptr;

	// Called whenever anything in the squad changes. Only the users that changed are sent. If a user is removed from
	// the squad, it will be sent with Role == UserRole::None
	SquadUpdateCallbackSignature SquadUpdateCallback = nullptr;

	// Called whenever the language is changed. Either by Changing it in the UI or by pressing the Right Ctrl (default) key.
	// Will also be called directly after initialization, with the current language, to get the startup language.
	LanguageChangedCallbackSignature LanguageChangedCallback = nullptr;
};

// This function must be exported by subscriber addons as 'arcdps_unofficial_extras_subscriber_init'. It's called once
// at startup. Can be called before or after arcdps calls mod_init. Set SubscriberName to nullptr if initialization fails.
typedef void (*ExtrasSubscriberInitSignature)(const ExtrasAddonInfo* pExtrasInfo, ExtrasSubscriberInfo* pSubscriberInfo);
