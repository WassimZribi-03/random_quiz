
#include <stdio.h>
#include <SDL/SDL.h>
#include <time.h>
#include <SDL/SDL_image.h>
//#include <SDL/SDL_mixer.h>
//#include <SDL/SDL_ttf.h>
#include "header_quiz.h"



void afficher_score(SDL_Surface* window , int res){
	taha_reaction result;
	if (res < 3)
	{	
			result.pic = IMG_Load("tf.png");
	}
	else{

			result.pic = IMG_Load("tw.png");
	}
	for (int i = 0; i < 4; ++i){	
		result.rect_pic[i] = result.pic->clip_rect;
	}
	result.pos_pic = window->clip_rect;
	result.pos_pic.x = 360;
	result.pos_pic.y = 200;


	result.rect_pic[0].x = 0;
	result.rect_pic[0].w = 200;

	result.rect_pic[1].x = 200;
	result.rect_pic[1].w = 200;

	result.rect_pic[2].x = 400;
	result.rect_pic[2].w = 200;

	result.rect_pic[3].x = 600;
	result.rect_pic[3].w = 200;

	printf("\nbefore animation\n");
	for (int j = 0; j < 3; ++j)
	{
		for (int i = 0; i < 4; i++){
			//SDL_BlitSurface(result->pic , &(result->rect_pic[i]),window,&());
			printf("%d\n",i);
			SDL_BlitSurface(result.pic , &(result.rect_pic[i]),window,&(result.pos_pic));
			SDL_Delay(500);
			SDL_Flip(window);
		}
	}
	return;
}

//////--------------------------------------------------------/////////
int calculer_score(page* p[], int mx , int my , SDL_Surface* window ){
	if ( (mx < 500 && mx >400 )&&(my >510 && my <550) )
	{
		int i,end;
		int res = 0;
		for (int i = 0; i < 3; i++)
		{
			printf(" ________________ page %d ------------------- \n",i);
			printf(" answer = %d \t choix =  %d \n",p[i]->answer,p[i]->choix);
			if (p[i]->choix == p[i]->answer){
				printf("--------------------- question %d est vrai -------------------\n\n",i+1);
				res = res +1;
			}
		}
		SDL_FillRect(window,NULL,SDL_MapRGB(window->format ,180,180,180));
		afficher_score(window,res);
		return res;
	}
	else{
		return 0;
	}
}

/////////////////////// - ALGORITMIQUE - //////////////////////////////////

page* remplir_page_algo(page *p ,SDL_Surface *window , int i ){

		p->box = SDL_DisplayFormat(IMG_Load("b2.jpg"));
		p->pos_image  = window->clip_rect;
		p->pos_image.x = 200;

		p->verif_box[0] = p->box->clip_rect;
		(p->verif_box[0]).w = ((p->verif_box[0]).w)/2;
		p->verif_box[1] = p->box->clip_rect;
		(p->verif_box[1]).x = ((p->verif_box[1]).w) /2 ;
		p->pos_image  = window->clip_rect;
		p->pos_image.x = 200;

		(p->pos_box[0]) = p->box->clip_rect;
		(p->pos_box[1]) = p->box->clip_rect;
		(p->pos_box[2]) = p->box->clip_rect;
		

	if (i == 0){

		p->image = SDL_DisplayFormat(IMG_Load("A_Q1.jpg"));
		(p->pos_box[0]).x = ( 500 + 110);
		(p->pos_box[0]).y = 195;

		(p->pos_box[1]).x = ( 500 + 110);
		(p->pos_box[1]).y = (195) + 40 + 20;

		(p->pos_box[2]).x = ( 500 + 110);
		(p->pos_box[2]).y = (195 + 45 + 20)+45+30;
		
		p->choix = 0;
		p->answer = 3;
	}
	else if (i == 1){
		p->image = SDL_DisplayFormat(IMG_Load("A_Q2.jpg"));
		(p->pos_box[0]).x =( 500 + 110);
		(p->pos_box[0]).y = (335);

		(p->pos_box[1]).x = ( 500 + 110); 
		(p->pos_box[1]).y = (335) + 40 + 20;
		
		(p->pos_box[2]).x = ( 500 + 110); 
		(p->pos_box[2]).y = ((335) + 40 + 20)+40+20;
		
		p->choix = 0;
		p->answer =  3;
	}
	else if (i == 2){
		p->image = SDL_DisplayFormat(IMG_Load("A_Q3.jpg"));
		(p->pos_box[0]).x =( 500 + 110);
		(p->pos_box[0]).y = (190);

		(p->pos_box[1]).x =( 500 + 110);
		(p->pos_box[1]).y = (190) + 40 + 20;

		(p->pos_box[2]).x =( 500 + 110);
		(p->pos_box[2]).y = ((190) + 40 + 20)+40+20+20;

		p->choix = 0;
		p->answer = 1;
	}
	else{
		printf("something went wrong \n");
		return NULL;
	}

	return p;
}
	

/////////////////////// - ELECTRONIQUE - //////////////////////////////////

page* remplir_page_electro(page *p ,SDL_Surface *window , int i ){

		p->box = SDL_DisplayFormat(IMG_Load("b2.jpg"));
		p->pos_image  = window->clip_rect;
		p->pos_image.x = 200;

		p->verif_box[0] = p->box->clip_rect;
		(p->verif_box[0]).w = ((p->verif_box[0]).w)/2;
		p->verif_box[1] = p->box->clip_rect;
		(p->verif_box[1]).x = ((p->verif_box[1]).w) /2 ;
		p->pos_image  = window->clip_rect;
		p->pos_image.x = 200;

		(p->pos_box[0]) = p->box->clip_rect;
		(p->pos_box[1]) = p->box->clip_rect;
		(p->pos_box[2]) = p->box->clip_rect;
		

	if (i == 0){

		p->image = SDL_DisplayFormat(IMG_Load("Q1_E.jpg"));
		(p->pos_box[0]).x = ( 500 + 110);
		(p->pos_box[0]).y = 330;

		(p->pos_box[1]).x = ( 500 + 110);
		(p->pos_box[1]).y = (330) + 45 + 20;

		(p->pos_box[2]).x = ( 500 + 110);
		(p->pos_box[2]).y = (330 +65+45+20);

		p->choix = 0;
		p->answer = 3;
	}
	else if (i == 1){
		p->image = SDL_DisplayFormat(IMG_Load("Q2_E.jpg"));
		(p->pos_box[0]).x =( 500 + 110);
		(p->pos_box[0]).y = (320);

		(p->pos_box[1]).x = ( 500 + 110); 
		(p->pos_box[1]).y = (330)+45+20;
		
		(p->pos_box[2]).x = ( 500 + 110); 
		(p->pos_box[2]).y = (330)+65+45+20 + 15;

		p->choix = 0;
		p->answer =  2;
	}
	else if (i == 2){
		p->image = SDL_DisplayFormat(IMG_Load("Q3_E.jpg"));
		(p->pos_box[0]).x =( 500 + 110);
		(p->pos_box[0]).y = (280);

		(p->pos_box[1]).x =( 500 + 110);
		(p->pos_box[1]).y = (280 + 75);

		(p->pos_box[2]).x =( 500 + 110);
		(p->pos_box[2]).y = (280 + 75 +45 +35);

		p->choix = 0;
		p->answer = 3;
	}
	else{
		printf("something went wrong \n");
		return NULL;
	}

	return p;
}


/////////////////////// - MATHEMATIQUE - //////////////////////////////////

page* remplir_page_math(page *p ,SDL_Surface *window , int i ){
		SDL_Surface* btn_valider;
		SDL_Rect btn_pos;
		p->box = SDL_DisplayFormat(IMG_Load("b2.jpg"));
		p->pos_image  = window->clip_rect;
		p->pos_image.x = 200;

		p->verif_box[0] = p->box->clip_rect;
		(p->verif_box[0]).w = ((p->verif_box[0]).w)/2;
		p->verif_box[1] = p->box->clip_rect;
		(p->verif_box[1]).x = ((p->verif_box[1]).w) /2 ;
		p->pos_image  = window->clip_rect;
		p->pos_image.x = 200;

		(p->pos_box[0]) = p->box->clip_rect;
		(p->pos_box[1]) = p->box->clip_rect;
		(p->pos_box[2]) = p->box->clip_rect;
		

	if (i == 0){

		p->image = SDL_DisplayFormat(IMG_Load("Q1_math.jpg"));
		(p->pos_box[0]).x = ( 500 + 110);
		(p->pos_box[0]).y = (235);

		(p->pos_box[1]).x = ( 500 + 110);
		(p->pos_box[1]).y = 240+70;

		(p->pos_box[2]).x = ( 500 + 110);
		(p->pos_box[2]).y = (390);

		p->choix = 0;
		p->answer = 3;
	}
	else if (i == 1){
		p->image = SDL_DisplayFormat(IMG_Load("Q2_math.jpg"));
		(p->pos_box[0]).x =( 500 + 110);
		(p->pos_box[0]).y = (210);

		(p->pos_box[1]).x = ( 500 + 110); 
		(p->pos_box[1]).y = 290;
		
		(p->pos_box[2]).x = ( 500 + 110); 
		(p->pos_box[2]).y = 370;

		p->choix = 0;
		p->answer =  1;
	}
	else if (i == 2){
		p->image = SDL_DisplayFormat(IMG_Load("Q3_math.jpg"));
		(p->pos_box[0]).x =( 500 + 110);
		(p->pos_box[0]).y = (220);

		(p->pos_box[1]).x =( 500 + 110);
		(p->pos_box[1]).y = (300);

		(p->pos_box[2]).x =( 500 + 110);
		(p->pos_box[2]).y = (380);

		p->choix = 0;
		p->answer = 2;
	}
	else{
		printf("something went wrong \n");
		return NULL;
	}

	return p;
}



////////////////////////  delete later //////////////////////

/*
	typedef struct {
		SDL_Surface *image;
		SDL_Rect pos_image;

		SDL_Surface *box;
		SDL_Rect verif_box[2];
		SDL_Rect pos_box[3];
		int answer;
	}page;
*/
///////////////////////////////////////////////////////////////

int  choose_answer(int mx , int my , page* p , SDL_Surface *window){
	SDL_Rect box;
	box = p->pos_box[0];
	printf("mouse X = %d\t",mx);
	printf("mouse Y = %d\n",my);
	printf(" box X = %d\t",box.x);
	printf(" box Y = %d\n",box.y);
	printf(" box x+w = %d\n",box.x+box.w);
	printf(" box Y+h = %d\n",box.y+box.h);
	
	if ( (mx > box.x )&& (mx < (box.w + box.x ) ) && (my > box.y)&&(my < (box.y+box.h)) )
	{
		/*SDL_BlitSurface(p->box , &(p->verif_box[1]) , window ,&(p->pos_box[0]) );
		if (p->answer == 1)
		{
			return 1;
		}
		*/
		printf("box 1 clicked \n");
		return 1;

	}
box = p->pos_box[1];

		if ( ( (mx > box.x )&& (mx < (box.w+box.x ) ) && ( (my > box.y)&&(my < (box.y+box.h) ))))
	{
		/*SDL_BlitSurface(p->box , &(p->verif_box[1]) , window ,&(p->pos_box[1]) );
		if (p->answer == 2)
		{
			return 1;
		}
		*/

		printf("box 2 clicked \n");
		return 2;

	}

	box = p->pos_box[2];

		if ( ( (mx > box.x )&& (mx < (box.w+box.x) ) && ( (my > box.y)&&(my < (box.y+box.h) ))))
	{
		/*SDL_BlitSurface(p->box , &(p->verif_box[1]) , window ,&(p->pos_box[0]) );
		if (p->answer == 2)
		{
			return 1;
		}
		*/
		printf("box 3 clicked \n");
		return 3;

	}

	return p->choix;
}

//////////////////////////////////////////////////////////////

void switch_page(SDL_Surface *window , int index,page* question[]){

	SDL_BlitSurface( (question[index])->image ,NULL ,window ,&((question[index])->pos_image) );
	SDL_BlitSurface( (question[index])->box , &( (question[index])->verif_box[0] ) ,window , &(question[index])->pos_box[0]);
	SDL_BlitSurface( (question[index])->box , &( (question[index])->verif_box[0] ) ,window , &(question[index])->pos_box[1]);
	SDL_BlitSurface( (question[index])->box , &( (question[index])->verif_box[0] ) ,window , &(question[index])->pos_box[2]);

	if (question[index]->choix == 1)
	{
		SDL_BlitSurface( (question[index])->box , &( (question[index])->verif_box[1] ) ,window , &(question[index])->pos_box[0]);
	}
	if (question[index]->choix == 2)
	{
		SDL_BlitSurface( (question[index])->box , &( (question[index])->verif_box[1] ) ,window , &(question[index])->pos_box[1]);
	}
	if(question[index]->choix == 3)
	{
		SDL_BlitSurface( (question[index])->box , &( (question[index])->verif_box[1] ) ,window , &(question[index])->pos_box[2]);
	}

	if (index == 2){

		SDL_Surface* btn_valider;
		SDL_Rect btn_pos;

		btn_valider = SDL_DisplayFormat(IMG_Load("bv1.jpg"));
		btn_pos = window->clip_rect;
		btn_pos.x = 400;
		btn_pos.y = 510;
		SDL_BlitSurface(btn_valider , NULL , window , &(btn_pos));
	}

}



//-------------------------------------------------//


int PLAY_QUIZ(SDL_Surface * screen){

	
	int mouseX , mouseY;
	time_t t ;
	int random ;
	int score = 0;
	int ind = 0;
	int i;
	int end = 0;

    SDL_Surface *bg;
    page *p[3];

	SDL_Event event1 ;

	end = 0;
	int running=1;

	srand( (unsigned) time(&t));
	random = 1 + (rand() % 3) ;

	bg = SDL_DisplayFormat(IMG_Load("bg.png"));
	//SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format ,255,255,255));

	printf("before for loop \n");

	for (int i = 0; i < 3; ++i)
	{
		p[i] = malloc(sizeof(page));
		if (random == 1)
		{
			p[i] = remplir_page_algo(p[i] ,screen ,i);
		}
		else if (random == 2)
		{
			p[i] = remplir_page_math(p[i] ,screen ,i);
		}
		else{
			p[i] = remplir_page_electro(p[i] ,screen ,i);
		}
		
	}
	
	printf("after for loop \n");

	

	SDL_BlitSurface(bg ,NULL ,screen,NULL );
	switch_page(screen,0,p);

	printf("before main loop \n");
	
	while(running ==1){
	
		//quiz_algo_1(screen);

		
		while(SDL_PollEvent(&event1)){
			
			switch(event1.type){
				case SDL_QUIT:
					running = 0;
					break;

				case SDL_MOUSEBUTTONDOWN : 
					if (event1.button.button == 1) // btn gauche clicked
					{

						mouseX = (int)event1.button.x;
						mouseY = (int)event1.button.y;
						p[ind]->choix = choose_answer(mouseX , mouseY , p[ind] ,screen);
						printf("choix =============== %d  \n",p[ind]->choix);
						
						end = calculer_score(p, mouseX,mouseY,screen);
												
					}

				case SDL_KEYDOWN :// keyboard
					switch(event1.key.keysym.sym){
						case SDLK_LEFT :
							if (ind >0)
							{
								ind--;
							}
							break;

						case SDLK_RIGHT :
							if (ind<2)
							{
								ind++;
							}
							break;
					}
					break;



			}

		}
		if(end == 0){
		switch_page(screen,ind,p);
		}
	
		SDL_Flip(screen);
		//printf("end == %d \n",end);

		

	}


	return end;
	}