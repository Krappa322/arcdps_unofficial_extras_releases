#pragma once

#ifdef UNOFFICIAL_EXTRAS_EXPORTS
#define UNOFFICIAL_EXTRAS_API __declspec(dllexport)
#else
#define UNOFFICIAL_EXTRAS_API __declspec(dllimport)
#endif

#include <cstdint>

namespace KeyBinds
{
	enum class KeyControl : int32_t
	{
		// Movement tab
		Movement_MoveForward = 0,
		Movement_MoveBackward = 1,
		Movement_StrafeLeft = 2,
		Movement_StrafeRight = 3,
		Movement_TurnLeft = 4,
		Movement_TurnRight = 5,
		Movement_Dodge = 6,
		Movement_Autorun = 7,
		Movement_Walk = 8,
		Movement_Jump = 9,
		Movement_SwimUp = 10,
		Movement_SwimDown = 11,
		Movement_AboutFace = 12,

		// Skills tab
		Skills_SwapWeapons = 17,
		Skills_WeaponSkill1 = 18,
		Skills_WeaponSkill2 = 19,
		Skills_WeaponSkill3 = 20,
		Skills_WeaponSkill4 = 21,
		Skills_WeaponSkill5 = 22,
		Skills_HealingSkill = 23,
		Skills_UtilitySkill1 = 24,
		Skills_UtilitySkill2 = 25,
		Skills_UtilitySkill3 = 26,
		Skills_EliteSkill = 27,
		Skills_ProfessionSkill1 = 28,
		Skills_ProfessionSkill2 = 29,
		Skills_ProfessionSkill3 = 30,
		Skills_ProfessionSkill4 = 31,
		Skills_ProfessionSkill5 = 79,
		Skills_ProfessionSkill6 = 201,
		Skills_ProfessionSkill7 = 202,
		Skills_SpecialAction = 82,

		// Targeting tab
		Targeting_AlertTarget = 131,
		Targeting_CallTarget = 32,
		Targeting_TakeTarget = 33,
		Targeting_SetPersonalTarget = 199,
		Targeting_TakePersonalTarget = 200,
		Targeting_NearestEnemy = 34,
		Targeting_NextEnemy = 35,
		Targeting_PreviousEnemy = 36,
		Targeting_NearestAlly = 37,
		Targeting_NextAlly = 38,
		Targeting_PreviousAlly = 39,
		Targeting_LockAutotarget = 40,
		Targeting_SnapGroundTarget = 80,
		Targeting_ToggleSnapGroundTarget = 115,
		Targeting_DisableAutotargeting = 116,
		Targeting_ToggleAutotargeting = 117,
		Targeting_AllyTargetingMode = 197,
		Targeting_ToggleAllyTargetingMode = 198,

		// UI Tab
		UI_BlackLionTradingDialog = 41,
		UI_ContactsDialog = 42,
		UI_GuildDialog = 43,
		UI_HeroDialog = 44,
		UI_InventoryDialog = 45,
		UI_PetDialog = 46,
		UI_LogOut = 47,
		UI_MailDialog = 71,
		UI_OptionsDialog = 48,
		UI_PartyDialog = 49,
		UI_PvPPanel = 73,
		UI_PvPBuild = 75,
		UI_Scoreboard = 50,
		UI_WizardsVaultDialog = 209,
		UI_InformationDialog = 51,
		UI_Show_HideChat = 70,
		UI_ChatCommand = 52,
		UI_ChatMessage = 53,
		UI_ChatReply = 54,
		UI_ShowHideUI = 55,
		UI_ShowHideSquadBroadcastChat = 85,
		UI_SquadBroadcastChatCommand = 83,
		UI_SquadBroadcastMessage = 84,

		// Camera Tab
		Camera_FreeCamera = 13,
		Camera_ZoomIn = 14,
		Camera_ZoomOut = 15,
		Camera_LookBehind = 16,
		Camera_ToggleActionCamera = 78,
		Camera_DisableActionCamera = 114,

		// Screenshot Tab
		Screenshot_Normal = 56,
		Screenshot_Stereoscopic = 57,

		// Map Tab
		Map_OpenClose = 59,
		Map_Recenter = 60,
		Map_FloorDown = 61,
		Map_FloorUp = 62,
		Map_ZoomIn = 63,
		Map_ZoomOut = 64,

		// Mounts Tab
		Mounts_MountDismount = 152,
		Mounts_MountAbility1 = 130,
		Mounts_MountAbility2 = 153,
		Mounts_Raptor = 155,
		Mounts_Springer = 156,
		Mounts_Skimmer = 157,
		Mounts_Jackal = 158,
		Mounts_Griffon = 159,
		Mounts_RollerBeetle = 161,
		Mounts_Warclaw = 169,
		Mounts_Skyscale = 170,
		Mounts_Turtle = 203,

		// Spectators Tab
		Spectators_NearestFixedCamera = 102,
		Spectators_NearestPlayer = 103,
		Spectators_RedPlayer1 = 104,
		Spectators_RedPlayer2 = 105,
		Spectators_RedPlayer3 = 106,
		Spectators_RedPlayer4 = 107,
		Spectators_RedPlayer5 = 108,
		Spectators_BluePlayer1 = 109,
		Spectators_BluePlayer2 = 110,
		Spectators_BluePlayer3 = 111,
		Spectators_BluePlayer4 = 112,
		Spectators_BluePlayer5 = 113,
		Spectators_FreeCamera = 120,
		Spectators_FreeCameraBoost = 127,
		Spectators_FreeCameraForward = 121,
		Spectators_FreeCameraBackward = 122,
		Spectators_FreeCameraLeft = 123,
		Spectators_FreeCameraRight = 124,
		Spectators_FreeCameraUp = 125,
		Spectators_FreeCameraDown = 126,

		// Squad Tab
		Squad_Location_Arrow = 86,
		Squad_Location_Circle = 87,
		Squad_Location_Heart = 88,
		Squad_Location_Square = 89,
		Squad_Location_Star = 90,
		Squad_Location_Spiral = 91,
		Squad_Location_Triangle = 92,
		Squad_Location_X = 93,
		Squad_ClearAllLocationMarkers = 119,
		Squad_Object_Arrow = 94,
		Squad_Object_Circle = 95,
		Squad_Object_Heart = 96,
		Squad_Object_Square = 97,
		Squad_Object_Star = 98,
		Squad_Object_Spiral = 99,
		Squad_Object_Triangle = 100,
		Squad_Object_X = 101,
		Squad_ClearAllObjectMarkers = 118,

		// Mastery Skills Tab
		MasterySkills_ActivateMasterySkill = 196,
		MasterySkills_StartFishing = 204,
		MasterySkills_SummonSkiff = 205,
		MasterySkills_SetJadeBotWaypoint = 206,
		MasterySkills_ScanForRift = 207,
		MasterySkills_SkyscaleLeap = 208,
		MasterySkills_ConjuredDoorway = 211,

		// Miscellaneous Tab
		Miscellaneous_AoELoot = 74,
		Miscellaneous_Interact = 65,
		Miscellaneous_ShowEnemyNames = 66,
		Miscellaneous_ShowAllyNames = 67,
		Miscellaneous_StowDrawWeapon = 68,
		Miscellaneous_ToggleLanguage = 69,
		Miscellaneous_RangerPetCombatToggle = 76,
		Miscellaneous_ToggleFullScreen = 160,
		Miscellaneous_EquipUnequipNovelty = 162,
		Miscellaneous_ActivateChair = 163,
		Miscellaneous_ActivateMusicalInstrument = 164,
		Miscellaneous_ActivateHeldItem = 165,
		Miscellaneous_ActivateToy = 166,
		Miscellaneous_ActivateTonic = 167,
		Miscellaneous_DecorateModeToggle = 210,

		// Templates Tab
		Templates_BuildTemplate1 = 171,
		Templates_BuildTemplate2 = 172,
		Templates_BuildTemplate3 = 173,
		Templates_BuildTemplate4 = 174,
		Templates_BuildTemplate5 = 175,
		Templates_BuildTemplate6 = 176,
		Templates_BuildTemplate7 = 177,
		Templates_BuildTemplate8 = 178,
		Templates_BuildTemplate9 = 179,
		Templates_EquipmentTemplate1 = 182,
		Templates_EquipmentTemplate2 = 183,
		Templates_EquipmentTemplate3 = 184,
		Templates_EquipmentTemplate4 = 185,
		Templates_EquipmentTemplate5 = 186,
		Templates_EquipmentTemplate6 = 187,
		Templates_EquipmentTemplate7 = 188,
		Templates_EquipmentTemplate8 = 189,
		Templates_EquipmentTemplate9 = 190,
	};
	constexpr int32_t KEY_CONTROL_SIZE = 177;

	// Some of them are not usable (like F13-F35 or PRINT)
	// These are custom scan codes.
	// Names are based upon US keyboard layout.
	// Site to translate it to other languages: http://kbdlayout.info
	enum class KeyCode : int32_t
	{
		LeftAlt = 0,
		LeftCtrl = 1,
		LeftShift = 2,
		Quote = 3,
		Hash = 4,
		CapsLock = 5,
		Colon = 6,
		Minus = 7,
		Equals = 8,
		Escape = 9,
		OpenBracket = 10,
		NumLock = 11,
		Period = 12,
		CloseBracket = 13,
		Semicolon = 14,
		Slash = 15,
		Print = 16,
		Tilde = 17,
		Backspace = 18,
		Delete = 19,
		Enter = 20,
		Space = 21,
		Tab = 22,
		End = 23,
		Home = 24,
		Insert = 25,
		Next = 26,
		Prior = 27,
		ArrowDown = 28,
		ArrowLeft = 29,
		ArrowRight = 30,
		ArrowUp = 31,
		F1 = 32,
		F2 = 33,
		F3 = 34,
		F4 = 35,
		F5 = 36,
		F6 = 37,
		F7 = 38,
		F8 = 39,
		F9 = 40,
		F10 = 41,
		F11 = 42,
		F12 = 43,
		_0 = 48,
		_1 = 49,
		_2 = 50,
		_3 = 51,
		_4 = 52,
		_5 = 53,
		_6 = 54,
		_7 = 55,
		_8 = 56,
		_9 = 57,
		A = 65,
		B = 66,
		C = 67,
		D = 68,
		E = 69,
		F = 70,
		G = 71,
		H = 72,
		I = 73,
		J = 74,
		K = 75,
		L = 76,
		M = 77,
		N = 78,
		O = 79,
		P = 80,
		Q = 81,
		R = 82,
		S = 83,
		T = 84,
		U = 85,
		V = 86,
		W = 87,
		X = 88,
		Y = 89,
		Z = 90,
		PlusNum = 91,
		DecimalNum = 92,
		DivideNum = 93,
		MultiplyNum = 94,
		_0_NUM = 95,
		_1_NUM = 96,
		_2_NUM = 97,
		_3_NUM = 98,
		_4_NUM = 99,
		_5_NUM = 100,
		_6_NUM = 101,
		_7_NUM = 102,
		_8_NUM = 103,
		_9_NUM = 104,
		EnterNum = 105,
		MinusNum = 106,
		ImeKey1 = 107,
		ImeKey2 = 108,
		RightAlt = 109,
		RightCtrl = 110,
		Backslash = 111,
		F13 = 112,
		F14 = 113,
		F15 = 114,
		F16 = 115,
		F17 = 116,
		F18 = 117,
		F19 = 118,
		F20 = 119,
		F21 = 120,
		F22 = 121,
		F23 = 122,
		F24 = 123,
		F25 = 124,
		F26 = 125,
		F27 = 126,
		F28 = 127,
		F29 = 128,
		F30 = 129,
		F31 = 130,
		F32 = 131,
		F33 = 132,
		F34 = 133,
		F35 = 134,
		RightShift = 135,
		Eject = 136,
		EqualNum = 137,
		ClearNum = 138,
		LeftCmd = 139,
		Function = 140,
		RightCmd = 141,

		// additional, not used by GW2
		Scroll = 200,
		Pause = 201,
		LeftWin = 202,
		RightWin = 203,
		Menu = 204
	};
	constexpr int32_t KEY_CODES_SIZE_GW2 = 131;
	constexpr int32_t KEY_CODES_SIZE = 136;
	constexpr int32_t KEY_CODES_SIZE_TRANSLATION = 87; // Literals (A-Z0-9) and OEM Keys are not in there

	enum class MouseCode : int32_t
	{
		Mouse_1 = 0,
		Mouse_3 = 1,
		Mouse_2 = 2,
		Mouse_4 = 3,
		Mouse_5 = 4,
		Mouse_6 = 5,
		Mouse_7 = 6,
		Mouse_8 = 7,
		Mouse_9 = 8,
		Mouse_10 = 9,
		Mouse_11 = 10,
		Mouse_12 = 11,
		Mouse_13 = 12,
		Mouse_14 = 13,
		Mouse_15 = 14,
		Mouse_16 = 15,
		Mouse_17 = 16,
		Mouse_18 = 17,
		Mouse_19 = 18,
		Mouse_20 = 19
	};
	constexpr int32_t MOUSE_CODES_SIZE = 20;

	enum class DeviceType : int32_t
	{
		Unset = 0,
		Mouse = 1,
		Keyboard = 2
	};
	constexpr int32_t DEVICE_TYPE_SIZE = 3;

	enum Modifier_ : int32_t
	{
		Modifier_Shift = 1,
		Modifier_Ctrl = 2,
		Modifier_Alt = 4
	};
	constexpr int32_t MODIFIER_SIZE = 3;
	typedef int32_t Modifier; // -> enum Modifier_

	// A single KeyBind
	struct Key
	{
		DeviceType DeviceType = DeviceType::Unset; /** 0|1|2 (0 = unset, 1 = MouseKey, 2 = KeyboardKey) */
		int32_t Code = 0; /** depends on `deviceType`. MouseCode or KeyCode depending on `DeviceType` */
		Modifier Modifier = 0; /** modifier flags (Bit 1 = Shift, Bit 2 = Ctrl, Bit 3 = Alt) */

		bool operator==(const Key& other) const {
			return other.DeviceType == DeviceType && other.Code == Code && other.Modifier == Modifier;
		}
	};

	struct KeyBind
	{
		Key Primary;
		Key Secondary;
	};

	struct KeyBindChanged
	{
		KeyControl KeyControl;
		uint32_t KeyIndex;
		Key SingleKey;
	};

	inline Modifier GetModifier(KeyCode pKeyCode)
	{
		if (pKeyCode == KeyCode::LeftShift || pKeyCode == KeyCode::RightShift)
		{
			return Modifier_Shift;
		}
		if (pKeyCode == KeyCode::LeftAlt || pKeyCode == KeyCode::RightAlt)
		{
			return Modifier_Alt;
		}
		if (pKeyCode == KeyCode::LeftCtrl || pKeyCode == KeyCode::RightCtrl)
		{
			return Modifier_Ctrl;
		}
		return 0;
	}
}

// pKeyIndex is either 0 or 1, notating the primary and secondary key for the keybind respectively
// These functions will return an empty/default Key, if the key is not set OR if the functionality is disabled cause of missing patterns.
// You can detect if it is disabled by checking if the `KeyBindChangedCallback` got called on startup.
extern "C" UNOFFICIAL_EXTRAS_API KeyBinds::Key get_key(KeyBinds::KeyControl pControl, uint32_t pKeyIndex = 0);
extern "C" UNOFFICIAL_EXTRAS_API KeyBinds::KeyBind get_key_bind(KeyBinds::KeyControl pControl);

/**
 * Magic_enum includes and definitions.
 * This is completely optional, you don't need any of it.
 */
#if __has_include("magic_enum.hpp")
#include "magic_enum.hpp"
#elif __has_include("magic_enum/magic_enum.hpp")
#include "magic_enum/magic_enum.hpp"
#endif

#ifdef MAGIC_ENUM_SUPPORTED
static_assert(KeyBinds::KEY_CONTROL_SIZE == magic_enum::enum_count<KeyBinds::KeyControl>());
static_assert(KeyBinds::KEY_CODES_SIZE == magic_enum::enum_count<KeyBinds::KeyCode>());
static_assert(KeyBinds::MOUSE_CODES_SIZE == magic_enum::enum_count<KeyBinds::MouseCode>());
static_assert(KeyBinds::DEVICE_TYPE_SIZE == magic_enum::enum_count<KeyBinds::DeviceType>());
static_assert(KeyBinds::KEY_CODES_SIZE == magic_enum::enum_count<KeyBinds::KeyCode>());

template <>
struct magic_enum::customize::enum_range<KeyBinds::Modifier_> {
  static constexpr bool is_flags = true;
};
#endif
