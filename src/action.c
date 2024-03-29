﻿/*
execute divers actions selon les evenements
*/

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

#include "debug.h"

#include "action.h"
#include "video.h"
#include "image.h"

// autre:

// appel de 'fermetureFenetre' (video.h) qui ferme le jeu

void aQuit(Images* Images, SDL_Window* pWindow, SDL_Renderer* pRenderer, FILE* fDebug, FILE* fSauvegarde)
{
    fermetureFenetre(Images, pWindow, pRenderer, fDebug, fSauvegarde);
}

void afficheDebug()
{
    debugWindow_Apparition();
}

// Parametre

// appel des parametres
void aParametre(int mode, int* joueurCommence,  Images* Images, SDL_Window* pWindow, SDL_Renderer* pRenderer, FILE* fDebug, FILE* fSauvegarde)
{
	   parametre(mode, joueurCommence, Images, pWindow, pRenderer, fDebug, fSauvegarde);
}

// Accueil

// fait retourner a l'accueil precedent
void aRetour(int* accueil)
{
    (*accueil)--;
}

    // 0:

// sort de l'ecran d'accueil
void aToucheAppuye(int* accueil)
{
    *accueil = -1;// sortie de l'accueil
}

    // 1:

// selection des modes de hardcore
void aHardcore(Hardcore* hardcore, float temps)
{

	if(temps >= 600)// reste appuye plus de 1 secondes
   	{
   		   if(hardcore->mode != 2)// le mode est different de 2
   		   {
   		       hardcore->mode = 2;// mode 2: 10 secondes pour jouer
   		   }
   		   else// le mode est 2
   		   {
   		       hardcore->mode = 0;// mode 0: pas de temps limite
   		   }
   	}
   	else if(hardcore->mode == 0)// reste appuyee moins de 2 secondes et le mode est 0
    {
   		   hardcore->mode = 1;// mode 1: 15 secondes pour jouer
    }
    else// reste appuyee moins de 2 secondes et le mode est different de 0
    {
    	   hardcore->mode = 0;// mode 0: pas de temps limite
    }

}

// 1v1
void aMode1(int* accueil, int* mode)
{
    *accueil = -1;// lancement du jeu
    *mode = 1;// 1v1
}

// 1vBot
void aMode2(int* accueil, int* mode)
{
    *accueil = 2;// accueil de choix de la difficultee des bots
    *mode = 2;// 1vBot
}

// 1v1v1
void aMode3(int* accueil, int* mode)
{
    *accueil = -1;// lancement du jeu
    *mode = 3;// 1v1v1
}

// BotvBot
void aMode4(int* accueil, int* mode)
{
    *accueil = 2;// accueil de choix de la difficultee des bots
    *mode = 4;// BotvBot
}

    // 2:

// difficultee du bot mise a facile
void aBotFacile(int* botDifficulte)
{
    *botDifficulte = 1;
}

// difficultee du bot mise a normale
void aBotNormal(int* botDifficulte)
{
    *botDifficulte = 2;
}

// difficultee du bot mise a difficile
void aBotDifficile(int* botDifficulte)
{
    *botDifficulte = 3;
}


// confirme la difficultee des bots
int aValide(int* accueil, int* mode, int* difficulteBot1, int* difficulteBot2)
{
    if(*difficulteBot1 != 0)// la difficultee du bot 1 a ete choisie
    {
        if(*mode == 4)// 2 bots
        {
            if(*difficulteBot2 != 0)// la difficultee du bot 2 a ete choisie
            {
                *accueil = -1;// lancement du jeu
                return 0;
            }
        }
        else if(*mode == 2)// 1 bot
        {
            *accueil = -1;// lancement du jeu
            return 0;
        }
    }

    return 1;
}

// Jeu

// assigne la colonne cliquee a la variable 'colonne'
void aJouerColonne(int c, int* colonne, int infoGrille[9])
{
	   if(infoGrille[c])// si il reste des cases vides dans la colonne cliquee
    {
        *colonne = c;
    }
}

// appel du menu (video.h)
void aMenu(int *rejouerPartie, int *retourAccueil, Hardcore* hardcore, int mode, int joueur, int tour, int* joueurCommence, caseGrille grille[9][9], Images* Images, SDL_Window *pWindow, SDL_Renderer *pRenderer, FILE *fDebug, FILE *fSauvegarde)
{
	   menu(rejouerPartie, retourAccueil, hardcore, mode, joueur, tour, joueurCommence, grille, Images, pWindow, pRenderer, fDebug, fSauvegarde);
}
