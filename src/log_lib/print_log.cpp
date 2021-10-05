#include <iostream>
#include <FirstOrganizedCMakeConfig.h>
#include <log_lib/print_log.h>

void hello_world() {
std::cout << "Hello world !\n" << std::endl;
}

void print_version() {
	std::cout << "project version is " << FirstCMake_VERSION_MAJOR << "." << FirstCMake_VERSION_MINOR << std::endl;
}