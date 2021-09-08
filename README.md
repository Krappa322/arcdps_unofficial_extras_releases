# ArcDPS Unofficial Extras
Provides arcdps addons with additional information arcdps does not provide, namely:
- When players leave or join the party/squad
- What role a player has in the squad
- What subgroup a player is in
- If the player is ready or not (in a squad ready check)

## Disclaimer
**arcdps_unofficial_extras is not affiliated with or endorsed by deltaconnected or arcdps**

**arcdps_unofficial_extras is not affiliated with or endorsed by Arenanet, NCSoft or Guild Wars 2**

**This addon, like arcdps, hooks network data. To do so it makes runtime modifications to the GW2 executable.**

**Use at your own risk.**

## Installation
Requires [ArcDPS](https://www.deltaconnected.com/arcdps/).

Download the latest [arcdps_unofficial_extras.dll](https://github.com/Krappa322/arcdps_unofficial_extras_releases/releases/latest) from the Releases page. Drag and drop arcdps_unofficial_extras.dll into the bin64\ directory (same directory as where arcdps d3d9.dll is)

## Usage
Currently no additional info is provided by the addon itself when it's working. Check addons that integrate with unofficial_extras to know if it's functioning as expected.

## Source Code
unofficial_extras is currently closed source. This in compliance with requests made by Guild Wars 2 community managers, who have requested for similar addons (that read runtime data from the GW2 executable) to be closed source.

## Issues and requests
Please report issues and requests using the github issue tracker, or on the [Elite Insights Discord](https://discord.gg/RaZ5myp)

## For Developers
Check out the Definitions.h header file included in every release, it should contain all the information needed in order to integrate your addon with unofficial_extras.

## Copyright
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
