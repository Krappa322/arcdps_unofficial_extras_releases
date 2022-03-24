#pragma once

#include "KeyBindStructs.h"

#include <intsafe.h>

namespace KeyBinds {
KeyBinds::KeyCode MsvcScanCodeToKeyCode(const UINT pScanCode);

UINT KeyCodeToMsvcScanCode(const KeyBinds::KeyCode& pScanCode);
}
