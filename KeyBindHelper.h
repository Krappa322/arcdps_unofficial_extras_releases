#pragma once

#include "KeyBindStructs.h"

#include <intsafe.h>

#if __cplusplus == 199711L
__pragma(message (__FILE__ "(" _CRT_STRINGIZE(__LINE__) "): warning: " "incompatible with C++99 or missing option /Zc:__cplusplus, https://learn.microsoft.com/en-us/cpp/build/reference/zc-cplusplus"))
#endif

#if __cplusplus >= 201703L
#include <optional>
#endif

namespace KeyBinds {
#if __cplusplus >= 201703L
	std::optional<KeyBinds::KeyCode> MsvcScanCodeToKeyCode(const UINT pScanCode);
#endif

	UINT KeyCodeToMsvcScanCode(const KeyBinds::KeyCode& pScanCode);
}
