#include "SDL.h" 
#include <iostream>
#include <vector>
using namespace std;


void drawlines(SDL_Renderer* r, vector<int>& initvec);
void orderlines(SDL_Renderer* render, vector<int>& v);


int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {										//Starts the SDL library to 0
		cout << "error initializing SDL: %s\n" << SDL_GetError() << endl;
	}

	SDL_Window* mywin;
	SDL_Renderer* rend;
	vector<int> myvec;

	mywin = SDL_CreateWindow("BubbleSort", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 400, SDL_WINDOW_RESIZABLE);						//Creating a window and renderer
	rend = SDL_CreateRenderer(mywin, -1, SDL_RENDERER_ACCELERATED);


	drawlines(rend, myvec);
	SDL_Delay(2000);
	orderlines(rend, myvec);
	SDL_Delay(4000);


	SDL_DestroyRenderer(rend);											//Destroys the window and renderer
	SDL_DestroyWindow(mywin);
	SDL_Quit();
	
	return 0;
}


void drawlines(SDL_Renderer* r, vector<int>& initvec) {
	int randy = 0;
	for (int i = 0; i < 800; i++) {													//Randomly generates a line with a length between 0-400
		randy = rand() % 400;
		initvec.push_back(randy);													//The element's position in the vector contains its x-axis
		SDL_SetRenderDrawColor(r, 255, 255, 255, 255);								//The element's value is the length of the line
		SDL_RenderDrawLine(r, i, 0, i, randy);
		SDL_RenderPresent(r);
	}
}

void orderlines(SDL_Renderer* r, vector<int>& v) {
	int temp = 0;
	for (int i = 0; i < v.size(); i++) {											//Starting the bubble sort
		for (int j = 0; j < v.size() - 1; j++) {
			if (v[j] > v[j + 1]) {													//Swaps the two elements
				temp = v[j];
				SDL_SetRenderDrawColor(r, 0, 0, 0, 255);
				SDL_RenderDrawLine(r, j, 0, j, v[j]);
				v[j] = v[j + 1];
				v[j + 1] = temp;
				SDL_SetRenderDrawColor(r, 255, 255, 255, 255);						//Provides the animation
				SDL_RenderDrawLine(r, j, 0, j, v[j]);
				SDL_RenderDrawLine(r, j + 1, 0, j + 1, v[j + 1]);
				SDL_RenderPresent(r);
			}
		}
	}
}
