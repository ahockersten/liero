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
============

Building on Windows
-----------------------

* Install Visual Studio 2015
* Download SDL2 for VS (https://www.libsdl.org/download-2.0.php)
* Rename the "include" folder to "SDL2" and copy it here:
C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\include
* Copy *.lib from the "lib\x86" folder to "C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\lib"
* Copy *.lib from the "lib\x64" folder to "C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\lib\amd64"
* Copy "lib\x86\SDL2.dll" to "C:\Windows\SysWOW64"
* Copy "lib\x64\SDL2.dll" to "C:\Windows\System32"
* (optional, for video to replay only) Download latest ffmpeg: git clone git://source.ffmpeg.org/ffmpeg.git ffmpeg

(Optional) Dependencies for building the video tool
-----------------------
* Follow the instructions for how to build ffmpeg. At the time of writing, the MSYS2 route worked best for me https://trac.ffmpeg.org/wiki/CompilationGuide/MinGW
* Download latest libx264: git clone git://git.videolan.org/x264.git
* Build it: cd x264; ./configure --enable-shared --enable-pic && make -j8
* Download latest ffmpeg: git clone git://source.ffmpeg.org/ffmpeg.git ffmpeg
* Build it: cd ffmpeg; ./configure --enable-shared --enable-pic --enable-gpl --enable-libx264 --disable-programs --extra-ldflags=-L../x264 --extra-cflags=-I../x264 && make -j8

How to build (Linux)
====================

Building on Linux
---------------------
* Make sure you have CMake, SDL2 and gcc installed
* Run cmake:
* $ cmake -G "Unix Makefiles"
* Run "make"

(Optional) Enabling and building the video tool
-------------------------------
* Download latest libx264: git clone git://git.videolan.org/x264.git
* Build it: cd x264; ./configure --enable-shared --enable-pic && make -j8
* Download latest ffmpeg: git clone git://source.ffmpeg.org/ffmpeg.git ffmpeg
* Build it: cd ffmpeg; ./configure --enable-shared --enable-pic --enable-gpl --enable-libx264 --disable-programs --extra-ldflags=-L"../x264" --extra-cflags="-I../x264" --extra-libs=-ldl && make -j8
* Run: make -j8 videotool

Building a release build
---------------------
* Run cmake:
* $ cmake -DCMAKE_BUILD_TYPE=Release -G "Unix Makefiles"
* Run "make"
