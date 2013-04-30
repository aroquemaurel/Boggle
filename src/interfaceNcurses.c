/**
 * \file interfaceNcurses.c
 * \brief Affichage avec la bibliothèque Ncurses
 * Affiche et permet de jouer au jeu de Boggle avec un affichage utilisant la bibliothèque Ncurses
 */

#include <ncurses.h>
#include <panel.h>
#include <menu.h>
#include <stdlib.h>
#include <string.h>

#include "interfaceNcurses.h"
#include "plateau.h"
#include "jeu.h"
#include "util.h"

int func(char* name);
void interfaceNcurses_afficherTitre(const char* pTitle) {
    mvprintw(0, 4, "==== %s ====", pTitle);
    mvprintw(1, 4, "Pressez la touche q pour sortir");
}
void interfaceNcurses_afficherSolution(const Solution pSolution) {
    int j = 0, k = 0;
    mvprintw(5, 55, "%d mots (%d points)", pSolution.nbMots, solution_nbPoints(pSolution));        
    for(int i=0 ; i < pSolution.nbMots ; ++i) {
        ++k;
        if(i % 30 == 0) {
            ++j; 
            k = 0;
        }
        mvprintw(6+k, 38+(j*15), "%s", pSolution.mots[i]);        
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

void interfaceNcurses_terminer(WINDOW* fenetre, Jeu pJeu) {
    delwin(fenetre);
    endwin();
    refresh();
    jeu_stopper(pJeu);
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
    lastChoseCase.i = -1;
    lastChoseCase.j = -1;; 

    jeu_lancer(&pJeu);
    fenetre = interfaceNcurses_initialiser();

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

        interfaceNcurses_afficherFenetreJeu(pJeu, mot, selectedCase, usedCase);
	refresh();
    ch = getch();
    } while ((ch != 'q') && (!jeu_compteurClaque(pJeu))); 
    
    interfaceNcurses_afficherBoiteDialogue(pJeu);
    interfaceNcurses_terminer(fenetre, pJeu);
}

void interfaceNcurses_afficherBoiteDialogue(const Jeu pJeu) {
    WINDOW* winBoiteDialogue;
    char* label= "Fin du jeu";
    winBoiteDialogue = newwin(12,73, 4, 0);
    win_show(winBoiteDialogue, label, 1, pJeu);
    interfaceNcurses_menu(winBoiteDialogue, pJeu);
}
void interfaceNcurses_afficherFenetreJeu(const Jeu pJeu, char* pMot, const Case pSelectedCase, Case* pUsedCase) {
    int minutes, secondes;
    
    interfaceNcurses_afficherSolution(pJeu.solutionUtilisateur);
    interfaceNcurses_afficherTitre("Jeu de Boggle");
    util_conversionTemps(jeu_tempsRestant(pJeu), &minutes, &secondes);
    mvprintw(0, 35, "Temps restant: %d min et %d secondes", minutes, secondes);
    mvprintw(1, 60, "%s", pMot);
    interfaceNcurses_afficherGrille(pJeu.plateau, pSelectedCase, pUsedCase, strlen(pMot));    
}

/* Show the window with a border and a label */
void win_show(WINDOW *win, char *label, Jeu pJeu) {	
    int startx, starty, height, width;

	getbegyx(win, starty, startx);
	getmaxyx(win, height, width);

	box(win, 0, 0);
	mvwaddch(win, 2, 0, ACS_LTEE); 
	mvwhline(win, 2, 1, ACS_HLINE, width - 2); 
	mvwaddch(win, 2, width - 1, ACS_RTEE); 
	
	print_in_middle(win, 1, 0, width, label, pJeu);
}

int interfaceNcurses_menu(WINDOW* pDialogBoxWin, const Jeu pJeu) {
    ITEM** items = calloc(3, sizeof(ITEM));
    ITEM* cur;  
    MENU* menu;
    WINDOW* winMenu;
    _Bool continuer = true;
    int c;
    int (*ptrTerminer)(char*);
    winMenu = newwin(1, 64, 14, 4);
    
    keypad(winMenu, TRUE);
    
    items[0] = new_item("1", "Quitter");
    items[1] = new_item("2", "Afficher la solution");
    items[2] = (ITEM*) NULL;
    
    set_item_userptr(items[0],func);
    set_item_userptr(items[1],func);
    menu = new_menu((ITEM**) items);
    
    set_menu_win(menu, winMenu);
    set_menu_format(menu, 1, 2);
    set_menu_mark(menu, " * ");

    post_menu(menu);
   do { 
        wrefresh(pDialogBoxWin);
        c=wgetch(winMenu);
        switch(c) {
            case KEY_LEFT:
                menu_driver(menu, REQ_LEFT_ITEM);
                break;
            case KEY_RIGHT:
                menu_driver(menu, REQ_RIGHT_ITEM);
                break;
            case 10:
                cur = current_item(menu);
                ptrTerminer = item_userptr(cur);
                if(ptrTerminer((char*)item_name(cur)) == 1) {
                    continuer = false;
                } else {
                    interfaceNcurses_afficherFenetreSolution(pJeu);
                    continuer = false;
                }
                pos_menu_cursor(menu);
                break;
        }
    } while(continuer);
}
void interfaceNcurses_afficherFenetreSolution(const Jeu pJeu) {
    WINDOW* winSolution = newwin(0,0,0,0);
    Case buff;
    buff.i = buff.j = -1;
    do {
        interfaceNcurses_afficherSolution(pJeu.plateau.solution);
        interfaceNcurses_afficherTitre("Solution de la partie");
        interfaceNcurses_afficherGrille(pJeu.plateau, buff, &buff, 0);
        wrefresh(winSolution);                    
        refresh();
    } while(getch() != 'q');

}
void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string, Jeu pJeu) {
	int length, x, y;
	float temp;
    char affichageSolution[128] = "";
    int j = 0;
    
	if(win == NULL)
		win = stdscr;
	getyx(win, y, x);
	if(startx != 0)
		x = startx;
	if(starty != 0)
		y = starty;
	if(width == 0)
		width = 80;
    
	length = strlen(string);
	temp = (width - length)/ 2;
	x = startx + (int)temp;
	mvwprintw(win, y, x, "%s", string);

    for(int i = 0 ; i < pJeu.solutionUtilisateur.nbMots ; ++i) {
        strcat(affichageSolution, pJeu.solutionUtilisateur.mots[i]);
        strcat(affichageSolution, ", ");
    }
    
	mvwprintw(win, y+4, 1, "%s", affichageSolution);
    mvwprintw(win, y+2, 1, "Vous avez obtenus %d/%d points. Voici les mots que vous avez trouves:", 
            solution_nbPoints(pJeu.solutionUtilisateur), solution_nbPoints(pJeu.plateau.solution));
    mvprintw(win, (int)y+3+j, 1, "%s", affichageSolution);
    
}

int func(char* name) {
    move(20,0);
    clrtoeol();
    if(strcmp(name, "1") == 0) {
        return 1;
    } else if(strcmp(name, "2") == 0) {
        return 2;
        // TODO afficher la solution
    }
    mvprintw(20,0, "Item selected %d", name);
    
}