# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/clion-2018.3.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2018.3.3/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/meynadier/ProjectImg/code

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/meynadier/ProjectImg/code/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CodeBarres.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CodeBarres.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CodeBarres.dir/flags.make

CMakeFiles/CodeBarres.dir/main.cpp.o: CMakeFiles/CodeBarres.dir/flags.make
CMakeFiles/CodeBarres.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/meynadier/ProjectImg/code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CodeBarres.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CodeBarres.dir/main.cpp.o -c /home/meynadier/ProjectImg/code/main.cpp

CMakeFiles/CodeBarres.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CodeBarres.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/meynadier/ProjectImg/code/main.cpp > CMakeFiles/CodeBarres.dir/main.cpp.i

CMakeFiles/CodeBarres.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CodeBarres.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/meynadier/ProjectImg/code/main.cpp -o CMakeFiles/CodeBarres.dir/main.cpp.s

CMakeFiles/CodeBarres.dir/PreProcess.cpp.o: CMakeFiles/CodeBarres.dir/flags.make
CMakeFiles/CodeBarres.dir/PreProcess.cpp.o: ../PreProcess.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/meynadier/ProjectImg/code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CodeBarres.dir/PreProcess.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CodeBarres.dir/PreProcess.cpp.o -c /home/meynadier/ProjectImg/code/PreProcess.cpp

CMakeFiles/CodeBarres.dir/PreProcess.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CodeBarres.dir/PreProcess.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/meynadier/ProjectImg/code/PreProcess.cpp > CMakeFiles/CodeBarres.dir/PreProcess.cpp.i

CMakeFiles/CodeBarres.dir/PreProcess.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CodeBarres.dir/PreProcess.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/meynadier/ProjectImg/code/PreProcess.cpp -o CMakeFiles/CodeBarres.dir/PreProcess.cpp.s

CMakeFiles/CodeBarres.dir/test/TestPreProcess.cpp.o: CMakeFiles/CodeBarres.dir/flags.make
CMakeFiles/CodeBarres.dir/test/TestPreProcess.cpp.o: ../test/TestPreProcess.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/meynadier/ProjectImg/code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/CodeBarres.dir/test/TestPreProcess.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CodeBarres.dir/test/TestPreProcess.cpp.o -c /home/meynadier/ProjectImg/code/test/TestPreProcess.cpp

CMakeFiles/CodeBarres.dir/test/TestPreProcess.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CodeBarres.dir/test/TestPreProcess.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/meynadier/ProjectImg/code/test/TestPreProcess.cpp > CMakeFiles/CodeBarres.dir/test/TestPreProcess.cpp.i

CMakeFiles/CodeBarres.dir/test/TestPreProcess.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CodeBarres.dir/test/TestPreProcess.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/meynadier/ProjectImg/code/test/TestPreProcess.cpp -o CMakeFiles/CodeBarres.dir/test/TestPreProcess.cpp.s

CMakeFiles/CodeBarres.dir/Process.cpp.o: CMakeFiles/CodeBarres.dir/flags.make
CMakeFiles/CodeBarres.dir/Process.cpp.o: ../Process.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/meynadier/ProjectImg/code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/CodeBarres.dir/Process.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CodeBarres.dir/Process.cpp.o -c /home/meynadier/ProjectImg/code/Process.cpp

CMakeFiles/CodeBarres.dir/Process.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CodeBarres.dir/Process.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/meynadier/ProjectImg/code/Process.cpp > CMakeFiles/CodeBarres.dir/Process.cpp.i

CMakeFiles/CodeBarres.dir/Process.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CodeBarres.dir/Process.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/meynadier/ProjectImg/code/Process.cpp -o CMakeFiles/CodeBarres.dir/Process.cpp.s

# Object files for target CodeBarres
CodeBarres_OBJECTS = \
"CMakeFiles/CodeBarres.dir/main.cpp.o" \
"CMakeFiles/CodeBarres.dir/PreProcess.cpp.o" \
"CMakeFiles/CodeBarres.dir/test/TestPreProcess.cpp.o" \
"CMakeFiles/CodeBarres.dir/Process.cpp.o"

# External object files for target CodeBarres
CodeBarres_EXTERNAL_OBJECTS =

CodeBarres: CMakeFiles/CodeBarres.dir/main.cpp.o
CodeBarres: CMakeFiles/CodeBarres.dir/PreProcess.cpp.o
CodeBarres: CMakeFiles/CodeBarres.dir/test/TestPreProcess.cpp.o
CodeBarres: CMakeFiles/CodeBarres.dir/Process.cpp.o
CodeBarres: CMakeFiles/CodeBarres.dir/build.make
CodeBarres: /usr/local/lib/libopencv_dnn.so.4.0.1
CodeBarres: /usr/local/lib/libopencv_gapi.so.4.0.1
CodeBarres: /usr/local/lib/libopencv_ml.so.4.0.1
CodeBarres: /usr/local/lib/libopencv_objdetect.so.4.0.1
CodeBarres: /usr/local/lib/libopencv_photo.so.4.0.1
CodeBarres: /usr/local/lib/libopencv_stitching.so.4.0.1
CodeBarres: /usr/local/lib/libopencv_video.so.4.0.1
CodeBarres: /usr/local/lib/libopencv_calib3d.so.4.0.1
CodeBarres: /usr/local/lib/libopencv_features2d.so.4.0.1
CodeBarres: /usr/local/lib/libopencv_flann.so.4.0.1
CodeBarres: /usr/local/lib/libopencv_highgui.so.4.0.1
CodeBarres: /usr/local/lib/libopencv_videoio.so.4.0.1
CodeBarres: /usr/local/lib/libopencv_imgcodecs.so.4.0.1
CodeBarres: /usr/local/lib/libopencv_imgproc.so.4.0.1
CodeBarres: /usr/local/lib/libopencv_core.so.4.0.1
CodeBarres: CMakeFiles/CodeBarres.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/meynadier/ProjectImg/code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable CodeBarres"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CodeBarres.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CodeBarres.dir/build: CodeBarres

.PHONY : CMakeFiles/CodeBarres.dir/build

CMakeFiles/CodeBarres.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CodeBarres.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CodeBarres.dir/clean

CMakeFiles/CodeBarres.dir/depend:
	cd /home/meynadier/ProjectImg/code/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/meynadier/ProjectImg/code /home/meynadier/ProjectImg/code /home/meynadier/ProjectImg/code/cmake-build-debug /home/meynadier/ProjectImg/code/cmake-build-debug /home/meynadier/ProjectImg/code/cmake-build-debug/CMakeFiles/CodeBarres.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CodeBarres.dir/depend

