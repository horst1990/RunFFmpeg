# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# configure import libs
set(ffmpeg_DIR ${CMAKE_SOURCE_DIR}/distribution/ffmpeg)

# build application's shared lib
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

add_library(avfilter-lib STATIC IMPORTED)
set_target_properties(avfilter-lib PROPERTIES IMPORTED_LOCATION ${ffmpeg_DIR}/lib/${ANDROID_ABI}/libavfilter.a)

add_library(avformat-lib STATIC IMPORTED)
set_target_properties(avformat-lib PROPERTIES IMPORTED_LOCATION ${ffmpeg_DIR}/lib/${ANDROID_ABI}/libavformat.a)

add_library(avcodec-lib STATIC IMPORTED)
set_target_properties(avcodec-lib PROPERTIES IMPORTED_LOCATION ${ffmpeg_DIR}/lib/${ANDROID_ABI}/libavcodec.a)

add_library(swresample-lib STATIC IMPORTED)
set_target_properties(swresample-lib PROPERTIES IMPORTED_LOCATION ${ffmpeg_DIR}/lib/${ANDROID_ABI}/libswresample.a)

add_library(swscale-lib STATIC IMPORTED)
set_target_properties(swscale-lib PROPERTIES IMPORTED_LOCATION ${ffmpeg_DIR}/lib/${ANDROID_ABI}/libswscale.a)

add_library(avutil-lib STATIC IMPORTED)
set_target_properties(avutil-lib PROPERTIES IMPORTED_LOCATION ${ffmpeg_DIR}/lib/${ANDROID_ABI}/libavutil.a)

include_directories(${ffmpeg_DIR}/include)

add_library(
             native-lib
             SHARED
             src/main/cpp/native-lib.cpp
             src/main/cpp/zyj-lib.cpp
             )

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.
find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
                       native-lib

                       avfilter-lib
                       avformat-lib
                       avcodec-lib
                       swresample-lib
                       swscale-lib
                       avutil-lib

                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )