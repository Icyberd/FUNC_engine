#include "FUNC_program.hpp"
#include <SDL.h>

namespace FUNC_engine
{

	int mScreenWidth, mScreenHeight;

	SDL_Window*  mWindow  = NULL;
	SDL_Surface* mWindowSurface = NULL;

	FUNC_program::FUNC_program(const char* title, int screenWidth, int screenHeight, bool windowCentered) 
	{
	
		mScreenWidth  =  screenWidth;
		mScreenHeight = screenHeight;
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
			throw "Could not initialize SDL Video";

		if (windowCentered)
			mWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, mScreenWidth, mScreenHeight, SDL_WINDOW_SHOWN);
		else
			mWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, mScreenWidth, mScreenHeight, SDL_WINDOW_SHOWN);

		if (mWindow == NULL)
			throw "SDL Window could not be initialized";

		mWindowSurface = SDL_GetWindowSurface(mWindow);
	};
	FUNC_program::~FUNC_program() {};

	void FUNC_program::Delay(int delayMs) { SDL_Delay(delayMs); };

	void FUNC_program::RefreshWindow() { SDL_UpdateWindowSurface(mWindow); };

	bool FUNC_program::ShouldClose()
	{

		SDL_Event evnt;
		SDL_PollEvent(&evnt);
		switch (evnt.type)
		{
		case SDL_QUIT:
			return true;
			break;
		default:
			return false;
			break;
		}

	}

}
