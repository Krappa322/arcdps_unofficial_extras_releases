#pragma once

#include "Definitions.h"
#include "KeyBindStructs.h"
#include "KeyBindHelper.h"

#include <string>
#include <Windows.h>

std::string to_string(KeyBinds::KeyControl pKeyControl, Language pLang);

/**
 * \brief Converts a keyBind to a string. It will have the same design as the one in GW2.
 * \param pKeyBind keyBind to convert.
 * \param pLang The language used to as translation. If you provide Chinese as translation, the string is always empty.
 * \param pKeyboardLayout The current keyboard layout used (is read from windows)
 * \param pNotSetText `true` if a text should be added, when the key is not set.
 * \return The String for this keyBind.
 */
std::string to_string(KeyBinds::Key pKeyBind, Language pLang, HKL pKeyboardLayout, bool pNotSetText = false);
std::string to_string(KeyBinds::KeyCode pKeyCode, Language pLang, HKL pKeyboardLayout);
std::string to_string(KeyBinds::MouseCode pMouseCode, Language pLang);
std::string to_string_unbind(Language pLang);
