#pragma once
#include <SDL.h>

namespace FUNC_engine
{
	class FUNC_program
	{
	public:
		FUNC_program(const char* title, int screenWidth, int screenHeight, bool windowCentered);
		virtual ~FUNC_program();

		void Delay(int delayMs);
		void RefreshWindow();

		bool ShouldClose();

		void Exit();
	};

};

