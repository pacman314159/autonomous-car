# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.27

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\PACMAIN\school\lop12CTIN\ComputerScience\Autonomous_Car\millis_micros

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\PACMAIN\school\lop12CTIN\ComputerScience\Autonomous_Car\millis_micros\build

# Utility rule file for ELF2UF2Build.

# Include any custom commands dependencies for this target.
include CMakeFiles/ELF2UF2Build.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ELF2UF2Build.dir/progress.make

CMakeFiles/ELF2UF2Build: CMakeFiles/ELF2UF2Build-complete

CMakeFiles/ELF2UF2Build-complete: elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-install
CMakeFiles/ELF2UF2Build-complete: elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-mkdir
CMakeFiles/ELF2UF2Build-complete: elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-download
CMakeFiles/ELF2UF2Build-complete: elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-update
CMakeFiles/ELF2UF2Build-complete: elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-patch
CMakeFiles/ELF2UF2Build-complete: elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-configure
CMakeFiles/ELF2UF2Build-complete: elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-build
CMakeFiles/ELF2UF2Build-complete: elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-install
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=D:\PACMAIN\school\lop12CTIN\ComputerScience\Autonomous_Car\millis_micros\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Completed 'ELF2UF2Build'"
	"C:\Program Files\CMake\bin\cmake.exe" -E make_directory D:/PACMAIN/school/lop12CTIN/ComputerScience/Autonomous_Car/millis_micros/build/CMakeFiles
	"C:\Program Files\CMake\bin\cmake.exe" -E touch D:/PACMAIN/school/lop12CTIN/ComputerScience/Autonomous_Car/millis_micros/build/CMakeFiles/ELF2UF2Build-complete
	"C:\Program Files\CMake\bin\cmake.exe" -E touch D:/PACMAIN/school/lop12CTIN/ComputerScience/Autonomous_Car/millis_micros/build/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-done

elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-build: elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-configure
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=D:\PACMAIN\school\lop12CTIN\ComputerScience\Autonomous_Car\millis_micros\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Performing build step for 'ELF2UF2Build'"
	cd /d D:\PACMAIN\school\lop12CTIN\ComputerScience\Autonomous_Car\millis_micros\build\elf2uf2 && $(MAKE)

elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-configure: elf2uf2/tmp/ELF2UF2Build-cfgcmd.txt
elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-configure: elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-patch
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=D:\PACMAIN\school\lop12CTIN\ComputerScience\Autonomous_Car\millis_micros\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Performing configure step for 'ELF2UF2Build'"
	cd /d D:\PACMAIN\school\lop12CTIN\ComputerScience\Autonomous_Car\millis_micros\build\elf2uf2 && "C:\Program Files\CMake\bin\cmake.exe" -DCMAKE_MAKE_PROGRAM:FILEPATH=C:/mingw64/bin/mingw32-make.exe "-GMinGW Makefiles" -S C:/VSARM/sdk/pico/pico-sdk/tools/elf2uf2 -B D:/PACMAIN/school/lop12CTIN/ComputerScience/Autonomous_Car/millis_micros/build/elf2uf2
	cd /d D:\PACMAIN\school\lop12CTIN\ComputerScience\Autonomous_Car\millis_micros\build\elf2uf2 && "C:\Program Files\CMake\bin\cmake.exe" -E touch D:/PACMAIN/school/lop12CTIN/ComputerScience/Autonomous_Car/millis_micros/build/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-configure

elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-download: elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-source_dirinfo.txt
elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-download: elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-mkdir
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=D:\PACMAIN\school\lop12CTIN\ComputerScience\Autonomous_Car\millis_micros\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "No download step for 'ELF2UF2Build'"
	"C:\Program Files\CMake\bin\cmake.exe" -E echo_append
	"C:\Program Files\CMake\bin\cmake.exe" -E touch D:/PACMAIN/school/lop12CTIN/ComputerScience/Autonomous_Car/millis_micros/build/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-download

elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-install: elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-build
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=D:\PACMAIN\school\lop12CTIN\ComputerScience\Autonomous_Car\millis_micros\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "No install step for 'ELF2UF2Build'"
	cd /d D:\PACMAIN\school\lop12CTIN\ComputerScience\Autonomous_Car\millis_micros\build\elf2uf2 && "C:\Program Files\CMake\bin\cmake.exe" -E echo_append

elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-mkdir:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=D:\PACMAIN\school\lop12CTIN\ComputerScience\Autonomous_Car\millis_micros\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Creating directories for 'ELF2UF2Build'"
	"C:\Program Files\CMake\bin\cmake.exe" -Dcfgdir= -P D:/PACMAIN/school/lop12CTIN/ComputerScience/Autonomous_Car/millis_micros/build/elf2uf2/tmp/ELF2UF2Build-mkdirs.cmake
	"C:\Program Files\CMake\bin\cmake.exe" -E touch D:/PACMAIN/school/lop12CTIN/ComputerScience/Autonomous_Car/millis_micros/build/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-mkdir

elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-patch: elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-patch-info.txt
elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-patch: elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-update
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=D:\PACMAIN\school\lop12CTIN\ComputerScience\Autonomous_Car\millis_micros\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "No patch step for 'ELF2UF2Build'"
	"C:\Program Files\CMake\bin\cmake.exe" -E echo_append
	"C:\Program Files\CMake\bin\cmake.exe" -E touch D:/PACMAIN/school/lop12CTIN/ComputerScience/Autonomous_Car/millis_micros/build/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-patch

elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-update: elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-update-info.txt
elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-update: elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-download
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=D:\PACMAIN\school\lop12CTIN\ComputerScience\Autonomous_Car\millis_micros\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "No update step for 'ELF2UF2Build'"
	"C:\Program Files\CMake\bin\cmake.exe" -E echo_append
	"C:\Program Files\CMake\bin\cmake.exe" -E touch D:/PACMAIN/school/lop12CTIN/ComputerScience/Autonomous_Car/millis_micros/build/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-update

ELF2UF2Build: CMakeFiles/ELF2UF2Build
ELF2UF2Build: CMakeFiles/ELF2UF2Build-complete
ELF2UF2Build: elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-build
ELF2UF2Build: elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-configure
ELF2UF2Build: elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-download
ELF2UF2Build: elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-install
ELF2UF2Build: elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-mkdir
ELF2UF2Build: elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-patch
ELF2UF2Build: elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-update
ELF2UF2Build: CMakeFiles/ELF2UF2Build.dir/build.make
.PHONY : ELF2UF2Build

# Rule to build all files generated by this target.
CMakeFiles/ELF2UF2Build.dir/build: ELF2UF2Build
.PHONY : CMakeFiles/ELF2UF2Build.dir/build

CMakeFiles/ELF2UF2Build.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ELF2UF2Build.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ELF2UF2Build.dir/clean

CMakeFiles/ELF2UF2Build.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\PACMAIN\school\lop12CTIN\ComputerScience\Autonomous_Car\millis_micros D:\PACMAIN\school\lop12CTIN\ComputerScience\Autonomous_Car\millis_micros D:\PACMAIN\school\lop12CTIN\ComputerScience\Autonomous_Car\millis_micros\build D:\PACMAIN\school\lop12CTIN\ComputerScience\Autonomous_Car\millis_micros\build D:\PACMAIN\school\lop12CTIN\ComputerScience\Autonomous_Car\millis_micros\build\CMakeFiles\ELF2UF2Build.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/ELF2UF2Build.dir/depend

