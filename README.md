# ArcDPS Unofficial Extras
This program does little on its own. It is mainly aimed to provide other plugins with additional information.

What it does directly:
- Lock mouse while camera is moving (hidden when rightclick)
- Lock mouse to the game window
- Presets for graphic settings that allow switching between them fast
- Save/Load Keybinds by Profession (previously part of arcdps)
- Save/Load Keybinds by Elite (previously part of arcdps)

What it provides for other addons:
- Information about the squad (join/leave party/squad, role, subgroup, read-state)
- Event when the language is changed
- Events and exports to read out keybinds
- Utilities to translate keybinds
- Utilities to convert to/from msvc to gw2 internal keybinds
- Events when Chat messages are sent/received

## Disclaimer
**arcdps_unofficial_extras is not affiliated with or endorsed by deltaconnected or arcdps**

**arcdps_unofficial_extras is not affiliated with or endorsed by Arenanet, NCSoft or Guild Wars 2**

**This addon, like arcdps, hooks network data. To do so it makes runtime modifications to the GW2 executable.**

**Use at your own risk.**

## Installation
Requires [ArcDPS](https://www.deltaconnected.com/arcdps/).

Download the latest [arcdps_unofficial_extras.dll](https://github.com/Krappa322/arcdps_unofficial_extras_releases/releases/latest) from the Releases page. Drag and drop arcdps_unofficial_extras.dll into the gw2 directory (same directory as where arcdps d3d11.dll is)

## Usage
If installed correctly, you should see an "Unoffical Extras Options" menu where auto-updating can be configured. Other addons that integrate with unofficial_extras should automatically start working, no additional configuration required. The addon does nothing on its own. 

## Source Code
unofficial_extras is currently closed source. This in compliance with requests made by Guild Wars 2 community managers, who have requested for similar addons (that read runtime data from the GW2 executable) to be closed source.

## Issues and requests
Please report issues and requests using the github issue tracker, or on the [Elite Insights Discord](https://discord.gg/T4kSbKJ5Sf)

## For Developers
Check out the Definitions.h header file included in every release, it should contain all the information needed in order to integrate your addon with unofficial_extras.

## Copyright Notice
This project makes use of the following third party libraries (they are all statically linked):
### arcdps-extension
[arcdps-extension](https://github.com/knoxfighter/arcdps-extension), licensed under the MIT license.
### Dear ImGui
[Dear ImGui](https://github.com/ocornut/imgui), licensed under the MIT license.
### GoogleTest
[GoogleTest](https://github.com/google/googletest), licensed under the BSD-3-Clause license.
### JSON for Modern C++
[JSON for Modern C++](https://github.com/nlohmann/json), licensed under the MIT license.
### spdlog
[spdlog](https://github.com/gabime/spdlog), licensed under the MIT license.
### fmt
[fmt](https://github.com/fmtlib/fmt), licensed under the MIT license.
### magic-enum
[magic-enum](https://github.com/Neargye/magic_enum), licensed under the MIT license.
