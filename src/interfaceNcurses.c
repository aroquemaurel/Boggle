#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include "interfaceNcurses.h"
#include "plateau.h"
#include "jeu.h"

void interfaceNcurses_afficherPlateau(const Plateau pPlateau, const Case pCase) { 
//    for(int j = 0 ; j < pPlateau.tailleGrille ; ++j) {
 //        for(int i = 0 ; i < pPlateau.tailleGrille ; ++i) {
             // TODO afficher en couleurs si séléctionnée
//            mvprintw(i+4, j*3+5, "%d%c", (pICaseActuel == i && pJCaseActuel ==j), pPlateau.grille[i][j]);
  //      }
  //   }
 
}

WINDOW* interfaceNcurses_initialiser() {
    WINDOW * fenetre;

    /*  Initialize ncurses  */
    if ( (fenetre = initscr()) == NULL ) {
        fprintf(stderr, "Error initializing ncurses.\n");
        exit(EXIT_FAILURE);
    }
    noecho();                  /*  Turn off key echoing                 */
    keypad(fenetre, TRUE);     /*  Enable the keypad for non-char keys  */
    mvprintw(0, 4, "=== Jeu de Boggle ===");
    refresh();
    
        /*  Clean up after ourselves  */

    return fenetre;
}

void interfaceNcurses_terminer(WINDOW* fenetre) {
    delwin(fenetre);
    endwin();
    refresh();
}
void jeu_lancerModeNcurses(Jeu pJeu) {
    Case selectedCase;
    Case lastChoseCase;
    Case usedCase[32];
    WINDOW* fenetre;
    char mot[32] = "";
    int ch;
    
    selectedCase.i = 0;
    selectedCase.j = 0;
    lastChoseCase = selectedCase; 

    jeu_lancer(&pJeu);
    fenetre = interfaceNcurses_initialiser();
            /*  Loop until user presses 'q'  */
                    for(int i = 0 ; i < 31 ; ++i) {
                    mot[i] = '\0';
                }
    while ( (ch = getch()) != 'q' ) { // TODO tantque compteur non claqué
        switch(ch) {
            case KEY_LEFT:
                // FIXME déplacement lettres
                if(strlen(mot) == 0 || (selectedCase.j == lastChoseCase.j) || (selectedCase.j == lastChoseCase.j+1)) {
                selectedCase.j = (selectedCase.j-1 >= 0) 
                                        ? selectedCase.j-1 : selectedCase.j;
                }
            break;
            case KEY_RIGHT:
                if(strlen(mot) == 0 || (selectedCase.j == lastChoseCase.j) || (selectedCase.j == lastChoseCase.j-1)) {
                selectedCase.j = (selectedCase.j+1 < pJeu.plateau.tailleGrille) 
                                        ? selectedCase.j+1 : selectedCase.j;
                }
                break;
            case KEY_UP:
                if(strlen(mot) == 0 || (selectedCase.i == lastChoseCase.i) || (selectedCase.i == lastChoseCase.i+1)) {
                selectedCase.i = (selectedCase.i-1 < pJeu.plateau.tailleGrille) 
                                        ? selectedCase.i-1 : selectedCase.i;                
                }
                break;
            case KEY_DOWN:
                if(strlen(mot) == 0 || (selectedCase.i == lastChoseCase.i) || (selectedCase.i == lastChoseCase.i-1)) {
                selectedCase.i = (selectedCase.i+1 <= pJeu.plateau.tailleGrille) 
                        ? selectedCase.i+1 : selectedCase.i;
                }
                break;
            case KEY_BACKSPACE: // TODO changer touche, lire la doc => space
                if(selectedCase.i != lastChoseCase.i || selectedCase.j != lastChoseCase.j) {
                    mot[strlen(mot)] = pJeu.plateau.grille[selectedCase.i][selectedCase.j];
                    usedCase[strlen(mot)] = selectedCase;
                    mvprintw(0, 50, "%s", mot);
                    for(int i = 0 ; i < 31 ; ++i) {
                            mvprintw(0, 50+strlen(mot)+i, " ");
                    }
                    lastChoseCase = selectedCase;
                }
                break;
            case KEY_ENTER:                
                // refresh la ligne TODO
                mvprintw(1, 50, "%s", (jeu_proposerMot(&pJeu, mot) ? "Mot correct" : "Mot Incorrect"));

                // refresh la ligne TODO
                for(int i = 0 ; i < 31 ; ++i) {
                    mvprintw(0, 50+i, " ");
                }

                for(int i = 0 ; i < 31 ; ++i) {
                    mot[i] = '\0';
                }
            
                break;
                        
        }
 /*       mvprintw(0, 50, "You pressed\n");
        mvprintw(0, 50, "You pressed\n");
        mvprintw(1, 50, "You pressed\n");
        mvprintw(2, 50, "You pressed\n");
        mvprintw(3, 50, "You pressed\n");
        mvprintw(4, 50, "You pressed\n"); */
//        interfaceNcurses_afficherPlateau(pJeu.plateau, iCaseActuel, jCaseActuel);
            for(int j = 0 ; j < pJeu.plateau.tailleGrille ; ++j) {
         for(int i = 0 ; i < pJeu.plateau.tailleGrille ; ++i) {
             // TODO afficher en couleurs si séléctionnée
            mvprintw(i+4, j*3+5, "%d%c", (selectedCase.i == i && selectedCase.j ==j), pJeu.plateau.grille[i][j]);
       }
     }
	/*  Delete the old response line, and print a new one  */
	deleteln();
	refresh();
    }

    interfaceNcurses_terminer(fenetre);
//    interfaceTexte_afficherPlateau(pJeu.plateau);
	//
 // solution_afficher(pJeu.plateau.solution);
 // do {
  //      printf("encore %f secondes", (jeu_tempsRestant(pJeu)));
   //     scanf("%s", &proposition);
//		printf("\n%s", jeu_proposerMot(&pJeu, proposition) ? "Good" : "Bad");
 //   }while((strcmp(proposition, "-1") != 0) && !jeu_compteurClaque(pJeu));
  //  solution_afficher(pJeu.solutionUtilisateur);
//	jeu_stopper(pJeu);
  //  printf("\nProposer des mots : ");
//    solution_afficher(pJeu.plateau.solution);
}


