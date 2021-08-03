#https://cmake.org/cmake/help/latest/manual/cmake-toolchains.7.html#cross-compiling-for-ios-tvos-or-watchos
#rm ./* && cmake .. -G "Xcode" -DCMAKE_SYSTEM_NAME=iOS && open 3d4.xcodeproj/
#
cmake_minimum_required(VERSION 3.17)
project(mhslg_map VERSION 1.0 LANGUAGES C CXX)
list(APPEND CMAKE_MODULE_PATH
        "${CMAKE_SOURCE_DIR}/cmake/macros")
include(AutoCollect)
enable_language(C)
#SET(CMAKE_C_FLAGS "-Wall -std=c99")

set(USE_GCC OFF)
set(SDL 0)
set(GLFW 0)
set(IOS 0)
set(ASSIMP 0)
set(IMGUI 0)
set(GLAD 0)
add_definitions(-D_AFXDLL)
set(CMAKE_MFC_FLAG 1)



# set(LIBS ${LIBS} gravityapi_s)
#add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/general/GameNetworkingSockets-1.3.0/)
#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/general/GameNetworkingSockets-1.3.0/include/)
#set(LIBS ${LIBS} GameNetworkingSockets_s)

if(VULKAN)
find_package(Vulkan)
if (DEFINED ENV{VULKAN_SDK})
    message(STATUS "Vulkan environment variable: $ENV{VULKAN_SDK}")
    set(VULKAN_INCLUDE "$ENV{VULKAN_SDK}/include")
else ()
    message(STATUS "Vulkan environment variable: undefined")
    set(VULKAN_INCLUDE "")
endif ()
endif()


IF(ASSIMP)
set(ASSIMP_STATIC 0)
IF (0)
    if (WIN32 AND MINGW)
        set(ASSIMP_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/mingw64/assimp)
    ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Linux")
        set(ASSIMP_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/linux/assimp)
    ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Darwin")
        set(ASSIMP_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/bsd/assimp)
    endif ()

    set(ASSIMP_LIBRARY "assimp" "IrrXML" "z")

    #set(ASSIMP_LIBRARY "assimp" "IrrXML" "zlibstatic")
    set(ASSIMP_LIBRARY_DIRS ${ASSIMP_PREFIX}/lib)
    set(ASSIMP_INCLUDE_DIRS ${ASSIMP_PREFIX}/include)
    link_directories(${ASSIMP_LIBRARY_DIRS})
    INCLUDE_DIRECTORIES(${ASSIMP_INCLUDE_DIRS})
    set(LIBS ${LIBS} ${ASSIMP_LIBRARY})
ELSEIF (NOT IOS)
#https://github.com/assimp/assimp/blob/master/Build.md
#BUILD_SHARED_LIBS ( default ON ): Generation of shared libs ( dll for windows, so for Linux ). Set this to OFF to get a static lib.
#BUILD_FRAMEWORK ( default OFF, MacOnly): Build package as Mac OS X Framework bundle
#ASSIMP_DOUBLE_PRECISION( default OFF ): All data will be stored as double values.
#ASSIMP_OPT_BUILD_PACKAGES ( default OFF): Set to ON to generate CPack configuration files and packaging targets
#ASSIMP_ANDROID_JNIIOSYSTEM ( default OFF ): Android JNI IOSystem support is active
#ASSIMP_NO_EXPORT ( default OFF ): Disable Assimp's export functionality
#ASSIMP_BUILD_ZLIB ( default OFF ): Build your own zlib
#ASSIMP_BUILD_ASSIMP_TOOLS ( default ON ): If the supplementary tools for Assimp are built in addition to the library.
#ASSIMP_BUILD_SAMPLES ( default OFF ): If the official samples are built as well (needs Glut).
#ASSIMP_BUILD_TESTS ( default ON ): If the test suite for Assimp is built in addition to the library.
#ASSIMP_COVERALLS ( default OFF ): Enable this to measure test coverage.
#ASSIMP_ERROR_MAX( default OFF): Enable all warnings.
#ASSIMP_WERROR( default OFF ): Treat warnings as errors.
#ASSIMP_ASAN ( default OFF ): Enable AddressSanitizer.
#ASSIMP_UBSAN ( default OFF ): Enable Undefined Behavior sanitizer.
#SYSTEM_IRRXML ( default OFF ): Use system installed Irrlicht/IrrXML library.
#BUILD_DOCS ( default OFF ): Build documentation using Doxygen.
#INJECT_DEBUG_POSTFIX( default ON ): Inject debug postfix in .a/.so lib names
#IGNORE_GIT_HASH ( default OFF ): Don't call git to get the hash.
#ASSIMP_INSTALL_PDB ( default ON ): Install MSVC debug files.

#    option(ASSIMP_NO_EXPORT OFF)
    option(BUILD_SHARED_LIBS OFF)
    option(ASSIMP_BUILD_ASSIMP_TOOLS OFF)
    option(ASSIMP_BUILD_SAMPLES OFF)
    option(ASSIMP_BUILD_TESTS OFF)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/general/assimp-5.0.1)
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/general/assimp-5.0.1/include)
    set(LIBS ${LIBS} assimp::assimp)
ENDIF ()
ENDIF()


# cd build
# cmake .. -G "MinGW Makefiles" -DCMAKE_SH="CMAKE_SH-NOTFOUND" -DCMAKE_CXX_FLAGS="-static"
PickIncludeDirectories(
        ${CMAKE_CURRENT_SOURCE_DIR}/code
        INCLUDEDIRS
        # Exclude
        ${CMAKE_CURRENT_SOURCE_DIR}/build
        ${CMAKE_CURRENT_SOURCE_DIR}/code/StartPoint
)

PickSourceFiles(
        ${CMAKE_CURRENT_SOURCE_DIR}/code
        CODEFILES
        # Exclude
        ${CMAKE_CURRENT_SOURCE_DIR}/build
        ${CMAKE_CURRENT_SOURCE_DIR}/code/StartPoint
)


MakeFilter(
        ${CMAKE_CURRENT_SOURCE_DIR}/code)



add_library(${CMAKE_PROJECT_NAME} SHARED ${CODEFILES} ${CMAKE_CURRENT_SOURCE_DIR}/code/StartPoint/dll.cpp)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/general/gravity-0.8.5/src)
set(LIBS ${LIBS} gravityapi_s)


set(INCLUDEDIRS ${INCLUDEDIRS} ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/raylib/include/)
set(LIBDIRS ${LIBDIRS} ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/raylib/lib/)
set(LIBS ${LIBS} Winmm raylib.lib)


set(INCLUDEDIRS ${INCLUDEDIRS} ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/erl/include/)
set(LIBDIRS ${LIBDIRS} ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/erl/lib/)
set(LIBS ${LIBS} erts_MD.lib)


target_link_directories(${CMAKE_PROJECT_NAME} PUBLIC ${LIBDIRS})
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${INCLUDEDIRS}${GRAVITY_INCLUDE_DIR})


add_executable(${CMAKE_PROJECT_NAME}EXE  ${CODEFILES} ${CMAKE_CURRENT_SOURCE_DIR}/code/StartPoint/main.cpp)
target_include_directories(${CMAKE_PROJECT_NAME}EXE PUBLIC ${INCLUDEDIRS}${GRAVITY_INCLUDE_DIR})
target_link_directories(${CMAKE_PROJECT_NAME}EXE PUBLIC ${LIBDIRS})

IF (CMAKE_SYSTEM_NAME MATCHES "Windows") #target_link_libraries(MyExec PUBLIC "-static")
    IF (USE_GCC)
        set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")
        set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O")
        target_link_libraries(${CMAKE_PROJECT_NAME}
                 ${LIBS})

    ELSE ()

        set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}  /MT")
        set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}  /MTd")
        set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE}  /MT")
        set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG}  /MTd")
        target_link_libraries(${CMAKE_PROJECT_NAME}
                ${LIBS})
        target_link_libraries(${CMAKE_PROJECT_NAME}EXE
                ${LIBS})
    ENDIF ()
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Linux")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

    target_link_libraries(${CMAKE_PROJECT_NAME}  pthread
            wren fmt
            )
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Darwin")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
    target_link_libraries(${CMAKE_PROJECT_NAME}
            pthread
            ${LIBS}
            )
    MESSAGE("MACOS")
ELSEIF (IOS)
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
    set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -DGLES_SILENCE_DEPRECATION)
    target_link_libraries(${CMAKE_PROJECT_NAME}
            pthread
            ${LIBS}
            )
    #    set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake/ios")
    #    add_executable(${CMAKE_PROJECT_NAME} MACOSX_BUNDLE main.cpp)
    #        -Wl,-framework,AudioToolbox
    #        -Wl,-framework,AVFoundation
    #        -Wl,-framework,CoreAudio
    #        -Wl,-framework,CoreBluetooth
    #        -Wl,-framework,CoreGraphics
    #        -Wl,-framework,CoreMotion
    #        -Wl,-framework,Foundation
    #        -Wl,-framework,GameController
    #        -Wl,-framework,Metal
    #        -Wl,-framework,OpenGLES
    #        -Wl,-framework,QuartzCore
    #        -Wl,-framework,UIKit
    set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES
            XCODE_ATTRIBUTE_OTHER_LDFLAGS "${XCODE_ATTRIBUTE_OTHER_LDFLAGS}
            -framework AudioToolbox
-framework AudioToolbox
-framework AVFoundation
-framework CoreAudio
-framework CoreBluetooth
-framework CoreGraphics
-framework CoreMotion
-framework Foundation
-framework CoreFoundation
-framework GameController
-framework Metal
-framework OpenGLES
-framework QuartzCore
-framework UIKit

")



    set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES
            MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/cmake/ios/MacOSXBundleInfo.plist.in
            MACOSX_BUNDLE ON
            MACOSX_BUNDLE_BUNDLE_NAME ${CMAKE_PROJECT_NAME}
            MACOSX_BUNDLE_GUI_IDENTIFIER com.myname.${CMAKE_PROJECT_NAME}
            MACOSX_FRAMEWORK_IDENTIFIER com.myname.${CMAKE_PROJECT_NAME}
            MACOSX_BUNDLE_BUNDLE_IDENTIFIER com.myname.${CMAKE_PROJECT_NAME}
            MACOSX_BUNDLE_SHORT_VERSION_STRING "123"
            MACOSX_BUNDLE_LONG_VERSION_STRING "456"
            MACOSX_BUNDLE_BUNDLE_VERSION "123"
            RESOURCE "${RES2}"
            #MACOSX_BUNDLE_ICON_FILE glfw.icns
            )
    MESSAGE("IOS")
ENDIF ()



if (EMSCRIPTEN)
    set(CMAKE_EXECUTABLE_SUFFIX ".html")
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -DIMGUI_IMPL_OPENGL_ES3")
    set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES LINK_FLAGS
            "-s ASYNCIFY=1 -s USE_SDL=2  -s MAX_WEBGL_VERSION=2 -s ALLOW_MEMORY_GROWTH=1 --preload-file data.0 -O3 --closure 1 ")
   
            # -s ERROR_ON_UNDEFINED_SYMBOLS=0  -s USE_GLFW=3 -s USE_SDL=2 -s FULL_ES3=1 -s FULL_ES2=1 -s USE_WEBGL2=1  --preload-file data.0 --shell-file shell_minimal.html -s MIN_WEBGL_VERSION=2 -s MAX_WEBGL_VERSION=2
endif()