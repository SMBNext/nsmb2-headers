# nsmb2-headers
Documentation of New Super Mario Bros. 2 headers, stripped from SMBNext.

These headers provide the interface necessary to create and add custom actors (objects & enemies) to the game, as well as interact with other game functionality. As the code is separated from and updated with the [Super Mario Bros. Next](https://smbnext.net/) project, it is very messy and incomplete.

Some helper code from the SMBNext codebase (not part of the original game) is also provided for the sake of convenience. These include functions for updating model matrices, as well as various interpolation functions.

# ⚠️ Absolutely NO entry-level support will be provided for these headers. They are provided AS-IS. ⚠️
Once SMBNext is released, proper documentation will be written, this repository will most likely be archived, and users will be encouraged to move to using the SMBNext codebase to develop their projects.


# Basic usage
All headers you need for your custom code are in the `include` subdirectory, which you are highly recommended to browse through first.

Custom enemies and objects should be placed in the `source/enemy` and `source/mapobj` folders, respectively.

VS Code snippets (in `.vscode`) are included as a way to easily get started with some templates; open the project in VS Code and simply type `Actor`, `ActorCollision`, or `Enemy` to begin. Snippets to easily create non-animated models (`ModelCreate`) and state functions (`State`) are also provided for conveience.

# Adding profiles & sprites to the game
All actors in the game have an associated profile, and some profiles also have a sprite table entry, which is necessary to be able to place the sprite in a level editor.

In order to fully add a custom actor to the game, a matching entry must be added to both the profile table (in `include/course/ProfileId.h`) and the course sprite table (in `source/course/CourseSpriteMgr.cpp`).

A **RegisterStageProfile** global object must also be correctly specified within the source file for your custom object. This is already included in the snippet templates.


# Compiling

⚠️ **NOTE**: If using WSL, ensure you perform the following actions **inside your WSL home directory (`~/`)** to prevent case sensitivity issues. Avoid working in `/mnt/c/` or other mounted Windows drives, as NTFS is case-insensitive by default and may cause build errors. ⚠️

The symbol table will also only work with the USA Gold Edition of New Super Mario Bros. 2.

Make sure the checksums of your dumped files match with the below checksums:
| File | #MD5    | #SHA1    |
| :---:   | :---: | :---: |
| code.bin | `bff3eaf503b16b9b3d3c98a4494d1149`   | `dec76696e3cd7ccdd29a637d51d255517a4daf1d`   |
| exheader.bin | `ee62b6025525d0da21093ff611e3161b`   | `344aab8c1f71f5b58b1a3607470756d0d58a337e`   |

1) Compile (or download) [magwi](https://github.com/RicBent/magwi).
2) Add magwi to your path.
3) Clone this repository, and if using VS code, set the contents of `.vscode/c_cpp_properties.json` to this, replacing the placeholders in `compilerPath` and `forcedInclude`:
<details>
  <summary>c_cpp_properties.json</summary>
  
```json
  {
      "configurations": [
          {
              "name": "magwi",
              "includePath": [
                  "${workspaceFolder}/include/**"
              ],
              "compilerPath": "<path_to_project>/gcc-arm-none-eabi/bin/arm-none-eabi-gcc",
              "forcedInclude": ["<path_to_magwi>/magwi/resources/include/magwi.h"],
              "defines": ["__mw_symbol_safe_filename=dummy_path"],
              "cStandard": "c11",
              "cppStandard": "c++11",
              "intelliSenseMode": "gcc-arm"
          }
      ],
      "version": 4
  }
```
</details>

and `.vscode/settings.json` to this:
<details>
  <summary>settings.json</summary>

  ```json
{
    "files.exclude": {
        "**/gcc-arm-none-eabi": true,
        "**/.git": true,
        "**/.svn": true,
        "**/.hg": true,
        "**/Thumbs.db": true
    },
    "search.exclude": {
        "**/gcc-arm-none-eabi": true,
    },
    "files.associations": {
        "*.s": "arm",
        "*.tcc": "cpp",
        "exception": "cpp",
        "locale": "cpp",
        "ostream": "cpp",
        "*.inc": "cpp",
        "qtcoredepends": "cpp",
        "qtdbusdepends": "cpp",
        "*.def": "cpp",
        "cmath": "cpp",
        "ios": "cpp",
        "any": "cpp",
        "bit": "cpp",
        "charconv": "cpp",
        "codecvt": "cpp",
        "compare": "cpp",
        "condition_variable": "cpp",
        "cstddef": "cpp",
        "forward_list": "cpp",
        "list": "cpp",
        "string": "cpp",
        "optional": "cpp",
        "rope": "cpp",
        "future": "cpp",
        "limits": "cpp",
        "memory": "cpp",
        "new": "cpp",
        "ranges": "cpp",
        "functional": "cpp",
        "regex": "cpp",
        "numeric": "cpp",
        "type_traits": "cpp",
        "utility": "cpp",
        "complex": "cpp"
    },

    "C_Cpp.default.compilerArgs": [
        "-nostdinc"
    ],
    "workbench.editor.pinnedTabSizing": "compact",
    "C_Cpp.intelliSenseEngine": "disabled",
    "clangd.arguments": [
        "--header-insertion=never"
    ]
}
```
</details>

4) Download a standalone version of the [GNU Arm Embedded Toolchain](https://developer.arm.com/downloads/-/gnu-rm), and unzip it inside this repository. You should have a `gcc-arm-none-eabi` folder next to the `source`, `include`, etc. folders.
5) Copy your game's `code.bin` and `exheader.bin` into a directory named `original` next to the other folders in the project.
6) From within the working directory, run `magwi` and the patcher will output your patched code files to the `build` directory.

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
