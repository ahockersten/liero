Liero (orbmit edition)
========================

This is the fork of Liero made by and for the community of Liero players in
Göteborg. Compared to Liero 1.36 it contains:
- an upgrade to SDL 2
- borderless window fullscreen
- single screen replay. Views the full map in replays
- spectator window. View the full map in a separate window for spectators or streaming
- updated video replay processing
- ability to view spawn point when dead (off by default)
- fix for occasional stuttering

Due to being forked from an unreleased improved version of Liero 1.36, it also
contains the following changes:
- AI improvements
- menu reorganization
- new game mode "Scales of Justice"
- massively improved total conversion support
- various other changes

How to build (Windows)
======================

Building on Windows
-----------------------
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
* Copy everything from the pkg directory to the _build directory
* Download SDL 2
  * Go to https://github.com/libsdl-org/SDL/releases
  * Download e.g. SDL2-2.26.1-win32-x64.zip
  * Put SDL2.dll either in your system32 folder or in the same folder as openliero.exe ends up in, e.g. out\build\x64-Debug
* Download SDL2_image
  * Go to https://github.com/libsdl-org/SDL_image/releases
  * Download e.g. SDL2_image-2.6.2-win32-x64.zip
  * Put SDL2_image.dll either in your system32 folder or in the same folder as openliero.exe ends up in, e.g. out\build\x64-Debug
* Copy everything from the pkg directory to the same folder as openliero.exe ends up in, e.g. out\build\x64-Debug


(Optional) Dependencies for building the video tool
-----------------------
* Follow the instructions for installing dependencies needed to build ffmpeg. At the time of writing, the MSYS2 route worked best for me https://trac.ffmpeg.org/wiki/CompilationGuide/MinGW
* Download latest libx264: git clone git://git.videolan.org/x264.git
* Build it: cd x264; ./configure --enable-shared --enable-pic && make -j8
* Download latest ffmpeg: git clone git://source.ffmpeg.org/ffmpeg.git ffmpeg
* Build it: cd ffmpeg; ./configure --enable-shared --enable-pic --enable-gpl --enable-libx264 --disable-programs --extra-ldflags=-L../x264 --extra-cflags=-I../x264 && make -j8

How to build (Linux and Mac)
============================

Building on Linux and Mac
-------------------------
* Make sure you have CMake, SDL2, SDL2_image and gcc installed
* Run cmake:
* $ cmake -G "Unix Makefiles"
* Run "make"
* Copy everything from the pkg directory to the root directory used for the build

(Optional) Enabling and building the video tool
-------------------------------
* Download latest libx264: git clone git://git.videolan.org/x264.git
* Build it: cd x264; ./configure --enable-shared --enable-pic && make -j8
* Download latest ffmpeg: git clone git://source.ffmpeg.org/ffmpeg.git ffmpeg
* Build it: cd ffmpeg; ./configure --enable-shared --enable-pic --enable-gpl --enable-libx264 --disable-programs --extra-ldflags=-L../x264 --extra-cflags=-I../x264 --extra-libs=-ldl && make -j8
* Run: make -j8 videotool

Building a release build
---------------------
* Run cmake:
* $ cmake -DCMAKE_BUILD_TYPE=Release -G "Unix Makefiles"
* Run "make"
