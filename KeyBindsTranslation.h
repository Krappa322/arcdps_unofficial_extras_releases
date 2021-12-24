#pragma once

#include "Definitions.h"
#include "KeyBindStructs.h"

#include <string>
#include <Windows.h>

std::string to_string(KeyBinds::KeyControl keyControl, Language lang);

/**
 * \brief Converts a keyBind to a string. It will have the same design as the one in GW2.
 * \param keyBind keyBind to convert.
 * \param lang The language used to as translation. If you provide Chinese as translation, the string is always empty.
 * \param keyboardLayout The current keyboard layout used (is read from windows)
 * \param notSetText `true` if a text should be added, when the key is not set.
 * \return The String for this keyBind.
 */
std::string to_string(KeyBinds::Key keyBind, Language lang, HKL keyboardLayout, bool notSetText = false);
std::string to_string(KeyBinds::KeyCode keyCode, Language lang, HKL keyboardLayout);
std::string to_string(KeyBinds::MouseCode mouseCode, Language lang);
