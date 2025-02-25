# CMake project definition file.
project(libgme)
cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

include (CheckCXXCompilerFlag)
include (CTest)

# When version is changed, also change the one in gme/gme.h to match
set(GME_VERSION 0.7.0 CACHE INTERNAL "libgme Version")

# Default emulators to build (all of them! ;)
if (NOT DEFINED USE_GME_AY)
    SET(USE_GME_AY 1 CACHE BOOL "Enable support for Spectrum ZX music emulation")
endif()

if (NOT DEFINED USE_GME_GBS)
    SET(USE_GME_GBS 1 CACHE BOOL "Enable support for Game Boy music emulation")
endif()

if (NOT DEFINED USE_GME_HES)
    SET(USE_GME_HES 1 CACHE BOOL "Enable PC Engine/TurboGrafx-16 music emulation")
endif()

if (NOT DEFINED USE_GME_KSS)
    SET(USE_GME_KSS 1 CACHE BOOL "Enable MSX or other Z80 systems music emulation")
endif()

if (NOT DEFINED USE_GME_NSF)
    SET(USE_GME_NSF 1 CACHE BOOL "Enable NES NSF music emulation")
endif()

if (NOT DEFINED USE_GME_NSFE)
    SET(USE_GME_NSFE 1 CACHE BOOL "Enable NES NSFE and NSF music emulation")
endif()

if (NOT DEFINED USE_GME_SAP)
    SET(USE_GME_SAP 1 CACHE BOOL "Enable Atari SAP music emulation")
endif()

if (NOT DEFINED USE_GME_SPC)
    SET(USE_GME_SPC 1 CACHE BOOL "Enable SNES SPC music emulation")
endif()

if (NOT DEFINED GME_SPC_ISOLATED_ECHO_BUFFER)
    option(GME_SPC_ISOLATED_ECHO_BUFFER "Enable isolated echo buffer on SPC emulator to allow correct playing of \"dodgy\" SPC files made for various ROM hacks ran on ZSNES" OFF)
endif()

if (USE_GME_NSFE AND NOT USE_GME_NSF)
    MESSAGE(" -- NSFE support requires NSF, enabling NSF support. --")
    SET(USE_GME_NSF 1 CACHE BOOL "Enable NES NSF music emulation" FORCE)
endif()

option(BUILD_SHARED_LIBS "Build shared library (set to OFF for static library)" OFF)

option(ENABLE_UBSAN "Enable Undefined Behavior Sanitizer error-checking" OFF)

option(BUILD_FRAMEWORK "Build framework instead of dylib (on macOS)" OFF)


# static builds need to find static zlib (and static forms of other needed
# libraries.  Ensure CMake looks only for static libs if we're doing a static
# build.  See https://stackoverflow.com/a/44738756
if(NOT BUILD_SHARED_LIBS)
    set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if (MSVC)
    # EDGE: silence no matching operator delete found; memory will not be freed if initialization throws an exception
    add_definitions("/wd4291")
endif()

# Check for GCC/Clang "visibility" support.
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU"
    OR
    CMAKE_CXX_COMPILER_ID STREQUAL "Clang")

    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -W -Wextra")

    # Assume we have visibility support on any compiler that supports C++11
    add_definitions (-DLIBGME_VISIBILITY)
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fvisibility=hidden -fvisibility-inlines-hidden")

    # Try to protect against undefined behavior from signed integer overflow
    # This has caused miscompilation of code already and there are other
    # potential uses; see https://bitbucket.org/mpyne/game-music-emu/issues/18/
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fwrapv")

    if (ENABLE_UBSAN)
        # GCC needs -static-libubsan
        if (NOT BUILD_SHARED_LIBS AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
            set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=undefined -static-libubsan")
        else()
            set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=undefined")
        endif()
    endif()
endif ()

# Shared library defined here
add_subdirectory(gme)