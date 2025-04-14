#pragma once

#include "KeyBindStructs.h"

#include <intsafe.h>

#if __cplusplus >= 201703L
#include <optional>
#endif

namespace KeyBinds {
#if __cplusplus >= 201703L
	std::optional<KeyBinds::KeyCode> MsvcScanCodeToKeyCode(const UINT pScanCode);
#endif

	UINT KeyCodeToMsvcScanCode(const KeyBinds::KeyCode& pScanCode);
}
