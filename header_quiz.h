#ifndef QUIZ_H
#define QUIZ_H
	



	typedef struct {
		SDL_Surface *image;
		SDL_Rect pos_image;

		SDL_Surface *box;
		SDL_Rect verif_box[2];
		SDL_Rect pos_box[3];

		int answer;
		int choix;
		
	}page;

	typedef struct{
		SDL_Surface *pic;

		SDL_Rect rect_pic[4];
		SDL_Rect pos_pic;
	}taha_reaction;



	int PLAY_QUIZ(SDL_Surface * screen);
	void afficher_score(SDL_Surface* window , int res);
	int calculer_score(page* p[],int mx , int my,SDL_Surface* window );
	void switch_page(SDL_Surface *window , int index,page* question[]);
	page** create_algo(SDL_Surface *window);
	page* remplir_page_algo(page *p ,SDL_Surface *window , int i );
	page* remplir_page_electro(page *p ,SDL_Surface *window , int i );
	page* remplir_page_math(page *p ,SDL_Surface *window , int i );
	int  choose_answer(int mx , int my , page* p , SDL_Surface *window);
	int quiz_algo_1(SDL_Surface *window);
	// page* remplir_page(int random ,page P[]);
#endif // QUIZ_H