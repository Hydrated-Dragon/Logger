#pragma once
#if defined _WINDOWS //This class only works on windows
#include <Windows.h> //For things like AllocConsole() and some data types
#include <stdio.h>

namespace Log
{
	//Logging class
	//Create a new instance with 'Logger example("ExampleLogger")'
	class Logger
	{
	public:
		Logger() = delete; //Delete to prevent creation of logger without a name
		Logger(const char* logger_name);

		template<typename ...Args>
		void Info(const char* message, Args ... args)
		{
			CONSOLE_SCREEN_BUFFER_INFO bufInf;
			GetConsoleScreenBufferInfo(hConsole, &bufInf);

			SetConsoleTextAttribute(hConsole, 15);

			printf("[%s] INFO: ", m_Logger);
			printf(message, args...);
			printf("\n");

			SetConsoleTextAttribute(hConsole, bufInf.wAttributes);
		}

		template<typename ...Args>
		void Warning(const char* message, Args ... args)
		{
			CONSOLE_SCREEN_BUFFER_INFO bufInf;
			GetConsoleScreenBufferInfo(hConsole, &bufInf);

			SetConsoleTextAttribute(hConsole, 14);

			printf("[%s] WARNING: ", m_Logger);
			printf(message, args...);
			printf("\n");

			SetConsoleTextAttribute(hConsole, bufInf.wAttributes);
		}

		template<typename ...Args>
		void Error(const char* message, Args ... args)
		{
			CONSOLE_SCREEN_BUFFER_INFO bufInf;
			GetConsoleScreenBufferInfo(hConsole, &bufInf);

			SetConsoleTextAttribute(hConsole, 12);

			printf("[%s] ERROR: ", m_Logger);
			printf(message, args...);
			printf("\n");

			SetConsoleTextAttribute(hConsole, bufInf.wAttributes);
		}

		template<typename ...Args>
		void FatalError(const char* message, Args ... args)
		{
			CONSOLE_SCREEN_BUFFER_INFO bufInf;
			GetConsoleScreenBufferInfo(hConsole, &bufInf);

			SetConsoleTextAttribute(hConsole, 12);

			printf("[%s] FATAL_ERROR: ", m_Logger);
			printf(message, args...);
			printf("\n");

			SetConsoleTextAttribute(hConsole, bufInf.wAttributes);

			MessageBoxA(NULL, "A fatal error has occurred!\nCheck console for more Info", "Fatal Error", MB_ICONERROR);
			
			exit(EXIT_FAILURE);
		}

	private:
		const char* m_Logger; //Name of the logger which is shown in the Console

		HANDLE hConsole; //For color

		bool HasConsole(); //Just for checking if there is a console to write to
	};
}
#endif