#include "Core.h"
#include "SDL.h"

#include <iostream>

namespace Core {

	void PrintHelloWorld()
	{
		std::cout << "Hello World!\n";
		std::cin.get();
	}

	void TestWindow()
	{
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			std::cout << "Failed to initialize SDL" << std::endl;
			return;
		}

		SDL_Window* pWin = SDL_CreateWindow("SDL2 Window",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			680, 480,
			0);

		if (!pWin)
		{
			std::cout << "Failed to create SDL window" << std::endl;
			return;
		}

		bool run = true;
		while (run)
		{
			SDL_Event e;
			while (SDL_PollEvent(&e)) 
			{
				switch(e.type)
				{
				case SDL_QUIT:
					run = false;
					break;
				}
			}
		}

		SDL_DestroyWindow(pWin);
		SDL_Quit();
	}
}