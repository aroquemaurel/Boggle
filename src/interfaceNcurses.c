#include <ncurses.h>
#include <stdlib.h>
#include "interfaceNcurses.h"
#include "plateau.h"
#include "jeu.h"

void interfaceNcurses_afficherPlateau(const Plateau pPlateau) { 
//    for(int i = 0 ; i < pPlateau.tailleGrille ; ++i) {
   //     for(int j = 0 ; j < pPlateau.tailleGrille ; ++j) {
          //  mvprintw(i, j, " %c ", pPlateau.grille[i][j]);
     //   }
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
    mvprintw(7, 10, "Jeu de Boggle");
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
    char proposition[32];
    int ch;
    WINDOW* fenetre;
    jeu_lancer(&pJeu);
    fenetre = interfaceNcurses_initialiser();
            /*  Loop until user presses 'q'  */

    while ( (ch = getch()) != 'q' ) { // TODO tantque compteur non claqué
        //mvprintw(0, 0, "You pressed:");
       // interfaceNcurses_afficherPlateau(pJeu.plateau);
        for(int i = 0 ; i < pJeu.plateau.tailleGrille ; ++i) {
             for(int j = 0 ; j < pJeu.plateau.tailleGrille ; ++j) {
                mvprintw(i*2+10, j*3+20, "%c", pJeu.plateau.grille[i][j]);
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


