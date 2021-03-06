/*
Corp de la gestion de la fenetre.
*/

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "debug.h"

#include "video.h"
#include "image.h"

#include "jeu.h"
#include "grille.h"

#include "event.h"



// fenetre

void res_InfoFenetre(InfoFenetre* fenetre){
    fenetre->pWindow = NULL;

    fenetre->pRenderer = NULL;

    fenetre->w = 0;
    fenetre->h = 0;

    fenetre->ecran = NULL;
    fenetre->menu = 0;
    fenetre->parametre = 0;
}


// cree la fenetre et le renderer, fait lien avec le corp du jeu
void fenetre(FILE* fDebug)
{
    int fenetreW = 1920, fenetreH = 1080;

    InfoFenetre fenetre;
    res_InfoFenetre(&fenetre);


    if(SDL_Init(SDL_INIT_VIDEO) != 0){                                                      // initialisation de la partie video de SDL
        fprintf(fDebug,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        exit(-2);
    }
                                                            // creation de la fenetre
    fenetre.pWindow = SDL_CreateWindow("Puissance4 2.0",SDL_WINDOWPOS_UNDEFINED,
                                                SDL_WINDOWPOS_UNDEFINED,
                                                fenetreW,
                                                fenetreH,
                                                SDL_WINDOW_SHOWN);

    if(pWindow){
        fenetre.pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);  // pRenderer
        if(fenetre.pRenderer){
            // clean le renderer
            SDL_SetRenderDrawColor(fenetre.pRenderer, 255, 255, 255, 255);
            SDL_RenderClear(fenetre.pRenderer);
            SDL_RenderPresent(fenetre.pRenderer);
            debugWindow_Affiche();

            SDL_GetRendererOutputSize(fenetre.pRenderer, &fenetre.w, &fenetre.h);

            fonctionJeu(&fenetre, fDebug);  // corp du jeu
        }
        else{
            fprintf(fDebug,"Erreur d'initialisation de pRenderer (%s)",SDL_GetError());
            exit(-4);
        }
    }
    else{
        fprintf(fDebug,"Erreur de création de la fenêtre: %s\n",SDL_GetError());
        exit(-3);
    }
}

// desallocation
void fermetureFenetre(Image* Images, InfoFenetre* fenetre, FILE* fDebug, FILE* fSauvegarde)
{
    res_Image(images); // destuction de toutes les textures pour la fermeture du jeu

    fprintf(fDebug,"Rapport de fin TTF: %s \n", TTF_GetError); // exprime un message d'erreur

    debugWindow_Quit();


    fprintf(fDebug,"Rapport de fin SDL: %s \n", SDL_GetError()); // exprime un message d'erreur

    SDL_DestroyRenderer(fenetre.pRenderer); // desallocation du renderer

    SDL_DestroyWindow(fenetre.pWindow);     // desallocation de la fenetre

    SDL_Quit();                     // arret de SDL

    fclose(fDebug);                 // fermeture du fichier 'fDebug'

    fclose(fSauvegarde);            // fermeture et suppression du fichier 'fSauvegarde'

    exit(0);
}

// image


// charge les images de section du jeu
void chargeSectionImage(Section section, Im_Images* images, SDL_Renderer* pRenderer, FILE* fDebug)
{



        case ACCEUIL:   // chargement des images du menu
            if(images->section_acceuil == 0){
                images->section_acceuil = 1;

                // ACCUEIL
                images->accueil.accueil_bg = chargeImage("./data/accueil/autre/accueil_bg.png", pRenderer, fDebug);
                images->accueil.accueil_retour = chargeImage("./data/accueil/autre/accueil_retour.png", pRenderer, fDebug);
                images->accueil.accueil_valide = chargeImage("./data/accueil/autre/accueil_valide.png", pRenderer, fDebug);

                // 0
                images->accueil.accueil_0.accueil_APPUYEZ_SUR_UNE_TOUCHE_POUR_JOUER = chargeImage("./data/accueil/autre/accueil_APPUYEZ_SUR_UNE_TOUCHE_POUR_JOUER.png", pRenderer, fDebug);

                // 1
                images->accueil.accueil_1.hardcore_inactif = chargeImage("./data/accueil/hardcore/hardcore_inactif.png", pRenderer, fDebug);
                images->accueil.accueil_1.hardcore_1 = chargeImage("./data/accueil/hardcore/hardcore_1.png", pRenderer, fDebug);
                images->accueil.accueil_1.hardcore_2 = chargeImage("./data/accueil/hardcore/hardcore_2.png", pRenderer, fDebug);

                images->accueil.accueil_1.accueil_mode1 = chargeImage("./data/accueil/mode/accueil_mode1.png", pRenderer, fDebug);
                images->accueil.accueil_1.accueil_mode2 = chargeImage("./data/accueil/mode/accueil_mode2.png", pRenderer, fDebug);
                images->accueil.accueil_1.accueil_mode3 = chargeImage("./data/accueil/mode/accueil_mode3.png", pRenderer, fDebug);
                images->accueil.accueil_1.accueil_mode4 = chargeImage("./data/accueil/mode/accueil_mode4.png", pRenderer, fDebug);

                // 2
                images->accueil.accueil_2.accueil_SELECTIONNEZ_UNE_DIFFICULTEE = chargeImage("./data/accueil/bot/SELECTIONNEZ_UNE_DIFFICULTEE.png", pRenderer, fDebug);
                images->accueil.accueil_2.accueil_SELECTIONNEZ_UNE_DIFFICULTEE_efface = chargeImage("./data/accueil/bot/SELECTIONNEZ_UNE_DIFFICULTEE_efface.png", pRenderer, fDebug);

                images->accueil.accueil_2.accueil_botJaune = chargeImage("./data/accueil/bot/accueil_botJaune.png", pRenderer, fDebug);
                images->accueil.accueil_2.accueil_botRouge = chargeImage("./data/accueil/bot/accueil_botRouge.png", pRenderer, fDebug);
                images->accueil.accueil_2.accueil_bot_inactif = chargeImage("./data/accueil/bot/accueil_bot_inactif.png", pRenderer, fDebug);

                images->accueil.accueil_2.accueil_botFacile_actif = chargeImage("./data/accueil/bot/accueil_botFacile_actif.png", pRenderer, fDebug);
                images->accueil.accueil_2.accueil_botNormal_actif = chargeImage("./data/accueil/bot/accueil_botNormal_actif.png", pRenderer, fDebug);
                images->accueil.accueil_2.accueil_botDifficile_actif = chargeImage("./data/accueil/bot/accueil_botDifficile_actif.png", pRenderer, fDebug);

                images->accueil.accueil_2.accueil_botFacile_inactif = chargeImage("./data/accueil/bot/accueil_botFacile_inactif.png", pRenderer, fDebug);
                images->accueil.accueil_2.accueil_botNormal_inactif = chargeImage("./data/accueil/bot/accueil_botNormal_inactif.png", pRenderer, fDebug);
                images->accueil.accueil_2.accueil_botDifficile_inactif = chargeImage("./data/accueil/bot/accueil_botDifficile_inactif.png", pRenderer, fDebug);
            }
            if(image->section_jeu){ //si les images du jeu sont charge alors que le programme est dans la section de l'accueil alors on les supprimes
                images->section_jeu = 0;

                // MENU
                supprimeTexture(images->menu.menu_logo);

                supprimeTexture(images->menu.grillage.menu_grillage);
                supprimeTexture(images->menu.grillage.menu_grillage1);
                supprimeTexture(images->menu.grillage.menu_grillage2);
                supprimeTexture(images->menu.grillage.menu_Borduregrillage);

                supprimeTexture(images->menu.bouton.menu_Reprendre);
                supprimeTexture(images->menu.bouton.menu_Rejouer);
                supprimeTexture(images->menu.bouton.menu_RetourAccueil);
                supprimeTexture(images->menu.bouton.menu_Quitter);

                // JEU
                supprimeTexture(images->jeu.jeu_bg);
                supprimeTexture(images->jeu.jeu_retour);
                // joueur
                supprimeTexture(images->jeu.joueur.joueur1);
                supprimeTexture(images->jeu.joueur.joueur2);
                supprimeTexture(images->jeu.joueur.joueur3);
                supprimeTexture(images->jeu.joueur.bot1);
                supprimeTexture(images->jeu.joueur.bot2);

                supprimeTexture(images->jeu.joueur.joueur1_actif);
                supprimeTexture(images->jeu.joueur.joueur2_actif);
                supprimeTexture(images->jeu.joueur.joueur3_actif);
                supprimeTexture(images->jeu.joueur.bot1_actif);
                supprimeTexture(images->jeu.joueur.bot2_actif);

                // grille
                supprimeTexture(images->jeu.grille.grille7x6);
                supprimeTexture(images->jeu.grille.grille9x8);

                // hardcore
                supprimeTexture(images->jeu.hardcore.hardcore_bg);

                supprimeTexture(images->jeu.hardcore.hardcore_Temps_Vert);
                supprimeTexture(images->jeu.hardcore.hardcore_Temps_Orange);
                supprimeTexture(images->jeu.hardcore.hardcore_Temps_Rouge);

                // colonne
                supprimeTexture(images->jeu.colonne.jeu_colonne_Desactive);

                supprimeTexture(images->jeu.colonne.jeu_colonneTaille1_Active);
                supprimeTexture(images->jeu.colonne.jeu_colonneTaille2_Active);
                supprimeTexture(images->jeu.colonne.jeu_colonneTaille3_Active);
                supprimeTexture(images->jeu.colonne.jeu_colonneTaille4_Active);
                supprimeTexture(images->jeu.colonne.jeu_colonneTaille5_Active);
                supprimeTexture(images->jeu.colonne.jeu_colonneTaille6_Active);
                supprimeTexture(images->jeu.colonne.jeu_colonneTaille7_Active);
                supprimeTexture(images->jeu.colonne.jeu_colonneTaille8_Active);

                // pions
                supprimeTexture(images->jeu.pions.pion1);
                supprimeTexture(images->jeu.pions.pion2);
                supprimeTexture(images->jeu.pions.pion3);

                supprimeTexture(images->jeu.pions.pion1_joue);
                supprimeTexture(images->jeu.pions.pion2_joue);
                supprimeTexture(images->jeu.pions.pion3_joue);

                supprimeTexture(images->jeu.pions.pion1_gagne);
                supprimeTexture(images->jeu.pions.pion2_gagne);
                supprimeTexture(images->jeu.pions.pion3_gagne);


                // FIN
                supprimeTexture(images->fin.fin_LE_JOUEUR);
                supprimeTexture(images->fin.fin_GAGNE);
                supprimeTexture(images->fin.fin_EGALITE);



        //


                /*// MENU

                images->menu.menu_logo = NULL;

                images->menu.grillage.menu_grillage = NULL;
                images->menu.grillage.menu_grillage1 = NULL;
                images->menu.grillage.menu_grillage2 = NULL;
                images->menu.grillage.menu_Borduregrillage = NULL;

                images->menu.bouton.menu_Reprendre = NULL;
                images->menu.bouton.menu_Rejouer = NULL;
                images->menu.bouton.menu_RetourAccueil = NULL;
                images->menu.bouton.menu_Quitter = NULL;



                // JEU
                images->jeu.jeu_bg = NULL;
                images->jeu.jeu_retour = NULL;

                // joueur
                images->jeu.joueur.joueur1 = NULL;
                images->jeu.joueur.joueur2 = NULL;
                images->jeu.joueur.joueur3 = NULL;
                images->jeu.joueur.bot1 = NULL;
                images->jeu.joueur.bot2 = NULL;

                images->jeu.joueur.joueur1_actif = NULL;
                images->jeu.joueur.joueur2_actif = NULL;
                images->jeu.joueur.joueur3_actif = NULL;
                images->jeu.joueur.bot1_actif = NULL;
                images->jeu.joueur.bot2_actif = NULL;

                // grille
                images->jeu.Grille.grille7x6 = NULL;
                images->jeu.Grille.grille9x8 = NULL;

                // hardcore
                images->jeu.hardcore.hardcore_bg = NULL;

                images->jeu.hardcore.hardcore_Temps_Vert = NULL;
                images->jeu.hardcore.hardcore_Temps_Orange = NULL;
                images->jeu.hardcore.hardcore_Temps_Rouge = NULL;

                // colonne
                images->jeu.colonne.jeu_colonne_Desactive = NULL;

                images->jeu.colonne.jeu_colonneTaille1_Active = NULL;
                images->jeu.colonne.jeu_colonneTaille2_Active = NULL;
                images->jeu.colonne.jeu_colonneTaille3_Active = NULL;
                images->jeu.colonne.jeu_colonneTaille4_Active = NULL;
                images->jeu.colonne.jeu_colonneTaille5_Active = NULL;
                images->jeu.colonne.jeu_colonneTaille6_Active = NULL;
                images->jeu.colonne.jeu_colonneTaille7_Active = NULL;
                images->jeu.colonne.jeu_colonneTaille8_Active = NULL;

                // pions
                images->jeu.pions.pion1 = NULL;
                images->jeu.pions.pion2 = NULL;
                images->jeu.pions.pion3 = NULL;

                images->jeu.pions.pion1_joue = NULL;
                images->jeu.pions.pion2_joue = NULL;
                images->jeu.pions.pion3_joue = NULL;

                images->jeu.pions.pion1_gagne = NULL;
                images->jeu.pions.pion2_gagne = NULL;
                images->jeu.pions.pion3_gagne = NULL;

                // FIN
                images->fin.fin_LE_JOUEUR = NULL;
                images->fin.fin_GAGNE = NULL;
                images->fin.fin_EGALITE = NULL;*/
            }
            break;

        case JEU:   // chargement des images du jeu
            if(image->section_jeu == 0){
                images->section_jeu = 1;

                // MENU
                images->menu.menu_logo = chargeImage("./data/menu/autre/menu_logo.png", pRenderer, fDebug);

                images->menu.grillage.menu_grillage = chargeImage("./data/menu/grillage/menu_grillage.png", pRenderer, fDebug);
                images->menu.grillage.menu_grillage1 = chargeImage("./data/menu/grillage/menu_grillage1.png", pRenderer, fDebug);
                images->menu.grillage.menu_grillage2 = chargeImage("./data/menu/grillage/menu_grillage2.png", pRenderer, fDebug);
                images->menu.grillage.menu_Borduregrillage = chargeImage("./data/menu/grillage/menu_Borduregrillage.png", pRenderer, fDebug);

                images->menu.bouton.menu_Reprendre = chargeImage("./data/menu/bouton/menu_Reprendre.png", pRenderer, fDebug);
                images->menu.bouton.menu_Rejouer = chargeImage("./data/menu/bouton/menu_Rejouer.png", pRenderer, fDebug);
                images->menu.bouton.menu_RetourAccueil = chargeImage("./data/menu/bouton/menu_RetourAccueil.png", pRenderer, fDebug);
                images->menu.bouton.menu_Quitter = chargeImage("./data/menu/bouton/menu_Quitter.png", pRenderer, fDebug);

                // JEU
                images->jeu.jeu_bg = chargeImage("./data/jeu/autre/jeu_bg.png", pRenderer, fDebug);
                images->jeu.jeu_retour = chargeImage("./data/jeu/autre/jeu_retour.png", pRenderer, fDebug);

                // joueur
                images->jeu.joueur.joueur1 = chargeImage("./data/jeu/joueur/joueur1.png", pRenderer, fDebug);
                images->jeu.joueur.joueur2 = chargeImage("./data/jeu/joueur/joueur2.png", pRenderer, fDebug);
                images->jeu.joueur.joueur3 = chargeImage("./data/jeu/joueur/joueur3.png", pRenderer, fDebug);
                images->jeu.joueur.bot1 = chargeImage("./data/jeu/joueur/bot1.png", pRenderer, fDebug);
                images->jeu.joueur.bot2 = chargeImage("./data/jeu/joueur/bot2.png", pRenderer, fDebug);

                images->jeu.joueur.joueur1_actif = chargeImage("./data/jeu/joueur/joueur1_actif.png", pRenderer, fDebug);
                images->jeu.joueur.joueur2_actif = chargeImage("./data/jeu/joueur/joueur2_actif.png", pRenderer, fDebug);
                images->jeu.joueur.joueur3_actif = chargeImage("./data/jeu/joueur/joueur3_actif.png", pRenderer, fDebug);
                images->jeu.joueur.bot1_actif = chargeImage("./data/jeu/joueur/bot1_actif.png", pRenderer, fDebug);
                images->jeu.joueur.bot2_actif = chargeImage("./data/jeu/joueur/bot2_actif.png", pRenderer, fDebug);

                // grille
                images->jeu.grille.grille7x6 = chargeImage("./data/jeu/grille/grille7x6.png", pRenderer, fDebug);
                images->jeu.grille.grille9x8 = chargeImage("./data/jeu/grille/grille9x8.png", pRenderer, fDebug);

                // hardcore
                images->jeu.hardcore.hardcore_bg = chargeImage("./data/jeu/hardcore/hardcore_bg.png", pRenderer, fDebug);

                images->jeu.hardcore.hardcore_Temps_Vert = chargeImage("./data/jeu/hardcore/hardcore_Temps_Vert.png", pRenderer, fDebug);
                images->jeu.hardcore.hardcore_Temps_Orange = chargeImage("./data/jeu/hardcore/hardcore_Temps_Orange.png", pRenderer, fDebug);
                images->jeu.hardcore.hardcore_Temps_Rouge = chargeImage("./data/jeu/hardcore/hardcore_Temps_Rouge.png", pRenderer, fDebug);

                // colonne
                images->jeu.colonne.jeu_colonne_Desactive = chargeImage("./data/jeu/colonne/jeu_colonne_Desactive.png", pRenderer, fDebug);

                images->jeu.colonne.jeu_colonneTaille1_Active = chargeImage("./data/jeu/colonne/jeu_colonneTaille1_Active.png", pRenderer, fDebug);
                images->jeu.colonne.jeu_colonneTaille2_Active = chargeImage("./data/jeu/colonne/jeu_colonneTaille2_Active.png", pRenderer, fDebug);
                images->jeu.colonne.jeu_colonneTaille3_Active = chargeImage("./data/jeu/colonne/jeu_colonneTaille3_Active.png", pRenderer, fDebug);
                images->jeu.colonne.jeu_colonneTaille4_Active = chargeImage("./data/jeu/colonne/jeu_colonneTaille4_Active.png", pRenderer, fDebug);
                images->jeu.colonne.jeu_colonneTaille5_Active = chargeImage("./data/jeu/colonne/jeu_colonneTaille5_Active.png", pRenderer, fDebug);
                images->jeu.colonne.jeu_colonneTaille6_Active = chargeImage("./data/jeu/colonne/jeu_colonneTaille6_Active.png", pRenderer, fDebug);
                images->jeu.colonne.jeu_colonneTaille7_Active = chargeImage("./data/jeu/colonne/jeu_colonneTaille7_Active.png", pRenderer, fDebug);
                images->jeu.colonne.jeu_colonneTaille8_Active = chargeImage("./data/jeu/colonne/jeu_colonneTaille8_Active.png", pRenderer, fDebug);

                // pion
                images->jeu.pions.pion1 = chargeImage("./data/jeu/pion/pion1.png", pRenderer, fDebug);
                images->jeu.pions.pion2 = chargeImage("./data/jeu/pion/pion2.png", pRenderer, fDebug);
                images->jeu.pions.pion3 = chargeImage("./data/jeu/pion/pion3.png", pRenderer, fDebug);

                images->jeu.pions.pion1_joue = chargeImage("./data/jeu/pion/pion1_joue.png", pRenderer, fDebug);
                images->jeu.pions.pion2_joue = chargeImage("./data/jeu/pion/pion2_joue.png", pRenderer, fDebug);
                images->jeu.pions.pion3_joue = chargeImage("./data/jeu/pion/pion3_joue.png", pRenderer, fDebug);

                images->jeu.pions.pion1_gagne = chargeImage("./data/jeu/pion/pion1_gagne.png", pRenderer, fDebug);
                images->jeu.pions.pion2_gagne = chargeImage("./data/jeu/pion/pion2_gagne.png", pRenderer, fDebug);
                images->jeu.pions.pion3_gagne = chargeImage("./data/jeu/pion/pion3_gagne.png", pRenderer, fDebug);


                // FIN
                images->fin.fin_LE_JOUEUR = chargeImage("./data/fin/texte/fin_LE_JOUEUR.png", pRenderer, fDebug);
                images->fin.fin_GAGNE = chargeImage("./data/fin/texte/fin_GAGNE.png", pRenderer, fDebug);
                images->fin.fin_EGALITE = chargeImage("./data/fin/texte/fin_EGALITE.png", pRenderer, fDebug);
            }
            if(images->section_acceuil){    // si les images de l'acceuil sont charge alors que le programme est dans la section du jeu alors on les supprimes
                images->section_acceuil = 0;

                // ACCUEIL
                supprimeTexture(images->accueil.accueil_bg);
                supprimeTexture(images->accueil.accueil_retour);
                supprimeTexture(images->accueil.accueil_valide);

                // 0
                supprimeTexture(images->accueil.accueil_0.accueil_APPUYEZ_SUR_UNE_TOUCHE_POUR_JOUER);
                supprimeTexture(images->accueil.accueil_0.accueil_jouer);

                // 1
                supprimeTexture(images->accueil.accueil_1.hardcore_inactif);
                supprimeTexture(images->accueil.accueil_1.hardcore_1);
                supprimeTexture(images->accueil.accueil_1.hardcore_2);

                supprimeTexture(images->accueil.accueil_1.accueil_mode1);
                supprimeTexture(images->accueil.accueil_1.accueil_mode2);
                supprimeTexture(images->accueil.accueil_1.accueil_mode3);
                supprimeTexture(images->accueil.accueil_1.accueil_mode4);

                // 2
                supprimeTexture(images->accueil.accueil_2.accueil_SELECTIONNEZ_UNE_DIFFICULTEE);
                supprimeTexture(images->accueil.accueil_2.accueil_SELECTIONNEZ_UNE_DIFFICULTEE_efface);

                supprimeTexture(images->accueil.accueil_2.accueil_botJaune);
                supprimeTexture(images->accueil.accueil_2.accueil_botRouge);
                supprimeTexture(images->accueil.accueil_2.accueil_bot_inactif);

                supprimeTexture(images->accueil.accueil_2.accueil_botFacile_actif);
                supprimeTexture(images->accueil.accueil_2.accueil_botNormal_actif);
                supprimeTexture(images->accueil.accueil_2.accueil_botDifficile_actif);

                supprimeTexture(images->accueil.accueil_2.accueil_botFacile_inactif);
                supprimeTexture(images->accueil.accueil_2.accueil_botNormal_inactif);
                supprimeTexture(images->accueil.accueil_2.accueil_botDifficile_inactif);


                /*// ACCUEIL
                images->accueil.accueil_bg = NULL;
                images->accueil.accueil_retour = NULL;
                images->accueil.accueil_valide = NULL;

                // 0
                images->accueil.accueil_0.accueil_APPUYEZ_SUR_UNE_TOUCHE_POUR_JOUER = NULL;
                images->accueil.accueil_0.accueil_jouer = NULL;

                // 1
                images->accueil.accueil_1.hardcore_inactif = NULL;
                images->accueil.accueil_1.hardcore_1 = NULL;
                images->accueil.accueil_1.hardcore_2 = NULL;

                images->accueil.accueil_1.accueil_mode1 = NULL;
                images->accueil.accueil_1.accueil_mode2 = NULL;
                images->accueil.accueil_1.accueil_mode3 = NULL;
                images->accueil.accueil_1.accueil_mode4 = NULL;

                // 2
                images->accueil.accueil_2.accueil_SELECTIONNEZ_UNE_DIFFICULTEE = NULL;
                images->accueil.accueil_2.accueil_SELECTIONNEZ_UNE_DIFFICULTEE_efface = NULL;

                images->accueil.accueil_2.accueil_botJaune = NULL;
                images->accueil.accueil_2.accueil_botRouge = NULL;
                images->accueil.accueil_2.accueil_bot_inactif = NULL;

                images->accueil.accueil_2.accueil_botFacile_actif = NULL;
                images->accueil.accueil_2.accueil_botNormal_actif = NULL;
                images->accueil.accueil_2.accueil_botDifficile_actif = NULL;

                images->accueil.accueil_2.accueil_botFacile_inactif = NULL;
                images->accueil.accueil_2.accueil_botNormal_inactif = NULL;
                images->accueil.accueil_2.accueil_botDifficile_inactif = NULL;*/
            }
            break;
    }
}


// action

void affichage(Im_Images* images, InfoJeu* jeu, InfoFenetre* fenetre, FILE* fDebug){

    if(fenetre->ecran == CHARGEMENT){
        if(images->autre.CHARGEMENT == NULL){
            chargeImage(images->autre.CHARGEMENT)
        }
    }
    else if(images->section_autre == 0){
        chargeSectionImage(AUTRE, images, fenetre->pRenderer, fDebug);
    }

    switch(fenetre->ecran){
        case CHARGEMENT:{
            afficheImage(images->autre.CHARGEMENT, [0, 0], NON, fenetre->pRenderer, fDebug);
            break;
        }

        case LENCEMENT:{
            if(images->section_acceuil == 0){
                chargeSectionImage(CHARGEMENT, images, fenetre->pRenderer, fDebug);
            }

            /*j'en suis ici, il faut faire l'affichage du premier ecran, avec la phrase qui clignote, donc utiliser le temps pour
            l'animation, donc refaire le sisteme d'image.*/

            break;
        }

        case ACCUEIL_MENU:{
            if(images->section_acceuil == 0){
                chargeSectionImage(CHARGEMENT, images, fenetre->pRenderer, fDebug);
            }
            break;
        }

        case ACCUEIL_BOT:{
            if(images->section_acceuil == 0){
                chargeSectionImage(CHARGEMENT, images, fenetre->pRenderer, fDebug);
            }
            break;
        }

        case JEU:{
            if(images->section_acceuil == 0){
                chargeSectionImage(JEU, images, fenetre->pRenderer, fDebug);
            }
            break;
        }
    }


}


// affiche les parametres
void parametre(infoJeu* jeu, Im_Images* images, SDL_Window* pWindow, SDL_Renderer* pRenderer, FILE* fDebug, FILE* fSauvegarde)
{
    // taille du renderer
    int x = 0, y = 0;
    SDL_GetRendererOutputSize(pRenderer, &x, &y);

    afficheImage(images->Parametre.parametre_bg, [x/2, 9*y/16], OUI, pRenderer, fDebug);

    // joueur commence
    afficheImage(images->parametre.joueurCommence.joueurCommence_bg, [x/2 - 360, 9*y/16], OUI, pRenderer, fDebug);

    afficheImage(images->parametre.joueurCommence.joueur1Commence, [x/2 - 360, 9*y/16 - 97.5], OUI, pRenderer, fDebug);
    afficheImage(images->parametre.joueurCommence.joueur2Commence, [x/2 - 360, 9*y/16 + 26.5], OUI, pRenderer, fDebug);
    afficheImage(images->parametre.joueurCommence.joueur3Commence, [x/2 - 360, 9*y/16 + 151.5], OUI, pRenderer, fDebug);

    switch(jeu->joueurCommence){
        case 1:
            afficheImage(images->parametre.joueurCommence.joueur1Commence_actif, [x/2 - 360, 9*y/16 - 97.5], OUI, pRenderer, fDebug);
            break;
        case 2:
            afficheImage(images->parametre.joueurCommence.joueur2Commence_actif, [x/2 - 360, 9*y/16 + 26.5], OUI, pRenderer, fDebug);
            break;
        case 3:
            afficheImage(images->parametre.joueurCommence.joueur3Commence_actif, [x/2 - 360, 9*y/16 + 151.5], OUI, pRenderer, fDebug);
            break;
    }
}

// affiche les accueils et fait intervenir les evenements lié
void accueil(int accueil, int* mode, int* joueurCommence, int* difficulteBot1, int* difficulteBot2, Hardcore* hardcore, Images* Images, SDL_Window* pWindow, SDL_Renderer* pRenderer, FILE* fDebug, FILE* fSauvegarde)
{
                          /*accueil = id de l'accueil:
                                    -1: hors de l'accueil
                                     0: ecran de bienvenue
                                     1: choix des modes
                                     2: choix de la difficulte des bots
                                     */
    while(accueil != -1)
    {
        int frame = 0; // permet de faire l'animation de clignotement

        SDL_Rect dest;

        while(accueil == 0)// ecran d'accueil
        {



            eventAccueil_0(&accueil, Images, pWindow, pRenderer, fDebug, fSauvegarde);

            // taille du renderer
            int x = 0, y = 0;
            SDL_GetRendererOutputSize(pRenderer, &x, &y);

            {   // affichage de l'accueil 0
                changeDest(&dest, 0, 0);
                afficheImage(Images->Accueil.accueil_bg, &dest, pRenderer, fDebug);

                changeDest(&dest, x-50, 0);
                afficheImage(Images->Autre.croix, &dest, pRenderer, fDebug);

                // animation de l'image en 59 fps
                if(0 <= frame && frame <= 39 )
                {
                    changeDest(&dest, x/2, 3*y/4);
                    afficheImage_Centre(Images->Accueil.Accueil_0.accueil_APPUYEZ_SUR_UNE_TOUCHE_POUR_JOUER, &dest, pRenderer, fDebug);

                }
                else if(40 <= frame && frame <= 79);
                else
                {
                    frame = 0;
                }


                SDL_RenderPresent(pRenderer);
                debugWindow_Affiche();

                SDL_Delay(17);// = 0.017 s
                frame++;
            }

        }

        while(accueil == 1)// selection modes de jeu
        {
            *difficulteBot1 = 0;
            *difficulteBot2 = 0;
            *mode = 0;

            while(eventAccueil_1(&accueil, mode, joueurCommence, hardcore, Images, pWindow, pRenderer, fDebug, fSauvegarde))
            {
                // taille du renderer
                int x = 0, y = 0;
                SDL_GetRendererOutputSize(pRenderer, &x, &y);

                {   // affichage de l'accueil 1
                    changeDest(&dest, 0, 0);
                    afficheImage(Images->Accueil.accueil_bg, &dest, pRenderer, fDebug);

                    changeDest(&dest, 75, 75);
                    afficheImage_Centre(Images->Parametre.parametre_logo, &dest, pRenderer, fDebug);

                    changeDest(&dest, x-50, 0);
                    afficheImage(Images->Autre.croix, &dest, pRenderer, fDebug);

                    changeDest(&dest, 7*x/8, 3*y/8);
                    switch(hardcore->mode)
                    {
                    	   case 0:
                    	       afficheImage_Centre(Images->Accueil.Accueil_1.hardcore_inactif, &dest, pRenderer, fDebug);
                    	   break;

                    	   case 1:
                    	       afficheImage_Centre(Images->Accueil.Accueil_1.hardcore_1, &dest, pRenderer, fDebug);
                    	   break;

                    	   case 2:
                    	       afficheImage_Centre(Images->Accueil.Accueil_1.hardcore_2, &dest, pRenderer, fDebug);
                    	   break;
                    }

                    changeDest(&dest, 5*x/16, y/2);
                    afficheImage_Centre(Images->Accueil.Accueil_1.accueil_mode1, &dest, pRenderer, fDebug); // PvP
                    changeDest(&dest, 5*x/16, 3*y/4);
                    afficheImage_Centre(Images->Accueil.Accueil_1.accueil_mode3, &dest, pRenderer, fDebug); // PvE
                    changeDest(&dest, 11*x/16, y/2);
                    afficheImage_Centre(Images->Accueil.Accueil_1.accueil_mode2, &dest, pRenderer, fDebug); // PvPvP
                    changeDest(&dest, 11*x/16, 3*y/4);
                    afficheImage_Centre(Images->Accueil.Accueil_1.accueil_mode4, &dest, pRenderer, fDebug); // EvE


                    SDL_RenderPresent(pRenderer);
                    debugWindow_Affiche();
                }
            }

            while(accueil == 2)// selecton difficulte bots
            {

                int frame = 0, frameFin = 0;
                int pasValide = 0;


                while(eventAccueil_2(&accueil, mode, joueurCommence, difficulteBot1, difficulteBot2, &pasValide, Images, pWindow, pRenderer, fDebug, fSauvegarde))
                {
                    frame ++;

                    // taille du renderer
                    int x = 0, y = 0;
                    SDL_GetRendererOutputSize(pRenderer, &x, &y);

                    {    // affichage de l'accueil 2
                        changeDest(&dest, 0, 0);
                        afficheImage(Images->Accueil.accueil_bg, &dest, pRenderer, fDebug);

                        changeDest(&dest, x/16, 7*y/8);
                        afficheImage_Centre(Images->Accueil.accueil_retour, &dest, pRenderer, fDebug);

                        changeDest(&dest, 29*x/32, y/2);
                        afficheImage_Centre(Images->Accueil.accueil_valide, &dest, pRenderer, fDebug);

                        changeDest(&dest, 75, 75);
                        afficheImage_Centre(Images->Parametre.parametre_logo, &dest, pRenderer, fDebug);

                        changeDest(&dest, x-50, 0);
                        afficheImage(Images->Autre.croix, &dest, pRenderer, fDebug);


                        // la selection de la difficulte du bot 2 est active selon le mode
                        if(*mode == 2)
                        {
                            changeDest(&dest, x/2, 10*y/16);
                            afficheImage_Centre(Images->Accueil.Accueil_2.accueil_botRouge, &dest, pRenderer, fDebug);

                            changeDest(&dest, x/2, 7*y/16);
                            afficheImage_Centre(Images->Accueil.Accueil_2.accueil_botFacile_inactif, &dest, pRenderer, fDebug);
                            changeDest(&dest, x/2, 10*y/16);
                            afficheImage_Centre(Images->Accueil.Accueil_2.accueil_botNormal_inactif, &dest, pRenderer, fDebug);
                            changeDest(&dest, x/2, 13*y/16);
                            afficheImage_Centre(Images->Accueil.Accueil_2.accueil_botDifficile_inactif, &dest, pRenderer, fDebug);

                            switch (*difficulteBot1)// la difficulte selectionne s'active
                            {
                                case 1:
                                    changeDest(&dest, x/2, 7*y/16);
                                    afficheImage_Centre(Images->Accueil.Accueil_2.accueil_botFacile_actif, &dest, pRenderer, fDebug);
                                break;

                                case 2:
                                    changeDest(&dest, x/2, 10*y/16);
                                    afficheImage_Centre(Images->Accueil.Accueil_2.accueil_botNormal_actif, &dest, pRenderer, fDebug);
                                break;

                                case 3:
                                    changeDest(&dest, x/2, 13*y/16);
                                    afficheImage_Centre(Images->Accueil.Accueil_2.accueil_botDifficile_actif, &dest, pRenderer, fDebug);
                                break;
                            }
                        }
                        else if(*mode == 4)
                        {
                            changeDest(&dest, 5*x/16, 10*y/16);
                            afficheImage_Centre(Images->Accueil.Accueil_2.accueil_botJaune, &dest, pRenderer, fDebug);

                            changeDest(&dest, 11*x/16, 10*y/16);
                            afficheImage_Centre(Images->Accueil.Accueil_2.accueil_botRouge, &dest, pRenderer, fDebug);

                            // bot 1

                            changeDest(&dest, 5*x/16, 7*y/16);
                            afficheImage_Centre(Images->Accueil.Accueil_2.accueil_botFacile_inactif, &dest, pRenderer, fDebug);
                            changeDest(&dest, 5*x/16, 10*y/16);
                            afficheImage_Centre(Images->Accueil.Accueil_2.accueil_botNormal_inactif, &dest, pRenderer, fDebug);
                            changeDest(&dest, 5*x/16, 13*y/16);
                            afficheImage_Centre(Images->Accueil.Accueil_2.accueil_botDifficile_inactif, &dest, pRenderer, fDebug);

                            switch (*difficulteBot1)// la difficulte selectionne s'active
                            {
                                case 1:
                                    changeDest(&dest, 5*x/16, 7*y/16);
                                    afficheImage_Centre(Images->Accueil.Accueil_2.accueil_botFacile_actif, &dest, pRenderer, fDebug);
                                break;

                                case 2:
                                    changeDest(&dest, 5*x/16, 10*y/16);
                                    afficheImage_Centre(Images->Accueil.Accueil_2.accueil_botNormal_actif, &dest, pRenderer, fDebug);
                                break;

                                case 3:
                                    changeDest(&dest, 5*x/16, 13*y/16);
                                    afficheImage_Centre(Images->Accueil.Accueil_2.accueil_botDifficile_actif, &dest, pRenderer, fDebug);
                                break;
                            }


                            // bot 2
                            changeDest(&dest, 11*x/16, 7*y/16);
                            afficheImage_Centre(Images->Accueil.Accueil_2.accueil_botFacile_inactif, &dest, pRenderer, fDebug);
                            changeDest(&dest, 11*x/16, 10*y/16);
                            afficheImage_Centre(Images->Accueil.Accueil_2.accueil_botNormal_inactif, &dest, pRenderer, fDebug);
                            changeDest(&dest, 11*x/16, 13*y/16);
                            afficheImage_Centre(Images->Accueil.Accueil_2.accueil_botDifficile_inactif, &dest, pRenderer, fDebug);

                            switch (*difficulteBot2)// la difficulte selectionne s'active
                            {
                                case 1:
                                    changeDest(&dest, 11*x/16, 7*y/16);
                                    afficheImage_Centre(Images->Accueil.Accueil_2.accueil_botFacile_actif, &dest, pRenderer, fDebug);
                                break;

                                case 2:
                                    changeDest(&dest, 11*x/16, 10*y/16);
                                    afficheImage_Centre(Images->Accueil.Accueil_2.accueil_botNormal_actif, &dest, pRenderer, fDebug);
                                break;

                                case 3:
                                    changeDest(&dest, 11*x/16, 13*y/16);
                                    afficheImage_Centre(Images->Accueil.Accueil_2.accueil_botDifficile_actif, &dest, pRenderer, fDebug);
                                break;
                            }
                        }

                        if (pasValide)
                        {
                            frameFin = frame + 80;
                        }

                        if(frameFin)
                        {
                            if(frame <= (frameFin - 20))
                            {
                                changeDest(&dest, x/2, 15*y/64);
                                afficheImage_Centre(Images->Accueil.Accueil_2.accueil_SELECTIONNEZ_UNE_DIFFICULTEE, &dest, pRenderer, fDebug);
                            }
                            else if(frame <= frameFin)
                            {
                                changeDest(&dest, x/2, 15*y/64);
                                afficheImage_Centre(Images->Accueil.Accueil_2.accueil_SELECTIONNEZ_UNE_DIFFICULTEE_efface, &dest, pRenderer, fDebug);
                            }
                            else
                                frameFin = 0;
                        }


                        SDL_Delay(17);

                        SDL_RenderPresent(pRenderer);
                        debugWindow_Affiche();
                    }

                    pasValide = 0;
                }
            }
        }
    }
}

// permet de jouer une colonne, affiche les images et fait intervenir les evenements liés
void jouerColonne(int mode, int* joueurCommence, int tour, int joueur, caseGrille grille[9][9], Hardcore* hardcore, int* colonne, int* retour, int* rejouerPartie, int* retourAccueil, Images* Images, SDL_Window*  pWindow, SDL_Renderer* pRenderer, FILE* fDebug, FILE* fSauvegarde)
{

    int colonneActive = -1;// colonne que la souris survole
    int infoGrille[9] = {0};// permet de connaitre le nombre de pions restant dans chaques colonne
    int frame = 0;// permet de gerer le temps

    infosGrille(mode, infoGrille, grille);

    while(*colonne == -1 && *retour == 0 && *rejouerPartie == 0 && *retourAccueil == 0)
    {
        // taille du renderer
        int x = 0, y = 0;
        SDL_GetRendererOutputSize(pRenderer, &x, &y);

        SDL_Rect dest;

        eventJouer(mode, joueurCommence, joueur, tour, &colonneActive, colonne, retour, rejouerPartie, retourAccueil, infoGrille, hardcore, grille, Images, pWindow, pRenderer, fDebug, fSauvegarde);// choix de la colonne, survol d'une colonne

        affiche(0, mode, joueur, tour, colonneActive, grille, Images, pRenderer, fDebug);// affiche le jeu

        changeDest(&dest, 75, 75);
        afficheImage_Centre(Images->Menu.menu_logo, &dest, pRenderer, fDebug);// logo du menu

        afficheHardcore(hardcore, Images, pRenderer, fDebug);

        changeDest(&dest, x-50, 0);
        afficheImage(Images->Autre.croix, &dest, pRenderer, fDebug);


        SDL_RenderPresent(pRenderer);
        debugWindow_Affiche();

        SDL_Delay(17);

        frame++;

        if(hardcore->mode != 0)
        {


            if(frame == 59)// ~1 seconde
            {
                frame = 0;
                hardcore->tempsRestant--; // diminue toutes les secondes
            }

            // si le joueur ne joue pas a temps, son pion est place aleatoirement
            if(hardcore->tempsRestant == 0)
            {
                do
                {
                    if(mode != 3)
                    {
                        *colonne = (rand() % 7);// renvoi un nombre aleatoire (0 - 6)
                    }
                    else
                    {
                        *colonne = (rand() % 9);// renvoi un nombre aleatoire (0 - 8)
                    }

                }while(*colonne == -1 || infoGrille[*colonne] == 0);


            }
        }
    }
}

// (en cour de partie) permet de recommencer une partie/ retourner a l'accueil/ reprendre une partie/ quitter le jeu
void menu(int* rejouerPartie, int* retourAccueil, Hardcore* hardcore, int mode, int joueur, int tour, int* joueurCommence, caseGrille grille[9][9], Images* Images, SDL_Window*  pWindow, SDL_Renderer* pRenderer, FILE* fDebug, FILE* fSauvegarde)
{

   animationGrillage(-1, NULL, mode, joueur, tour, hardcore, grille, Images, pWindow, pRenderer, fDebug, fSauvegarde);

   while(eventMenu(mode, joueurCommence, rejouerPartie, retourAccueil, Images, pWindow, pRenderer, fDebug, fSauvegarde))
   {
        // taille du renderer
        int x = 0, y = 0;
        SDL_GetRendererOutputSize(pRenderer, &x, &y);

        {// affichage du menu

            SDL_Rect dest;

            affiche(0, mode, joueur, tour, -1, grille, Images, pRenderer, fDebug);

            changeDest(&dest, 0, 0);
            afficheImage(Images->Menu.Grillage.menu_Grillage, &dest, pRenderer, fDebug);

            changeDest(&dest, 75, 75);
            afficheImage_Centre(Images->Parametre.parametre_logo, &dest, pRenderer, fDebug);

            changeDest(&dest, x-50, 0);
            afficheImage(Images->Autre.croix, &dest, pRenderer, fDebug);

            changeDest(&dest, x/2, 2*y/16);
            afficheImage_Centre(Images->Menu.Bouton.menu_Reprendre, &dest, pRenderer, fDebug);

            changeDest(&dest, x/2, 6*y/16);
            afficheImage_Centre(Images->Menu.Bouton.menu_Rejouer, &dest, pRenderer, fDebug);

            changeDest(&dest, x/2, 10*y/16);
            afficheImage_Centre(Images->Menu.Bouton.menu_RetourAccueil, &dest, pRenderer, fDebug);

            changeDest(&dest, x/2, 14*y/16);
            afficheImage_Centre(Images->Menu.Bouton.menu_Quitter, &dest, pRenderer, fDebug);

            SDL_RenderPresent(pRenderer);
            debugWindow_Affiche();
        }
    }
}

// (en fin de partie) permet de recommencer une partie/ retourner a l'accueil/ quitter le jeu
void finPartie(int* rejouerPartie, Hardcore* hardcore, int fin, int mode, int joueur, int* joueurCommence, caseGrille grille[9][9], Images* Images, SDL_Window*  pWindow, SDL_Renderer* pRenderer, FILE* fDebug, FILE* fSauvegarde)
{

    // animation ecran de fin

    animationGrillage(1, fin, mode, joueur, NULL, hardcore, grille, Images, pWindow, pRenderer, fDebug, fSauvegarde);

    while(eventFin(mode, joueurCommence, rejouerPartie, Images, pWindow, pRenderer, fDebug, fSauvegarde))
    {
        // taille du renderer
        int x = 0, y = 0;
        SDL_GetRendererOutputSize(pRenderer, &x, &y);

        {// affichage du menu

            SDL_Rect dest;

            afficheFin(0, fin, joueur, mode, NULL, NULL, NULL, NULL, NULL, grille, Images, pWindow, pRenderer, fDebug, fSauvegarde);

            changeDest(&dest, 0, 0);
            afficheImage(Images->Menu.Grillage.menu_Grillage, &dest, pRenderer, fDebug);

            changeDest(&dest, 75, 75);
            afficheImage_Centre(Images->Parametre.parametre_logo, &dest, pRenderer, fDebug);

            changeDest(&dest, x-50, 0);
            afficheImage(Images->Autre.croix, &dest, pRenderer, fDebug);

            changeDest(&dest, x/2, 3*y/16);
            afficheImage_Centre(Images->Menu.Bouton.menu_Rejouer, &dest, pRenderer, fDebug);

            changeDest(&dest, x/2, 8*y/16);
            afficheImage_Centre(Images->Menu.Bouton.menu_RetourAccueil, &dest, pRenderer, fDebug);

            changeDest(&dest, x/2, 13*y/16);
            afficheImage_Centre(Images->Menu.Bouton.menu_Quitter, &dest, pRenderer, fDebug);

            SDL_RenderPresent(pRenderer);
            debugWindow_Affiche();
        }
    }
}



// groupe d'image

// gere l'affichage du jeu: background, grille, pion, colonneActive
void affiche(int utilisation, int mode, int joueur, int tour, int colonneActive, caseGrille grille[9][9], Images* Images, SDL_Renderer* pRenderer, FILE* fDebug)
{
            /*
            ordre d'affichage:
            - background
            - joueur
            - pions
            - colonne active
            - grille
            - fleche retour
            */

            /*
            utilisation:
            0: affichage de la grille
            1: pas de grille
            */

    // taille du renderer
    int x = 0, y = 0;
    SDL_GetRendererOutputSize(pRenderer, &x, &y);

    SDL_Rect dest;

    changeDest(&dest, 0, 0);
    afficheImage(Images->Jeu.jeu_bg, &dest, pRenderer, fDebug);// background


    positionneJoueur(mode, joueur, Images, pRenderer, fDebug);// icones des joueurs


    int infoGrille[9] = {0};
    infosGrille(mode, infoGrille, grille);


    int c, l;
    // nombre de lignes et de colonnes different selon le mode
    if(mode!=3)
        c = 7, l = 6;
    else
        c = 9, l = 8;


    // affiche tous les pions
    for(int colonne = 0; colonne < c; colonne++)
    {
    	   for(int ligne = 0; ligne < l; ligne++)
    	   {
    	   	   affichePion(mode, colonne, ligne, grille[colonne][ligne].joueur, grille[colonne][ligne].etat, Images, pRenderer, fDebug);
    	   }
    }

    // active la colonne que survole le curseur
    if(colonneActive != -1)
    {

        // position de la colonne survole
        if(mode != 3)
	  	{
            changeDest(&dest, (x/2 - 350) + (colonneActive * 100), y/2 - 400);
        }
        else
        {
            changeDest(&dest, (x/2 - 450) + (colonneActive * 100), y/2 - 400);
        }

        // activation de la colonne en fonction de ses infos
        switch(infoGrille[colonneActive])
        {
            case 0:
                afficheImage(Images->Jeu.Colonne.jeu_Colonne_Desactive, &dest, pRenderer, fDebug);
            break;

            case 1:
                afficheImage(Images->Jeu.Colonne.jeu_ColonneTaille1_Active, &dest, pRenderer, fDebug);
            break;

            case 2:
                afficheImage(Images->Jeu.Colonne.jeu_ColonneTaille2_Active, &dest, pRenderer, fDebug);
            break;

            case 3:
                afficheImage(Images->Jeu.Colonne.jeu_ColonneTaille3_Active, &dest, pRenderer, fDebug);
            break;

            case 4:
                afficheImage(Images->Jeu.Colonne.jeu_ColonneTaille4_Active, &dest, pRenderer, fDebug);
            break;

            case 5:
                afficheImage(Images->Jeu.Colonne.jeu_ColonneTaille5_Active, &dest, pRenderer, fDebug);
            break;

            case 6:
                afficheImage(Images->Jeu.Colonne.jeu_ColonneTaille6_Active, &dest, pRenderer, fDebug);
            break;

            case 7:
                afficheImage(Images->Jeu.Colonne.jeu_ColonneTaille7_Active, &dest, pRenderer, fDebug);
            break;

            case 8:
                afficheImage(Images->Jeu.Colonne.jeu_ColonneTaille8_Active, &dest, pRenderer, fDebug);
            break;

        }

        // met un pion au dessu de la colonne active
        if(infoGrille[colonneActive] != 0)
        {
        	   affichePion(mode, colonneActive, l, joueur, 2, Images, pRenderer, fDebug);
        }
    }

    if(utilisation != 1)
    {
        // grilles differentes selon le mode
        if(mode!=3)
        {
            changeDest(&dest, x/2, y/2);
            afficheImage_Centre(Images->Jeu.Grille.grille7x6, &dest, pRenderer, fDebug);
        }
        else
        {
            changeDest(&dest, x/2, y/2 + 100);
            afficheImage_Centre(Images->Jeu.Grille.grille9x8, &dest, pRenderer, fDebug);
        }

    }

    if(tour != 0)
    {
        changeDest(&dest, x/2 - 650, y/2);
        afficheImage_Centre(Images->Jeu.jeu_retour, &dest, pRenderer, fDebug);
    }

}


void afficheFin(int utilisation, int fin, int joueur, int mode, int tour, int *rejouerPartie, int *retourAccueil, Hardcore* hardcore, int* joueurCommence, caseGrille grille[9][9], Images* Images, SDL_Window* pWindow, SDL_Renderer* pRenderer, FILE* fDebug, FILE* fSauvegarde)// ecrans de fin
{
    /*
	   la variable utilisation a pour fonctions:
	   si elle est positive, elle affiche met du delai
	   si elle est neutre, elle ne met pas de delai
    */

    // taille du renderer
    int x = 0, y = 0;
    SDL_GetRendererOutputSize(pRenderer,&x, &y);

    SDL_Rect dest;


    affiche(0, mode, NULL, NULL, -1, grille, Images, pRenderer, fDebug);


    changeDest(&dest, x-50, 0);
    afficheImage(Images->Autre.croix, &dest, pRenderer, fDebug);

    if(utilisation)
    {
        for(int temps = 0; (temps < 2500) && (*rejouerPartie == 0) && (*retourAccueil == 0); temps += 17)
        {
            affiche(0, mode, NULL, NULL, -1, grille, Images, pRenderer, fDebug);

            changeDest(&dest, x-50, 0);
            afficheImage(Images->Autre.croix, &dest, pRenderer, fDebug);

            changeDest(&dest, 75, 75);
            afficheImage_Centre(Images->Menu.menu_logo, &dest, pRenderer, fDebug);// logo du menu

            SDL_RenderPresent(pRenderer);
            debugWindow_Affiche();

            SDL_Delay(17);

            eventSpectateur(rejouerPartie, retourAccueil, hardcore, mode, joueur, tour, joueurCommence, grille, Images, pWindow, pRenderer, fDebug, fSauvegarde);
        }

    }

    /*
    ecran de fin:
    'LE JOUEUR
         n
       GAGNE'

        ou

     'EGALITE'
    */

    if(fin > 0)// victoire d'un joueur
    {

        changeDest(&dest, x/2, 1*y/4);
        afficheImage_Centre(Images->Fin.fin_LE_JOUEUR, &dest, pRenderer, fDebug);


    	   if(utilisation)
        {
            for(int temps = 0; (temps < 750) && (*rejouerPartie == 0) && (*retourAccueil == 0); temps += 17)
            {
                affiche(0, mode, NULL, NULL, -1, grille, Images, pRenderer, fDebug);

                changeDest(&dest, x-50, 0);
                afficheImage(Images->Autre.croix, &dest, pRenderer, fDebug);

                changeDest(&dest, 75, 75);
                afficheImage_Centre(Images->Menu.menu_logo, &dest, pRenderer, fDebug);// logo du menu


                changeDest(&dest, x/2, 1*y/4);
                afficheImage_Centre(Images->Fin.fin_LE_JOUEUR, &dest, pRenderer, fDebug);


                SDL_RenderPresent(pRenderer);
                debugWindow_Affiche();

                SDL_Delay(17);

                eventSpectateur(rejouerPartie, retourAccueil, hardcore, mode, joueur, tour, joueurCommence, grille, Images, pWindow, pRenderer, fDebug, fSauvegarde);
            }
        }


        // affichage du nombre

        changeDest(&dest, x/2, y/2);
        nombre(fin, &dest, Images, pRenderer, fDebug);


        if(utilisation)
        {
            for(int temps = 0; (temps < 750) && (*rejouerPartie == 0) && (*retourAccueil == 0); temps += 17)
            {
                affiche(0, mode, NULL, NULL, -1, grille, Images, pRenderer, fDebug);

                changeDest(&dest, x-50, 0);
                afficheImage(Images->Autre.croix, &dest, pRenderer, fDebug);

                changeDest(&dest, 75, 75);
                afficheImage_Centre(Images->Menu.menu_logo, &dest, pRenderer, fDebug);// logo du menu


                changeDest(&dest, x/2, 1*y/4);
                afficheImage_Centre(Images->Fin.fin_LE_JOUEUR, &dest, pRenderer, fDebug);

                changeDest(&dest, x/2, 2*y/4);
                nombre(fin, &dest, Images, pRenderer, fDebug);


                SDL_RenderPresent(pRenderer);
                debugWindow_Affiche();

                SDL_Delay(17);

                eventSpectateur(rejouerPartie, retourAccueil, hardcore, mode, joueur, tour, joueurCommence, grille, Images, pWindow, pRenderer, fDebug, fSauvegarde);
            }
        }

        changeDest(&dest, x/2, 3*y/4);
        afficheImage_Centre(Images->Fin.fin_GAGNE, &dest, pRenderer, fDebug);

        if(utilisation)
        {
            for(int temps = 0; (temps < 1400) && (*rejouerPartie == 0) && (*retourAccueil == 0); temps += 17)
            {
                affiche(0, mode, NULL, NULL, -1, grille, Images, pRenderer, fDebug);

                changeDest(&dest, x-50, 0);
                afficheImage(Images->Autre.croix, &dest, pRenderer, fDebug);

                changeDest(&dest, 75, 75);
                afficheImage_Centre(Images->Menu.menu_logo, &dest, pRenderer, fDebug);// logo du menu


                changeDest(&dest, x/2, 1*y/4);
                afficheImage_Centre(Images->Fin.fin_LE_JOUEUR, &dest, pRenderer, fDebug);

                changeDest(&dest, x/2, 2*y/4);
                nombre(fin, &dest, Images, pRenderer, fDebug);

                changeDest(&dest, x/2, 3*y/4);
                afficheImage_Centre(Images->Fin.fin_GAGNE, &dest, pRenderer, fDebug);


                SDL_RenderPresent(pRenderer);
                debugWindow_Affiche();

                SDL_Delay(17);

                eventSpectateur(rejouerPartie, retourAccueil, hardcore, mode, joueur, tour, joueurCommence, grille, Images, pWindow, pRenderer, fDebug, fSauvegarde);
            }
        }

    }
    else if(fin < 0)// egalite
    {
        changeDest(&dest, x/2, 2*y/4);
        afficheImage_Centre(Images->Fin.fin_EGALITE, &dest, pRenderer, fDebug);

        if(utilisation)
        {
            for(int temps = 0; (temps < 1400) && (*rejouerPartie == 0) && (*retourAccueil == 0); temps += 17)
            {
                affiche(0, mode, NULL, NULL, -1, grille, Images, pRenderer, fDebug);

                changeDest(&dest, x-50, 0);
                afficheImage(Images->Autre.croix, &dest, pRenderer, fDebug);

                changeDest(&dest, 75, 75);
                afficheImage_Centre(Images->Menu.menu_logo, &dest, pRenderer, fDebug);// logo du menu


                changeDest(&dest, x/2, 2*y/4);
                afficheImage_Centre(Images->Fin.fin_EGALITE, &dest, pRenderer, fDebug);


                SDL_RenderPresent(pRenderer);
                debugWindow_Affiche();

                SDL_Delay(17);

                eventSpectateur(rejouerPartie, retourAccueil, hardcore, mode, joueur, tour, joueurCommence, grille, Images, pWindow, pRenderer, fDebug, fSauvegarde);
            }
        }
    }

    if(utilisation){
        SDL_RenderPresent(pRenderer);
        debugWindow_Affiche();
    }


}

// affiche les pions
void affichePion(int mode, int colonne, int ligne, int pionJoueur, int pionEtat, Images* Images, SDL_Renderer* pRenderer, FILE* fDebug)
{
	   // taille du renderer
    int x = 0, y = 0;
    SDL_GetRendererOutputSize(pRenderer, &x, &y);

    SDL_Rect dest;

    if(mode != 3)
    {
        changeDest(&dest, (x/2 - 300) + (colonne * 100), (y/2 + 250) - (ligne * 100));
    }
    else
    {
        changeDest(&dest, (x/2 - 400) + (colonne * 100), (y/2 + 450) - (ligne * 100));
    }

    switch (pionJoueur)
    {
        case 1:

            switch(pionEtat)
            {
            	   case 1:
            	       afficheImage_Centre(Images->Jeu.Pions.pion1, &dest, pRenderer, fDebug);// normal
            	   break;

            	   case 2:
            	       afficheImage_Centre(Images->Jeu.Pions.pion1_joue, &dest, pRenderer, fDebug);// vient d'etre joue
            	   break;

            	   case 3:
            	       afficheImage_Centre(Images->Jeu.Pions.pion1_gagne, &dest, pRenderer, fDebug);// fait parti du puissance4
            	   break;

            }
        break;

        case 2:

            switch(pionEtat)
            {
            	   case 1:
            	       afficheImage_Centre(Images->Jeu.Pions.pion2, &dest, pRenderer, fDebug);// normal
            	   break;

            	   case 2:
            	       afficheImage_Centre(Images->Jeu.Pions.pion2_joue, &dest, pRenderer, fDebug);// vient d'etre joue
            	   break;

            	   case 3:
            	       afficheImage_Centre(Images->Jeu.Pions.pion2_gagne, &dest, pRenderer, fDebug);// fait parti du puissance4
            	   break;

            }
        break;

        case 3:

            switch(pionEtat)
            {
            	   case 1:
            	       afficheImage_Centre(Images->Jeu.Pions.pion3, &dest, pRenderer, fDebug);// normal
            	   break;

            	   case 2:
            	       afficheImage_Centre(Images->Jeu.Pions.pion3_joue, &dest, pRenderer, fDebug);// vient d'etre joue
            	   break;

            	   case 3:
            	       afficheImage_Centre(Images->Jeu.Pions.pion3_gagne, &dest, pRenderer, fDebug);// fait parti du puissance4
            	   break;

            }

        break;

    }
}

// positionne les joueurs dans l'ordre de jeu
void positionneJoueur(int mode, int joueur, Images* Images, SDL_Renderer* pRenderer, FILE* fDebug)
{

	   switch(mode)
	   {
	   	   case 1:
	   	       if(joueur == 1)
	   	       {
	   	           afficheJoueur(1, 1, Images, pRenderer, fDebug);
	   	           afficheJoueur(2, 2, Images, pRenderer, fDebug);
	   	       }
	   	       else
	   	       {
	   	           afficheJoueur(2, 1, Images, pRenderer, fDebug);
	   	           afficheJoueur(1, 2, Images, pRenderer, fDebug);
	   	       }

	   	   break;

	   	   case 2:
	   	       if(joueur == 1)
	   	       {
	   	           afficheJoueur(1, 1, Images, pRenderer, fDebug);
	   	           afficheJoueur(5, 2, Images, pRenderer, fDebug);
	   	       }
	   	       else
	   	       {
	   	           afficheJoueur(5, 1, Images, pRenderer, fDebug);
	   	           afficheJoueur(1, 2, Images, pRenderer, fDebug);
	   	       }

	   	   break;

	   	   case 3:
	   	       if(joueur == 1)
	   	       {
	   	           afficheJoueur(1, 1, Images, pRenderer, fDebug);
	   	           afficheJoueur(2, 2, Images, pRenderer, fDebug);
	   	           afficheJoueur(3, 3, Images, pRenderer, fDebug);
	   	       }
	   	       else if(joueur == 2)
	   	       {
	   	           afficheJoueur(2, 1, Images, pRenderer, fDebug);
	   	           afficheJoueur(3, 2, Images, pRenderer, fDebug);
	   	           afficheJoueur(1, 3, Images, pRenderer, fDebug);
	   	       }
	   	       else
	   	       {
	   	           afficheJoueur(3, 1, Images, pRenderer, fDebug);
	   	           afficheJoueur(1, 2, Images, pRenderer, fDebug);
	   	           afficheJoueur(2, 3, Images, pRenderer, fDebug);
	   	       }

	   	   break;

	   	   case 4:
	   	       if(joueur == 1)
	   	       {
	   	           afficheJoueur(4, 1, Images, pRenderer, fDebug);
	   	           afficheJoueur(5, 2, Images, pRenderer, fDebug);
	   	       }
	   	       else
	   	       {
	   	           afficheJoueur(5, 1, Images, pRenderer, fDebug);
	   	           afficheJoueur(4, 2, Images, pRenderer, fDebug);
	   	       }
	   	   break;
	   }
}

// affiche les joueurs
void afficheJoueur(int type, int position, Images* Images, SDL_Renderer* pRenderer, FILE* fDebug)
{
/*
type:
    1 = joueur 1
	2 = joueur 2
	3 = joueur 3
	4 = bot 1
	5 = bot 2
*/

    // taille du renderer
    int x = 0, y = 0;
    SDL_GetRendererOutputSize(pRenderer, &x, &y);

    SDL_Rect dest = {x/2 - 750, y/16 + position*100, 0, 0};


    if(position == 1)// le joueur qui doit jouer est mis en valeur
    {
        switch(type)
        {
            case 1:
                afficheImage_Centre(Images->Jeu.Joueur.joueur1_actif, &dest, pRenderer, fDebug);
            break;

            case 2:
                afficheImage_Centre(Images->Jeu.Joueur.joueur2_actif, &dest, pRenderer, fDebug);
            break;

            case 3:
                afficheImage_Centre(Images->Jeu.Joueur.joueur3_actif, &dest, pRenderer, fDebug);
            break;

            case 4:
                afficheImage_Centre(Images->Jeu.Joueur.bot1_actif, &dest, pRenderer, fDebug);
            break;

            case 5:
                afficheImage_Centre(Images->Jeu.Joueur.bot2_actif, &dest, pRenderer, fDebug);
            break;

        }
    }
    else
    {
        switch(type)
        {
            case 1:
                afficheImage_Centre(Images->Jeu.Joueur.joueur1, &dest, pRenderer, fDebug);
            break;

            case 2:
                afficheImage_Centre(Images->Jeu.Joueur.joueur2, &dest, pRenderer, fDebug);
            break;

            case 3:
                afficheImage_Centre(Images->Jeu.Joueur.joueur3, &dest, pRenderer, fDebug);
            break;

            case 4:
                afficheImage_Centre(Images->Jeu.Joueur.bot1, &dest, pRenderer, fDebug);
            break;

            case 5:
                afficheImage_Centre(Images->Jeu.Joueur.bot2, &dest, pRenderer, fDebug);
            break;

        }
    }
}

// affiche la barre de temps restant au mode hardcore
void afficheHardcore(Hardcore* hardcore, Images* Images, SDL_Renderer* pRenderer, FILE* fDebug)
{
    // taille du renderer
    int x = 0, y = 0;
    SDL_GetRendererOutputSize(pRenderer, &x, &y);

    SDL_Rect dest;

    if(hardcore->mode)
    {

        changeDest(&dest, x/2 + 700, y/2);
        afficheImage_Centre(Images->Jeu.Hardcore_.hardcore_bg, &dest, pRenderer, fDebug);// background

        // affichage des nombres indiquants le temps restant

        if(hardcore->tempsRestant >= 10)
        {
            changeDest(&dest, x/2 + 625, (y/2 - 300) - 100);
            nombre(1, &dest, Images, pRenderer, fDebug);

            changeDest(&dest, x/2 + 775, (y/2 - 300) - 100);
            nombre(hardcore->tempsRestant - 10, &dest, Images, pRenderer, fDebug);

        }
        else
        {
            changeDest(&dest, x/2 + 700, (y/2 - 300) - 100);
            nombre(hardcore->tempsRestant, &dest, Images, pRenderer, fDebug);
        }


        // affichage des 'case' de temps restant
        switch(hardcore->mode)
        {
            case 1: // 10 cases de temps
            {
                for(int i = 0; i < hardcore->tempsRestant; i++)
                {
                    // place dest.y en bas de hardcore_bg, puis divise ce dernier en 11 pour ensuite assigner chaques hardcore_temps aux divisions
                    changeDest(&dest, x/2 + 700, (y/2 + 300) - (( i + 1) * (600 / 11)));

                    // changement de couleur selon te temps restant
                    if(hardcore->tempsRestant >= 5)
                        afficheImage_Centre(Images->Jeu.Hardcore_.hardcore_Temps_Vert, &dest, pRenderer, fDebug);
                    else if(hardcore->tempsRestant >= 3)
                        afficheImage_Centre(Images->Jeu.Hardcore_.hardcore_Temps_Orange, &dest, pRenderer, fDebug);
                    else
                        afficheImage_Centre(Images->Jeu.Hardcore_.hardcore_Temps_Rouge, &dest, pRenderer, fDebug);

                }
            }
            break;

            case 2: // 3 cases de temps
            {
                for(int i = 0; i < hardcore->tempsRestant; i++)
                {
                    // place dest.y en bas de hardcore_bg, puis divise ce dernier en 4 pour ensuite assigner chaques hardcore_temps aux divisions
                    changeDest(&dest, x/2 + 700, (y/2 + 300) - (( i + 1) * (600 / 4)));

                    // changement de couleur selon te temps restant
                    if(hardcore->tempsRestant >= 3)
                        afficheImage_Centre(Images->Jeu.Hardcore_.hardcore_Temps_Vert, &dest, pRenderer, fDebug);
                    else if(hardcore->tempsRestant >= 2)
                        afficheImage_Centre(Images->Jeu.Hardcore_.hardcore_Temps_Orange, &dest, pRenderer, fDebug);
                    else
                        afficheImage_Centre(Images->Jeu.Hardcore_.hardcore_Temps_Rouge, &dest, pRenderer, fDebug);

                }
            }
            break;
        }
    }

}

// affiche des nombres
void nombre(int nombre, SDL_Rect* dest, Images* Images, SDL_Renderer* pRenderer, FILE* fDebug)
{
    switch(nombre)
    {
        case 0:
            afficheImage_Centre(Images->Nombres.nb_0, dest, pRenderer, fDebug);
        break;

        case 1:
            afficheImage_Centre(Images->Nombres.nb_1, dest, pRenderer, fDebug);
        break;

        case 2:
            afficheImage_Centre(Images->Nombres.nb_2, dest, pRenderer, fDebug);
        break;

        case 3:
            afficheImage_Centre(Images->Nombres.nb_3, dest, pRenderer, fDebug);
        break;

        case 4:
            afficheImage_Centre(Images->Nombres.nb_4, dest, pRenderer, fDebug);
        break;

        case 5:
            afficheImage_Centre(Images->Nombres.nb_5, dest, pRenderer, fDebug);
        break;

        case 6:
            afficheImage_Centre(Images->Nombres.nb_6, dest, pRenderer, fDebug);
        break;

        case 7:
            afficheImage_Centre(Images->Nombres.nb_7, dest, pRenderer, fDebug);
        break;

        case 8:
            afficheImage_Centre(Images->Nombres.nb_8, dest, pRenderer, fDebug);
        break;

        case 9:
            afficheImage_Centre(Images->Nombres.nb_9, dest, pRenderer, fDebug);
        break;

    }
}



// animation

// anime le grillage du menu qui tombe
void animationGrillage(int utilisation, int fin, int mode, int joueur, int tour, Hardcore* hardcore, caseGrille grille[9][9], Images* Images, SDL_Window* pWindow, SDL_Renderer* pRenderer, FILE* fDebug, FILE* fSauvegarde)
{
        /*
        la variable utilisation a 2 fonctions:
        si elle est positive, elle affiche la grille en mode fin
        si son absolu est égal a 2, elle affiche la grille sans animation
        */

        /*
        ordre d'affichage:
        -affiche (background, pion, grille,...)
        -hardcore
        -grillage
        */

    // taille du renderer
    int x = 0, y = 0;
    SDL_GetRendererOutputSize(pRenderer, &x, &y);

    SDL_Rect dest;

    for(int nombreLigne = 1; nombreLigne <= (y/16); nombreLigne += 6)// nombre de ligne ( /2 car l'image d'une ligne fait 2pxls)
    {


        if(utilisation > 0)// si c'est la fin
            afficheFin(0, fin, joueur, mode, NULL, NULL, NULL, NULL, NULL, grille, Images, pWindow, pRenderer, fDebug, fSauvegarde);
        else
        {
            affiche(0, mode, joueur, tour, -1, grille, Images, pRenderer, fDebug);

            if(mode!=4)
                afficheHardcore(hardcore, Images, pRenderer, fDebug);
        }

        changeDest(&dest, 75, 75);
        afficheImage_Centre(Images->Menu.menu_logo, &dest, pRenderer, fDebug);// logo du menu


        // affichage du la grillage
        for(int ligne = 0, i = 8; ligne < nombreLigne; ligne++, i += 16)
        {
            changeDest(&dest, x/2, i);

            if((nombreLigne - 1) % 12)
            {
                if((i+8) % 32)
                    afficheImage_Centre(Images->Menu.Grillage.menu_Grillage1, &dest, pRenderer, fDebug);
                else
                    afficheImage_Centre(Images->Menu.Grillage.menu_Grillage2, &dest, pRenderer, fDebug);
            }
            else
            {
                if((i+8) % 32)
                    afficheImage_Centre(Images->Menu.Grillage.menu_Grillage2, &dest, pRenderer, fDebug);
                else
                    afficheImage_Centre(Images->Menu.Grillage.menu_Grillage1, &dest, pRenderer, fDebug);
            }

        }

        if(nombreLigne + 1 <= (y/16))
        {
            changeDest(&dest, x/2, (nombreLigne) * 16);
            afficheImage_Centre(Images->Menu.Grillage.menu_BordureGrillage, &dest, pRenderer, fDebug);// se situe en bas du grillage et permet de rajouter du style
        }


        changeDest(&dest, x-50, 0);
        afficheImage(Images->Autre.croix, &dest, pRenderer, fDebug);


        SDL_RenderPresent(pRenderer);
        debugWindow_Affiche();

        SDL_Delay(17); // (= 0.017 s)

    }

    SDL_RenderPresent(pRenderer);
    debugWindow_Affiche();

}


// anime les pions qui tombent
void animationPion(int colonne, int joueur, int mode, int tour,int *rejouerPartie, int *retourAccueil, int* joueurCommence, Hardcore* hardcore, caseGrille grille[9][9], Images* Images, SDL_Window* pWindow, SDL_Renderer* pRenderer, FILE* fDebug, FILE* fSauvegarde)
{

    // taille du renderer
    int x = 0, y = 0;
    SDL_GetRendererOutputSize(pRenderer, &x, &y);

    SDL_Rect dest;


    int infoGrille[9] = {0};// permet de connaitre le nombre de pions restant dans chaques colonne
    infosGrille(mode, infoGrille, grille);

    pion pion = {mode != 3? (x/2 - 300) + (colonne * 100) : (x/2 - 400) + (colonne * 100), mode != 3? y/2 - 350 : y/2 - 350, 0};// info du pion: x, y, velociteY


    int distance = infoGrille[colonne]*100;// distance que le pion doit encore parcourir

    while(distance != 0 || pion.velociteY != 0)// animation
    {

        // mouvement
        distance += pion.velociteY;
        pion.y -= pion.velociteY;

        // depasse la case
        if(distance < 0)
        {
            distance = 0;
            pion.y = mode != 3? y/2 - 350 : y/2 - 350;
            pion.y += infoGrille[colonne]*100;
        }


        {//affichage du reste

            affiche(1, mode, joueur, tour, -1, grille, Images, pRenderer, fDebug);

            changeDest(&dest, x-50, 0);
            afficheImage(Images->Autre.croix, &dest, pRenderer, fDebug);

            changeDest(&dest, 75, 75);
            afficheImage_Centre(Images->Menu.menu_logo, &dest, pRenderer, fDebug);// logo du menu

            {// affichage du pion
                changeDest(&dest, pion.x, pion.y);

                switch(joueur)
                {
                    case 1:
                        afficheImage_Centre(Images->Jeu.Pions.pion1_joue, &dest, pRenderer, fDebug);
                    break;

                    case 2:
                        afficheImage_Centre(Images->Jeu.Pions.pion2_joue, &dest, pRenderer, fDebug);
                    break;

                    case 3:
                        afficheImage_Centre(Images->Jeu.Pions.pion3_joue, &dest, pRenderer, fDebug);
                    break;
                }
            }

            if(mode!=3)
            {
                changeDest(&dest, x/2, y/2);
                afficheImage_Centre(Images->Jeu.Grille.grille7x6, &dest, pRenderer, fDebug);
            }
            else
            {
                changeDest(&dest, x/2, y/2 + 100);
                afficheImage_Centre(Images->Jeu.Grille.grille9x8, &dest, pRenderer, fDebug);
            }


            if(mode!=4)
                afficheHardcore(hardcore, Images, pRenderer, fDebug);

        }

        SDL_RenderPresent(pRenderer);
        debugWindow_Affiche();

        if(0 > pion.velociteY && pion.velociteY > -25)// le pion tombe
            pion.velociteY -= 3;// gagne 3 px de velocite par frames
        else if(pion.velociteY > 0)// le pion monte
            pion.velociteY -= 5;// pert 10 px de velocite par frames

        if(abs(distance) < 25 && ( (-15 <= pion.velociteY) && (pion.velociteY <= 0) ))// le pion est presque a l'arret et a sa case
        {
            // on arrete le pion
            distance = 0;
            pion.y = mode != 3? y/2 - 350 : y/2 - 350;
            pion.y += infoGrille[colonne]*100;
            pion.velociteY = 0;
        }
        else// le pion est a l'arret mais pas a sa case
        {
            pion.velociteY -= 2;
        }

        if(distance <= 0)// le pion atteint sa case
            pion.velociteY = abs(pion.velociteY)/2;// on inverse sa vitesse, ce qui le fait rebondir

        // event qui permet au joueur d'effectuer des actions lors d'une annimation ou autre
        eventSpectateur(rejouerPartie, retourAccueil, hardcore, mode, joueur, tour, joueurCommence, grille, Images, pWindow, pRenderer, fDebug, fSauvegarde);

        SDL_Delay(17);
    }

}
