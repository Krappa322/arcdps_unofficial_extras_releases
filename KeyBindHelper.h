#pragma once

#include "KeyBindStructs.h"

#include <intsafe.h>
#include <optional>

namespace KeyBinds {
	std::optional<KeyBinds::KeyCode> MsvcScanCodeToKeyCode(const UINT pScanCode);

UINT KeyCodeToMsvcScanCode(const KeyBinds::KeyCode& pScanCode);
}
