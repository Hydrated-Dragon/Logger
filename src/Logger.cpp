#if defined _WINDOWS //This class only works on windows
#include "logger.h"

namespace Log
{
	Logger::Logger(const char* logger_name)
		:m_Logger(logger_name)
	{
		if (!HasConsole())
		{
			AllocConsole();
			FILE* temp;
			freopen_s(&temp, "conout$", "w", stdout);

			Info("Created new console!");
		}

		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		Info("Logger has been successfully initialized");
	}

	bool Logger::HasConsole()
	{
		HWND consoleWindow;
		consoleWindow = GetConsoleWindow();

		if (consoleWindow)
			return true;

		return false;
	}
}
#endif