﻿#include <SDL2/SDL.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "grille.h"
#include "video.h"
#include "image.h"

#include "jeu.h"

// remet a zero la grille, la structure 'case'
void res_Grille(CaseGrille grille[9][9])
{
	   // pour toute la grille
    for(int i=0;i<9;i++)
    {
        for(int ii=0;ii<9;ii++)
        {
        	   // initialise la structure
            grille[i][ii].joueur = 0;
            grille[i][ii].etat = 0;
        }
    }
}

// trouve a quelle case placer le pion, et le place
int placePion(int joueur, int colonne, int mode, int tour, int *rejouerPartie, int *retourAccueil, int* joueurCommence, Hardcore* hardcore, caseGrille grille[9][9], Images* Images, SDL_Window *pWindow, SDL_Renderer *pRenderer, FILE *fDebug, FILE *fSauvegarde)
{

int l;

// nombre de lignes different selon le mode
if(mode != 3)
    l = 6;
else
{
    l = 8;
}

    for(int ligne = 0; ligne < l; ligne++)
    {
        if(grille[colonne][ligne].joueur == 0)// cherche une case vide dans la colonne donnee
        {

            remplacePion_joue(grille);// change l'ancien 'pion_joue' en pion normal

            animationPion(colonne, joueur, mode, tour, rejouerPartie, retourAccueil, joueurCommence, hardcore, grille, Images, pWindow, pRenderer, fDebug, fSauvegarde);

            grille[colonne][ligne].joueur = joueur;// la case jouee est assigne au joueur
            grille[colonne][ligne].etat = 2;// elle prend l'etat 'pion_joue'

            return 0;
        }
    }

    return 1;
}

// change les "pion_joue" en "pion"
void remplacePion_joue(caseGrille grille[9][9])
{

    for(int colonne = 0; colonne < 9; colonne++)
    {
    	   for(int ligne = 0; ligne < 8; ligne++)
    	   {

    	   	   if(grille[colonne][ligne].etat == 2)// chercher un 'pion_joue'
    	   	       grille[colonne][ligne].etat = 1;// le remplace par un pion normal
    	   }
    }

}

// verifie les puissance 4
int aligne4(caseGrille grille[9][9], int mode)
{

    int fin = 0;// indique le joueur qui gagne
    int ligneMax, colonneMax;

    if(mode != 3)
    {
        ligneMax = 6;
        colonneMax = 7;
    }
    else
    {
        ligneMax = 8;
        colonneMax = 9;
    }

    for(int pion = 1; pion < 4; pion++)
    {
        for(int colonne = 0; colonne < colonneMax; colonne++)
        {
            for(int l = 0, ll = 1, lll = 2, llll = 3; llll < ligneMax ; l++, ll++, lll++, llll++)
            {
                // |
                if(grille[colonne][llll].joueur == pion   //  |
                    &&grille[colonne][lll].joueur == pion //  |
                    &&grille[colonne][ll].joueur == pion  //  |
                    &&grille[colonne][l].joueur == pion)  //  |
                {
                    grille[colonne][llll].etat = 3;
                    grille[colonne][lll].etat = 3;
                    grille[colonne][ll].etat = 3;
                    grille[colonne][l].etat = 3;

                    fin = pion;
                }
            }
        }


        for(int ligne = 0; ligne < ligneMax; ligne++)
        {
            for(int c = 0, cc = 1, ccc = 2, cccc = 3; cccc < colonneMax; c++, cc++, ccc++, cccc++)
            {
                // —
                if(grille[c][ligne].joueur == pion          //  * - - -
                    &&grille[cc][ligne].joueur == pion      //  - * - -
                    &&grille[ccc][ligne].joueur == pion     //  - - * -
                    &&grille[cccc][ligne].joueur == pion)   //  - - - *
                {
                    grille[c][ligne].etat = 3;
                    grille[cc][ligne].etat = 3;
                    grille[ccc][ligne].etat = 3;
                    grille[cccc][ligne].etat = 3;

                    fin = pion;
                }
            }
        }


        for(int c = 0, cc = 1, ccc = 2, cccc = 3; cccc < colonneMax; c++, cc++, ccc++, cccc++)
        {
            for(int l = 0, ll = 1, lll = 2, llll = 3; llll < ligneMax ; l++, ll++, lll++, llll++)
            {
                // /
                if(grille[cccc][llll].joueur == pion    //       /
                    &&grille[ccc][lll].joueur == pion   //     /
                    &&grille[cc][ll].joueur == pion     //   /
                    &&grille[c][l].joueur == pion)      // /
                {
                    grille[cccc][llll].etat = 3;
                    grille[ccc][lll].etat = 3;
                    grille[cc][ll].etat = 3;
                    grille[c][l].etat = 3;

                    fin = pion;
                }
            }
        }



        for(int c = 0, cc = 1, ccc = 2, cccc = 3; cccc < colonneMax; c++, cc++, ccc++, cccc++)
        {
            for(int l = 0, ll = 1, lll = 2, llll = 3; llll < ligneMax ; l++, ll++, lll++, llll++)
            {
                /* \ */
                if(grille[cccc][l].joueur == pion       /* \        */
                    &&grille[ccc][ll].joueur == pion    /*   \      */
                    &&grille[cc][lll].joueur == pion    /*     \    */
                    &&grille[c][llll].joueur == pion)   /*       \  */
                {
                    grille[cccc][l].etat = 3;
                    grille[ccc][ll].etat = 3;
                    grille[cc][lll].etat = 3;
                    grille[c][llll].etat = 3;

                    fin = pion;
                }
            }
        }
    }

    return fin;

}

// recupere le nombre de cases vides de chaques colonne
void infosGrille(int mode, int infoGrille[9], caseGrille grille[9][9])
{
	   // reset de infoGrille
   	for(int i = 0; i < 9; i++)
    {
        infoGrille[i] = 0;
    }

     int c, l;

    // nombre de lignes different selon le mode
    if(mode != 3)
        c = 7, l = 6;
    else
        c = 9, l = 8;


    for(int i = 0; i < c; i++)
    {
    	   for(int ii = 0; ii < l; ii++)
        {
            if(grille[i][ii].joueur == 0)// cherche une case vide
            {
            	   infoGrille[i]++;
            }
        }
    }

}

// sauvegarde la grille dans un fichier
void sauvegardeGrille(int tour, int joueur, caseGrille grille[9][9], FILE* fDebug, FILE* fSauvegarde)
{
	   // place le curseur virtuel a la fin du fichier

	   fseek(fSauvegarde, 0, SEEK_CUR);

	   fprintf(fSauvegarde, ":%d %d\n", tour, joueur); // infos de tour

	   for(int i = 7; i > -1; i--)
	   {
	   	  for(int ii = 0; ii < 9; ii++)
	   	  {
	   	  	   // joueur et etat du pion
	   	  	   fprintf(fSauvegarde, " %d/%d", grille[ii][i].joueur, grille[ii][i].etat);
	   	  }

	   	  fputc('\n', fSauvegarde);
	   }

	   fputc('\n', fSauvegarde);

}

// lis un fichier a la recherche d'un tour donne et remplace la grille actuelle par celle sauvegardee
void recupereGrille(int* tour, int* joueur, caseGrille grille[9][9], Images* Images, SDL_Window *pWindow, SDL_Renderer *pRenderer,  FILE* fDebug, FILE* fSauvegarde)
{

        // place le curseur virtuel au debut du fichier
        fseek(fSauvegarde, 0, SEEK_SET);

        int i = 1, securite2 = 0;
        long securite = 0;
        // trouve le bon tour
        while(i)
        {

	      	while(fgetc(fSauvegarde) != ':')
            {
                securite++;
            if(securite > 1000000000)
                fermetureFenetre(Images, pWindow, pRenderer, fDebug, fSauvegarde);
            }


            char aTour[4];
            aTour[0] = ' ';
            aTour[1] = ' ';
            aTour[2] = ' ';
            aTour[3] = '\0';



            for(int ii = 0, c = 0; c != ' '; ii++)
            {
                c = fgetc(fSauvegarde);

                aTour[ii] = c;
            }


            if(atoi(aTour) == (*tour) - 1)
            {
                i = 0;
                (*tour) -= 2;

            }

            securite2++;
            if(securite2 > 100)
                fermetureFenetre(Images, pWindow, pRenderer, fDebug, fSauvegarde);
        }

	   (*joueur) = 0;

	   char chiffre[2];
	    chiffre[0] = ' ';
	     chiffre[1] = '\0';

	   while(*joueur != 1 && *joueur != 2 && *joueur != 3)
	   {
	       chiffre[0] = fgetc(fSauvegarde);
	       *joueur = atoi(chiffre);// recupere les infos de joueur
	   }

	   fgetc(fSauvegarde);// on passe le \n

	   for(int i = 7; i > -1; i--)
	   {
	   	  for(int ii = 0; ii < 9; ii++)
	   	  {

	   	  	   fgetc(fSauvegarde);// ' '
	   	  	   chiffre[0] = fgetc(fSauvegarde);
	   	  	   grille[ii][i].joueur = atoi(chiffre); // joueur auquel appartient la case
	   	  	   fgetc(fSauvegarde);// '/'
	   	  	   chiffre[0] = fgetc(fSauvegarde);
	   	  	   grille[ii][i].etat = atoi(chiffre); // etat de la case
	   	  }

	   	  fgetc(fSauvegarde);// \n
	   }

    fgetc(fSauvegarde);// \n

}
