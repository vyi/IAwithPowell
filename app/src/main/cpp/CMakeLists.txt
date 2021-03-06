# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

message("-- CHOLMOD_INCLUDE_DIR : " ${CMAKE_CURRENT_SOURCE_DIR})

message(" now including directories ")

add_library(boost SHARED IMPORTED)
set_target_properties( # Specifies the target library.
        boost PROPERTIES IMPORTED_LOCATION
        /home/vivek/Documents/2020/Android_projects/Vision/IAwithPowell/app/src/main/jniLibs/${ANDROID_ABI}/libboost_thread.so )

add_library(g2o SHARED IMPORTED)
set_target_properties(g2o PROPERTIES IMPORTED_LOCATION
        /home/vivek/Documents/2020/Android_projects/Vision/IAwithPowell/app/src/main/jniLibs/${ANDROID_ABI}/libg2o_core.so
        )

add_library(cv SHARED IMPORTED)
set_target_properties(cv PROPERTIES IMPORTED_LOCATION
        /home/vivek/Documents/2020/Android_projects/Vision/IAwithPowell/app/src/main/jniLibs/${ANDROID_ABI}/libopencv_java4.so
        )

include_directories(
        /home/vivek/Documents/2020/Android_projects/Vision/IAwithPowell/app/libs/llvm/include/
#        /home/vivek/Documents/2020/Android_projects/Vision/IAwithPowell/app/libs/llvm/include/boost/
#        /home/vivek/Documents/2020/Android_projects/Vision/IAwithPowell/app/libs/llvm/include/opencv2/
#        /home/vivek/Documents/2020/Android_projects/Vision/IAwithPowell/app/libs/llvm/include/g20/core/
#        ${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/llvm/include/opencv2/
#        ${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/llvm/include/g2o/core/
#        ${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/llvm/include/
)



add_library( # Sets the name of the library.
        native-lib

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        native-lib.cpp)

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log)

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
        native-lib

        # Links the target library to the log library
        ## External libs
        boost
        g2o
        cv
        # included in the NDK.
        ${log-lib})
