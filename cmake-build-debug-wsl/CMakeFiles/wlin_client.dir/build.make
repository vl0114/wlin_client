# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/vl_sys/Desktop/proj/wlin_client

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/vl_sys/Desktop/proj/wlin_client/cmake-build-debug-wsl

# Include any dependencies generated for this target.
include CMakeFiles/wlin_client.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/wlin_client.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/wlin_client.dir/flags.make

CMakeFiles/wlin_client.dir/main.cpp.o: CMakeFiles/wlin_client.dir/flags.make
CMakeFiles/wlin_client.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/vl_sys/Desktop/proj/wlin_client/cmake-build-debug-wsl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/wlin_client.dir/main.cpp.o"
	/usr/bin/clang++-8  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/wlin_client.dir/main.cpp.o -c /mnt/c/Users/vl_sys/Desktop/proj/wlin_client/main.cpp

CMakeFiles/wlin_client.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wlin_client.dir/main.cpp.i"
	/usr/bin/clang++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/vl_sys/Desktop/proj/wlin_client/main.cpp > CMakeFiles/wlin_client.dir/main.cpp.i

CMakeFiles/wlin_client.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wlin_client.dir/main.cpp.s"
	/usr/bin/clang++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/vl_sys/Desktop/proj/wlin_client/main.cpp -o CMakeFiles/wlin_client.dir/main.cpp.s

CMakeFiles/wlin_client.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/wlin_client.dir/main.cpp.o.requires

CMakeFiles/wlin_client.dir/main.cpp.o.provides: CMakeFiles/wlin_client.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/wlin_client.dir/build.make CMakeFiles/wlin_client.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/wlin_client.dir/main.cpp.o.provides

CMakeFiles/wlin_client.dir/main.cpp.o.provides.build: CMakeFiles/wlin_client.dir/main.cpp.o


CMakeFiles/wlin_client.dir/Application.cpp.o: CMakeFiles/wlin_client.dir/flags.make
CMakeFiles/wlin_client.dir/Application.cpp.o: ../Application.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/vl_sys/Desktop/proj/wlin_client/cmake-build-debug-wsl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/wlin_client.dir/Application.cpp.o"
	/usr/bin/clang++-8  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/wlin_client.dir/Application.cpp.o -c /mnt/c/Users/vl_sys/Desktop/proj/wlin_client/Application.cpp

CMakeFiles/wlin_client.dir/Application.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wlin_client.dir/Application.cpp.i"
	/usr/bin/clang++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/vl_sys/Desktop/proj/wlin_client/Application.cpp > CMakeFiles/wlin_client.dir/Application.cpp.i

CMakeFiles/wlin_client.dir/Application.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wlin_client.dir/Application.cpp.s"
	/usr/bin/clang++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/vl_sys/Desktop/proj/wlin_client/Application.cpp -o CMakeFiles/wlin_client.dir/Application.cpp.s

CMakeFiles/wlin_client.dir/Application.cpp.o.requires:

.PHONY : CMakeFiles/wlin_client.dir/Application.cpp.o.requires

CMakeFiles/wlin_client.dir/Application.cpp.o.provides: CMakeFiles/wlin_client.dir/Application.cpp.o.requires
	$(MAKE) -f CMakeFiles/wlin_client.dir/build.make CMakeFiles/wlin_client.dir/Application.cpp.o.provides.build
.PHONY : CMakeFiles/wlin_client.dir/Application.cpp.o.provides

CMakeFiles/wlin_client.dir/Application.cpp.o.provides.build: CMakeFiles/wlin_client.dir/Application.cpp.o


CMakeFiles/wlin_client.dir/Network.cpp.o: CMakeFiles/wlin_client.dir/flags.make
CMakeFiles/wlin_client.dir/Network.cpp.o: ../Network.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/vl_sys/Desktop/proj/wlin_client/cmake-build-debug-wsl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/wlin_client.dir/Network.cpp.o"
	/usr/bin/clang++-8  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/wlin_client.dir/Network.cpp.o -c /mnt/c/Users/vl_sys/Desktop/proj/wlin_client/Network.cpp

CMakeFiles/wlin_client.dir/Network.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wlin_client.dir/Network.cpp.i"
	/usr/bin/clang++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/vl_sys/Desktop/proj/wlin_client/Network.cpp > CMakeFiles/wlin_client.dir/Network.cpp.i

CMakeFiles/wlin_client.dir/Network.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wlin_client.dir/Network.cpp.s"
	/usr/bin/clang++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/vl_sys/Desktop/proj/wlin_client/Network.cpp -o CMakeFiles/wlin_client.dir/Network.cpp.s

CMakeFiles/wlin_client.dir/Network.cpp.o.requires:

.PHONY : CMakeFiles/wlin_client.dir/Network.cpp.o.requires

CMakeFiles/wlin_client.dir/Network.cpp.o.provides: CMakeFiles/wlin_client.dir/Network.cpp.o.requires
	$(MAKE) -f CMakeFiles/wlin_client.dir/build.make CMakeFiles/wlin_client.dir/Network.cpp.o.provides.build
.PHONY : CMakeFiles/wlin_client.dir/Network.cpp.o.provides

CMakeFiles/wlin_client.dir/Network.cpp.o.provides.build: CMakeFiles/wlin_client.dir/Network.cpp.o


CMakeFiles/wlin_client.dir/LinuxStatus/Linuxstatus.cpp.o: CMakeFiles/wlin_client.dir/flags.make
CMakeFiles/wlin_client.dir/LinuxStatus/Linuxstatus.cpp.o: ../LinuxStatus/Linuxstatus.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/vl_sys/Desktop/proj/wlin_client/cmake-build-debug-wsl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/wlin_client.dir/LinuxStatus/Linuxstatus.cpp.o"
	/usr/bin/clang++-8  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/wlin_client.dir/LinuxStatus/Linuxstatus.cpp.o -c /mnt/c/Users/vl_sys/Desktop/proj/wlin_client/LinuxStatus/Linuxstatus.cpp

CMakeFiles/wlin_client.dir/LinuxStatus/Linuxstatus.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wlin_client.dir/LinuxStatus/Linuxstatus.cpp.i"
	/usr/bin/clang++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/vl_sys/Desktop/proj/wlin_client/LinuxStatus/Linuxstatus.cpp > CMakeFiles/wlin_client.dir/LinuxStatus/Linuxstatus.cpp.i

CMakeFiles/wlin_client.dir/LinuxStatus/Linuxstatus.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wlin_client.dir/LinuxStatus/Linuxstatus.cpp.s"
	/usr/bin/clang++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/vl_sys/Desktop/proj/wlin_client/LinuxStatus/Linuxstatus.cpp -o CMakeFiles/wlin_client.dir/LinuxStatus/Linuxstatus.cpp.s

CMakeFiles/wlin_client.dir/LinuxStatus/Linuxstatus.cpp.o.requires:

.PHONY : CMakeFiles/wlin_client.dir/LinuxStatus/Linuxstatus.cpp.o.requires

CMakeFiles/wlin_client.dir/LinuxStatus/Linuxstatus.cpp.o.provides: CMakeFiles/wlin_client.dir/LinuxStatus/Linuxstatus.cpp.o.requires
	$(MAKE) -f CMakeFiles/wlin_client.dir/build.make CMakeFiles/wlin_client.dir/LinuxStatus/Linuxstatus.cpp.o.provides.build
.PHONY : CMakeFiles/wlin_client.dir/LinuxStatus/Linuxstatus.cpp.o.provides

CMakeFiles/wlin_client.dir/LinuxStatus/Linuxstatus.cpp.o.provides.build: CMakeFiles/wlin_client.dir/LinuxStatus/Linuxstatus.cpp.o


CMakeFiles/wlin_client.dir/StatusJSON/LsJson.cpp.o: CMakeFiles/wlin_client.dir/flags.make
CMakeFiles/wlin_client.dir/StatusJSON/LsJson.cpp.o: ../StatusJSON/LsJson.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/vl_sys/Desktop/proj/wlin_client/cmake-build-debug-wsl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/wlin_client.dir/StatusJSON/LsJson.cpp.o"
	/usr/bin/clang++-8  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/wlin_client.dir/StatusJSON/LsJson.cpp.o -c /mnt/c/Users/vl_sys/Desktop/proj/wlin_client/StatusJSON/LsJson.cpp

CMakeFiles/wlin_client.dir/StatusJSON/LsJson.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wlin_client.dir/StatusJSON/LsJson.cpp.i"
	/usr/bin/clang++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/vl_sys/Desktop/proj/wlin_client/StatusJSON/LsJson.cpp > CMakeFiles/wlin_client.dir/StatusJSON/LsJson.cpp.i

CMakeFiles/wlin_client.dir/StatusJSON/LsJson.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wlin_client.dir/StatusJSON/LsJson.cpp.s"
	/usr/bin/clang++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/vl_sys/Desktop/proj/wlin_client/StatusJSON/LsJson.cpp -o CMakeFiles/wlin_client.dir/StatusJSON/LsJson.cpp.s

CMakeFiles/wlin_client.dir/StatusJSON/LsJson.cpp.o.requires:

.PHONY : CMakeFiles/wlin_client.dir/StatusJSON/LsJson.cpp.o.requires

CMakeFiles/wlin_client.dir/StatusJSON/LsJson.cpp.o.provides: CMakeFiles/wlin_client.dir/StatusJSON/LsJson.cpp.o.requires
	$(MAKE) -f CMakeFiles/wlin_client.dir/build.make CMakeFiles/wlin_client.dir/StatusJSON/LsJson.cpp.o.provides.build
.PHONY : CMakeFiles/wlin_client.dir/StatusJSON/LsJson.cpp.o.provides

CMakeFiles/wlin_client.dir/StatusJSON/LsJson.cpp.o.provides.build: CMakeFiles/wlin_client.dir/StatusJSON/LsJson.cpp.o


# Object files for target wlin_client
wlin_client_OBJECTS = \
"CMakeFiles/wlin_client.dir/main.cpp.o" \
"CMakeFiles/wlin_client.dir/Application.cpp.o" \
"CMakeFiles/wlin_client.dir/Network.cpp.o" \
"CMakeFiles/wlin_client.dir/LinuxStatus/Linuxstatus.cpp.o" \
"CMakeFiles/wlin_client.dir/StatusJSON/LsJson.cpp.o"

# External object files for target wlin_client
wlin_client_EXTERNAL_OBJECTS =

wlin_client: CMakeFiles/wlin_client.dir/main.cpp.o
wlin_client: CMakeFiles/wlin_client.dir/Application.cpp.o
wlin_client: CMakeFiles/wlin_client.dir/Network.cpp.o
wlin_client: CMakeFiles/wlin_client.dir/LinuxStatus/Linuxstatus.cpp.o
wlin_client: CMakeFiles/wlin_client.dir/StatusJSON/LsJson.cpp.o
wlin_client: CMakeFiles/wlin_client.dir/build.make
wlin_client: /usr/lib/x86_64-linux-gnu/libboost_system.a
wlin_client: CMakeFiles/wlin_client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/vl_sys/Desktop/proj/wlin_client/cmake-build-debug-wsl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable wlin_client"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/wlin_client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/wlin_client.dir/build: wlin_client

.PHONY : CMakeFiles/wlin_client.dir/build

CMakeFiles/wlin_client.dir/requires: CMakeFiles/wlin_client.dir/main.cpp.o.requires
CMakeFiles/wlin_client.dir/requires: CMakeFiles/wlin_client.dir/Application.cpp.o.requires
CMakeFiles/wlin_client.dir/requires: CMakeFiles/wlin_client.dir/Network.cpp.o.requires
CMakeFiles/wlin_client.dir/requires: CMakeFiles/wlin_client.dir/LinuxStatus/Linuxstatus.cpp.o.requires
CMakeFiles/wlin_client.dir/requires: CMakeFiles/wlin_client.dir/StatusJSON/LsJson.cpp.o.requires

.PHONY : CMakeFiles/wlin_client.dir/requires

CMakeFiles/wlin_client.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/wlin_client.dir/cmake_clean.cmake
.PHONY : CMakeFiles/wlin_client.dir/clean

CMakeFiles/wlin_client.dir/depend:
	cd /mnt/c/Users/vl_sys/Desktop/proj/wlin_client/cmake-build-debug-wsl && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/vl_sys/Desktop/proj/wlin_client /mnt/c/Users/vl_sys/Desktop/proj/wlin_client /mnt/c/Users/vl_sys/Desktop/proj/wlin_client/cmake-build-debug-wsl /mnt/c/Users/vl_sys/Desktop/proj/wlin_client/cmake-build-debug-wsl /mnt/c/Users/vl_sys/Desktop/proj/wlin_client/cmake-build-debug-wsl/CMakeFiles/wlin_client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/wlin_client.dir/depend
