#include <time.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
//#include <SDL/SDL_mixer.h>
//#include <SDL/SDL_ttf.h>
#include "header_quiz.h"


int main(int argC , char **argV){

	SDL_Surface *screen ;
	int score ;



	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0 ){
		printf("__error 000__ \n");
		return 1;
	}
	
	else{
		printf("__yeeeyy !!!! __\n");
	}
	
	screen = SDL_SetVideoMode(900,600,32,SDL_SWSURFACE | SDL_DOUBLEBUF);
	if (screen == NULL )
	{
		printf("__error 001__ \n");
		SDL_Quit();
		return 1;
	}

	score = PLAY_QUIZ(screen);
	printf("sccore == %d\n",score);
	SDL_Quit();

	return 0;
}
