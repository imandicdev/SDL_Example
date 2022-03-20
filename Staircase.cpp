// Program to draw a staircase
// -- from _C++20 for Lazy Programmers_ by Will Brigs
// Author: Ilija Mandic
// Drawing StairCase from chapter 11 SDL way (with some SSDL)

#include <iostream>
#include "SSDL.h"
#include "SDL.h"


constexpr int ScreenWidth = 400;
constexpr int ScreenHeight = 200;

constexpr int MAX_POINTS = 25;
constexpr int STAIR_STEP_LENGTH = 15;



struct Point2D // A struct to hold a 2-D point
{
	int x_, y_;
};

int main(int argc, char** argv)
{


	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;


	window = SDL_CreateWindow("Stairway example: Hit a key to end", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, ScreenWidth, ScreenHeight, 0);

	renderer = SDL_CreateRenderer(window, -1, 0);
	if (!renderer) {
		std::cout << "SDL: could not create renderer - exiting " << std::endl << SDL_GetError();
		return -1;
	}



	Point2D myPoints[MAX_POINTS];

	int width, height;
	SDL_GetWindowSize(window, &width, &height); // For calculating window height
	int x = 0; // Start at lower left corner
	int y = height - 1; // of screen


	for (int i = 0; i < MAX_POINTS; ++i) // Fill an array with points
	{
		myPoints[i] = { x, y };
		// On iteration 0, go up (change Y)
		// On iteration 1, go right
		// then up, then right, then up...
		if (i % 2 == 0) // If i is even...
			y -= STAIR_STEP_LENGTH;
		else
			x += STAIR_STEP_LENGTH;
	}

	for (int i = 0; i < MAX_POINTS - 1; ++i)
	{   
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderDrawLine(renderer, myPoints[i].x_, myPoints[i].y_, myPoints[i + 1].x_, myPoints[i + 1].y_);
		SDL_RenderPresent(renderer);
		SDL_UpdateWindowSurface(window);
    }


	SSDL_WaitKey();


	return 0;

}