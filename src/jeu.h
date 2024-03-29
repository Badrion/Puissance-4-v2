﻿#ifndef ABZ_JEU

#define ABZ_JEU

#include <SDL2/SDL.h>

// corp du jeu
void fonctionJeu(SDL_Window* pWindow, SDL_Renderer* pRenderer, FILE* fDebug, FILE* fSauvegarde);


// compose la grille
typedef struct CaseGrille{

    int joueur;
                 /*
                 0 = case vide
                 1 = joueur 1
                 2 = joueur 2
                 3 = joueur 3
                 */

     int etat;
                /*
                0 = case vide
                1 = normal
                2 = vient d'être joue
                3 = gagne
                */

} CaseGrille;

// gere le mode hardcore
typedef struct Hardcore{

	   int mode;
	               /*
	               0 = desactive
	               1 = mode 15 secondes
	               2 = mode 10 secondes
	               */

   	int tempsRestant;
} Hardcore;

void res_Hardcore(Hardcore* hardcore);

typedef struct Pion{
	   int x;// milieu du pion sur l'axe x

	   int y;// milieu du pion sur l'axe y

	   int velociteY;/* vitesse du pion sur l'axe y
	                 - = descend
	                 + = monte

	                 ! important ! avec SDL, si on fait y + 30, le pion va descendre de 30 pixels,
	                 il faut donc inverser et faire y - velociteY pour ne pas avoir d'erreurs.
	                 */
} Pion;


typedef struct Strat{
    int colonne;    // colonne du pion inférieur gauche de la strategie

    int ligne;      // ligne du pion inférieur gauche de la strategie

    int type;       /*
                    strategie utilisée

                    type est negatif pour itilisé la stratégie en "miroir"
                    */
} Strat;

void res_Strat(Strat* strat);

typedef struct Bot{
    Strat strat;

    int difficulte;     /*
                        1 : facile
                        2 : normal
                        3 : difficile
                        */
} Bot;

void res_Bot(Bot* bot);


typedef struct InfoJeu{
    CaseGrille grille[9][9];// grille de jeu

    FILE* fSauvegarde;

    Hardcore hardcore;

    int mode;   /*
                1 : Joueur contre Joueur
                2 : Joueur contre Ordinateur
                3 : Joueur contre Joueur contre Joueur
                4 : Ordinateur contre Ordinateur
                */

    Bot bot1, bot2;

    int joueurCommence;
    int joueur; // joueur actuel

    int colonne;// colonne jouee
    int tour;   // incremente a chaques tours, permet de detecter une egalite

} InfoJeu;

void res_InfoJeu(InfoJeu* jeu);


#endif // ABZ_JEU
