cmake_minimum_required(VERSION 3.10)
#francois
#Set the project name
project(FirstCMake VERSION 1.0)

#export configuration to source code
configure_file(cmake/FirstOrganizedCMakeConfig.h.in FirstOrganizedCMakeConfig.h)

# specify the C++ standard
# use the CMAKE_CXX_STANDARD variable
set(CMAKE_CXX_STANDARD  11)
set(CMAKE_CXX_STANDARD_REQUIERED TRUE)

#about libraries
add_subdirectory(src/log_lib)

#about executable
option(FIRSTORGANIZEDCMAKE_WITH_EXECUTABLES "Compile mains" ON)
if(FIRSTORGANIZEDCMAKE_WITH_EXECUTABLES)
	message(STATUS "Configuring FirstOrganizedCMake with executables")
	add_subdirectory(mains)
endif()

#about tests
option(FIRSTORGANIZEDCMAKE_WITH_TESTS "Compile test projects" ON)
if(FIRSTORGANIZEDCMAKE_WITH_TESTS)
	# Enable testing with CTest	
	enable_testing()
	message(STATUS "Configuring FirstOrganizedCMake with tests")
add_subdirectory(tests)
endif()

#export
include(CMakePackageConfigHelpers) # define the following command
configure_package_config_file(
	cmake/FirstOrganizedCMakeConfig.cmake.in 
	FirstOrganizedCMakeConfig.cmake
	INSTALL_DESTINATION ${PROJECT_BINARY_DIR}
)

# Configure CPack
if(WIN32)
	set(CPACK_GENERATOR "ZIP")
else()
	set(CPACK_GENERATOR "TGZ")
endif()

# This must always be last!
include(CPack)

