# nsmb2-headers
Partial documentation of New Super Mario Bros. 2 headers, stripped from SMBNext.

These headers provide the bare minimum (and then some) required to create and add custom actors (objects & enemies) to the game. As the code was hastily separated from the [Super Mario Bros. Next](https://smbnext.net/) project, it is very messy and incomplete.

Some helper code from the SMBNext codebase (not part of the original game) is also provided for the sake of convenience. These include functions for updating model matrices, as well as various interpolation functions.

# ⚠️ Absolutely NO support or updates will be provided for these headers. They are provided AS-IS. ⚠️
Once SMBNext is released, this repository will be archived and users will be encouraged to move to using the SMBNext codebase to develop their projects.


# Basic usage
All headers you need for your custom code are in the `include` subdirectory, which you are highly recommended to browse through first.

Custom enemies and objects should be placed in the `source/enemy` and `source/mapobj` folders, respectively.

VS Code snippets (in `.vscode`) are included as a way to easily get started with some templates; open the project in VS Code and simply type `Actor`, `ActorCollision`, or `Enemy` to begin. Snippets to easily create non-animated models (`ModelCreate`) and state functions (`State`) are also provided for conveience.

# Adding profiles & sprites to the game
All actors in the game have an associated profile, and some profiles also have a sprite table entry, which is necessary to be able to place the sprite in a level editor.

In order to fully add a custom actor to the game, a matching entry must be added to both the profile table (in `include/course/ProfileId.h`) and the course sprite table (in `source/course/CourseSpriteMgr.cpp`).

A **RegisterStageProfile** global object must also be correctly specified within the source file for your custom object. This is already included in the snippet templates.


# Compiling

⚠️ **NOTE**: Compiling at the moment only works on Linux/[WSL](https://learn.microsoft.com/en-us/windows/wsl/install) (and maybe macOS). ⚠️

⚠️ **NOTE**: If using WSL, ensure you perform the following actions **inside your WSL home directory (`~/`)** to prevent case sensitivity issues. Avoid working in `/mnt/c/` or other mounted Windows drives, as NTFS is case-insensitive by default and may cause build errors. ⚠️

The symbol table will also only work with the USA Gold Edition of New Super Mario Bros. 2.

Make sure the checksums of your dumped files match with the below checksums:
| File | #MD5    | #SHA1    |
| :---:   | :---: | :---: |
| code.bin | `bff3eaf503b16b9b3d3c98a4494d1149`   | `dec76696e3cd7ccdd29a637d51d255517a4daf1d`   |
| exheader.bin | `ee62b6025525d0da21093ff611e3161b`   | `344aab8c1f71f5b58b1a3607470756d0d58a337e`   |

1) Compile (or download) [Magikoopa](https://github.com/RicBent/Magikoopa).
2) Clone this repository.
3) Download a standalone version of the [GNU Arm Embedded Toolchain](https://developer.arm.com/downloads/-/gnu-rm), and unzip it inside this repository. You should have a `gcc-arm-none-eabi` folder next to the `source`, `loader`, etc. folders.
4) Copy your game's `code.bin` and `exheader.bin` into this directory as well.
5) Open Magikoopa, and set the working directory to the respository folder (containing your `code.bin`).
6) Press "Make and Insert". Your code files will now be patched, and a backup of the originals will be kept in `bak`.

# Loading custom code in-game

Place the patched `code.bin` and `exheader.bin` files in the game's mods directory for Citra/Azahar, or under `luma/titles/<TitleID>` for Luma3DS. Replace `<TitleID>` with the correct one from the table below:

```
NSMB2 Standard Edition:
EUR - 000400000007AF00
USA - 000400000007AE00
JPN - 000400000007AD00
KOR - 00040000000B8900

NSMB2 Gold Edition:
USA - 0004000000137E00

NSMB2 Special Edition:
EUR - 0004000000137F00
JPN - 0000400000137D00
```
