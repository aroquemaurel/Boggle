/**
 * \file interfaceNcurses.c
 * \brief Affichage avec la bibliothèque Ncurses
 * Affiche et permet de jouer au jeu de Boggle avec un affichage utilisant la bibliothèque Ncurses
 */

#include <ncurses.h>
#include <panel.h>
#include <stdlib.h>
#include <string.h>

#include "interfaceNcurses.h"
#include "plateau.h"
#include "jeu.h"
#include "util.h"


void interfaceNcurses_afficherSolution(const Solution pSolution) {
    mvprintw(5, 55, "%d mots (%d points)", pSolution.nbMots, solution_nbPoints(pSolution));        
    for(int i=0 ; i < pSolution.nbMots ; ++i) {
        mvprintw(6+i, 55, "%s", pSolution.mots[i]);        
    }    
}

WINDOW* interfaceNcurses_initialiser(void) {
    WINDOW* fenetre = initscr();
    /*  Initialize ncurses  */
    if (fenetre == NULL) {
        fprintf(stderr, "Error initializing ncurses.\n");
        exit(EXIT_FAILURE);
    }
    noecho();                  /*  Turn off key echoing                 */
    keypad(fenetre, TRUE);     /*  Enable the keypad for non-char keys  */
    start_color();
    init_pair(COULEUR_SELECTION_CASE, COLOR_BLACK, COLOR_WHITE);
    init_pair(COULEUR_CASE_CHOISI, COLOR_WHITE, COLOR_BLUE);    

    refresh();
    
    return fenetre;
}

void interfaceNcurses_afficherGrille(const Plateau pPlateau, const Case pSelectedCase, 
                                    const Case* pUsedCase, const int pLgUsedCase) {
    Case buff;
    
    for (int j = 0 ; j < pPlateau.tailleGrille ; ++j) {
         for(int i = 0 ; i < pPlateau.tailleGrille ; ++i) {
             buff.i = i;
             buff.j = j;
             if(util_isInArray(pUsedCase, pLgUsedCase+1, buff)) {
                attron(COLOR_PAIR(COULEUR_CASE_CHOISI));
             }             
             if((pSelectedCase.i == i) && (pSelectedCase.j ==j)) {
            	attron(COLOR_PAIR(COULEUR_SELECTION_CASE));
             }
             mvprintw(i+6, j*3+5, " %c ", pPlateau.grille[i][j]);
            
            attroff(COLOR_PAIR(COULEUR_SELECTION_CASE));
            attroff(COLOR_PAIR(COULEUR_CASE_CHOISI));
       }
     }
    for(int i = 3 ; i < NB_LIGNES - 2; ++i) {
        mvprintw(i, pPlateau.tailleGrille*3+7, "");        
        addch(ACS_VLINE);
    }
}

void interfaceNcurses_terminer(WINDOW* fenetre) {
    delwin(fenetre);
    endwin();
    refresh();
}

void jeu_lancerModeNcurses(Jeu pJeu) {
    int minutes, secondes;
    Case selectedCase;
    Case lastChoseCase;
    Case usedCase[32];
    WINDOW* fenetre;
    char mot[32] = "";
    int ch;

    selectedCase.i = 0;
    selectedCase.j = 0;
    lastChoseCase.i = -1;
    lastChoseCase.j = -1;; 

    jeu_lancer(&pJeu);
    fenetre = interfaceNcurses_initialiser();
    for(int i = 0 ; i < 31 ; ++i) {
        mot[i] = '\0';
    }

    do {
        clear();

        switch(ch) {
            case KEY_LEFT:
                // FIXME déplacement lettres
                if((strlen(mot) == 0) || (selectedCase.j == lastChoseCase.j) || (selectedCase.j == lastChoseCase.j+1)) {
                    selectedCase.j = (selectedCase.j-1 >= 0) ? selectedCase.j-1 : selectedCase.j;
               }
            break;
            case KEY_RIGHT:
                if((strlen(mot) == 0) || (selectedCase.j == lastChoseCase.j) || (selectedCase.j == lastChoseCase.j-1)) {
                selectedCase.j = (selectedCase.j+1 < pJeu.plateau.tailleGrille) 
                                        ? selectedCase.j+1 : selectedCase.j;
                }
                break;
            case KEY_UP:
                if((strlen(mot) == 0) || (selectedCase.i == lastChoseCase.i) || (selectedCase.i == lastChoseCase.i+1)) {
                selectedCase.i = (selectedCase.i-1 < pJeu.plateau.tailleGrille) 
                                        ? selectedCase.i-1 : selectedCase.i;                
                }
                break;
            case KEY_DOWN:
                if((strlen(mot) == 0) || (selectedCase.i == lastChoseCase.i) || (selectedCase.i == lastChoseCase.i-1)) {
                selectedCase.i = (selectedCase.i+1 < pJeu.plateau.tailleGrille) 
                        ? selectedCase.i+1 : selectedCase.i;
                }
                break;
            case ' ':  //touche espace
               if(((selectedCase.i != lastChoseCase.i) || (selectedCase.j != lastChoseCase.j)) 
                        && (!util_isInArray(usedCase, strlen(mot)+1, selectedCase))) {
                    mot[strlen(mot)] = pJeu.plateau.grille[selectedCase.i][selectedCase.j];
                    usedCase[strlen(mot)] = selectedCase;
                    mvprintw(0, 50, "%s", mot);
                    lastChoseCase = selectedCase;
                }
                break;
            case '\n': // Touche entrée 
                mvprintw(1, 60, "%s", mot);
                mvprintw(2, 60, "%s", (jeu_proposerMot(&pJeu, mot) ? "Mot correct" : "Mot Incorrect"));

                for(int i = 0 ; i < 31 ; ++i) {
                    mot[i] = '\0';
                }
                lastChoseCase.i = -1;
                lastChoseCase.j = -1;
                break;
            default:
                break;
        }

        interfaceNcurses_afficherSolution(pJeu.solutionUtilisateur);
        mvprintw(0, 4, "=== Jeu de Boggle ===");
        util_conversionTemps(jeu_tempsRestant(pJeu), &minutes, &secondes);
        mvprintw(0, 35, "Temps restant: %d min et %d secondes", minutes, secondes);
        mvprintw(1, 60, "%s", mot);
        interfaceNcurses_afficherGrille(pJeu.plateau, selectedCase, usedCase, strlen(mot));

	//deleteln();
	refresh();
    ch = getch();
    } while ((ch != 'q') && (!jeu_compteurClaque(pJeu))); 

    interfaceNcurses_terminer(fenetre);
}


