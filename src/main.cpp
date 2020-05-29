#include <iostream>
#include "Core.hpp"
#include "Exception.hpp"
#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

int main()
{
	try {
		Core prog;
		prog.launch();
	} catch (Exception &err) {
		std::cerr << err.what() << std::endl;
		return (84);
	}
	return (0);
}