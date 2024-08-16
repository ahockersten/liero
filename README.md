# Liero (orbmit edition)

This is the fork of Liero made by and for the community of Liero players in
Göteborg. Compared to Liero 1.36 it contains:
- an upgrade to SDL 2
- borderless window fullscreen
- single screen replay. Views the full map in replays
- spectator window. View the full map in a separate window for spectators or streaming
- updated video replay processing
- ability to view spawn point when dead (off by default)
- fix for occasional stuttering
- dualstick controls (see below for instructions) (off by default)

Due to being forked from an unreleased improved version of Liero 1.36, it also
contains the following changes:
- AI improvements
- menu reorganization
- new game mode "Scales of Justice"
- massively improved total conversion support
- various other changes

## Dualstick controls
Liero was built in a time before dualstick joysticks were invented (and when playing on keyboards was still the norm).
As a consequence, it has a control scheme that is old school. As an experiment, I tried adding dualstick controls for
modern joypads. Of course, being able to aim in any direction immediately makes this into a very different game.

To use dualstick controls, go to the "options" menu and set "dualstick controls" to "on". Then, go into the player
setup menus and make sure to setup "Aim L/R" and "Aim U/D" appropriately.

Note that currently if one player has dualstick controls, then the second player is forced to use dualstick controls as well.

## How to build (Windows)

### Building on Windows
* Install Visual Studio 2022
* Install SDL 2
  * Go to https://github.com/libsdl-org/SDL/releases
  * Download e.g. SDL2-devel-2.26.1-VC.zip
  * Extract the contents to somewhere on your file system
  * Set the SDL2_DIR environment variable to the directory you extracted the files to
* Install SDL2_image
  * Go to https://github.com/libsdl-org/SDL_image/releases
  * Download e.g. SDL2_image-devel-2.6.2-VC.zip
  * Extract the contents to somewhere on your file system
  * Set the SDL2_image_DIR environment variable to the directory you extracted the files to
* Copy everything from the pkg directory to the same folder as openliero.exe ends up in, e.g. `out\build\x64-Debug` or `out\build\x64-Release`
* Download SDL 2
  * Go to https://github.com/libsdl-org/SDL/releases
  * Download e.g. SDL2-2.26.1-win32-x64.zip
  * Put SDL2.dll either in your system32 folder or in the same folder as openliero.exe ends up in, e.g. `out\build\x64-Debug` or `out\build\x64-Release`
* Download SDL2_image
  * Go to https://github.com/libsdl-org/SDL_image/releases
  * Download e.g. SDL2_image-2.6.2-win32-x64.zip
  * Put SDL2_image.dll either in your system32 folder or in the same folder as openliero.exe ends up in, e.g. `out\build\x64-Debug` or `out\build\x64-Release`
* Copy everything from the pkg directory to the same folder as openliero.exe ends up in, e.g. `out\build\x64-Debug` or `out\build\x64-Release`

### (Optional) Dependencies for building the video tool
* Follow the instructions for installing dependencies needed to build ffmpeg. At the time of writing, the MSYS2 route worked best for me https://trac.ffmpeg.org/wiki/CompilationGuide/MinGW
* Download latest libx264: git clone git://git.videolan.org/x264.git
* Build it: cd x264; ./configure --enable-shared --enable-pic && make -j8
* Download latest ffmpeg: git clone git://source.ffmpeg.org/ffmpeg.git ffmpeg
* Build it: cd ffmpeg; ./configure --enable-shared --enable-pic --enable-gpl --enable-libx264 --disable-programs --extra-ldflags=-L../x264 --extra-cflags=-I../x264 && make -j8

## How to build (Linux and Mac)

### Building on Linux and Mac
* Make sure you have CMake, SDL2, SDL2_image and gcc installed
* Run cmake:
* $ cmake -G "Unix Makefiles"
* Run "make"
* Copy everything from the pkg directory to the root directory used for the build

### (Optional) Enabling and building the video tool
* Download latest libx264: git clone git://git.videolan.org/x264.git
* Build it: cd x264; ./configure --enable-shared --enable-pic && make -j8
* Download latest ffmpeg: git clone git://source.ffmpeg.org/ffmpeg.git ffmpeg
* Build it: cd ffmpeg; ./configure --enable-shared --enable-pic --enable-gpl --enable-libx264 --disable-programs --extra-ldflags=-L../x264 --extra-cflags=-I../x264 --extra-libs=-ldl && make -j8
* Run: make -j8 videotool

### Building a release build
* Run cmake:
* $ cmake -DCMAKE_BUILD_TYPE=Release -G "Unix Makefiles"
* Run "make"

Extracting game data for total conversions
======================

For copyright reasons, this repository does not contain the original Liero sound
files. Included instead is the original ruleset together with the lierolibre
sound effects.

In order to use the original data, or any total conversion, you need to run
the tctool on the game data. Example on how to do this is included below:

Windows
---------------------
```powershell
Invoke-WebRequest https://www.liero.be/download/liero-1.36-bundle.zip -OutFile liero-1.36-bundle.zip
Expand-Archive -LiteralPath .\liero-1.36-bundle.zip .
.\out/build/x64-Release/tctool.exe liero-1.36-bundle
Move-Item .\TC\liero-1.36-bundle .\TC\"Liero v1.33"
Remove-Item .\liero-1.36-bundle.zip
Remove-Item -Recurse .\liero-1.36-bundle
Copy-Item -Recurse .\TC .\out\build\x64-Debug
Copy-Item -Recurse .\TC .\out\build\x64-Release
```

Linux/Mac
---------------------
```bash
curl https://www.liero.be/download/liero-1.36-bundle.zip -O
unzip liero-1.36-bundle.zip
./tctool liero-1.36-bundle
mv TC/liero-1.36-bundle TC/"Liero v1.33"
rm liero-1.36-bundle.zip
rm -rf liero-1.36-bundle
```
