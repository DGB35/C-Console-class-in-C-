#include "Console.h"

#define CONSOLE_COLORS

namespace cl
{
	std::string Console::signature = "Copyright (c) 2020 DGB. All rights reserved.";

	Console::Console()
	{
		WriteSignature();
	}

	void Console::Clear()
	{
		system("CLS");
		WriteSignature();
	}

	void Console::Pause()
	{
		std::cin.get();
	}

	void Console::WriteSignature()
	{
	#ifdef CONSOLE_COLORS
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 14));
	#endif

		std::cout << signature << std::endl << std::endl;

	#ifdef CONSOLE_COLORS
		SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
	#endif
	}
}
