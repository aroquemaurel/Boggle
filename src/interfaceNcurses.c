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
#include "resolveur.h"

int fctMenu(char* name);

/**
 * Afficher un titre à la fenêtre
 * @param pTitle Le titre à afficher
 */
void interfaceNcurses_afficherTitre(const char* pTitle) {
    mvprintw(0, 4, "==== %s ====", pTitle);
    mvprintw(1, 4, "Pressez la touche q pour sortir");
}

/**
 * Affiche la solution passée en paramètre
 * @param pSolution La solution à afficher
 */
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

/**
 * Initialise l'interface Ncurses
 * @return La fenêtre créée
 */
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

/**
 * Affiche la grille, composée de couleurs en fonctions des différentes cases
 * @param pPlateau La grille à afficher
 * @param pSelectedCase La case séléctionnée
 * @param pUsedCase Les cases utilisés pour le mot courant
 * @param pLgUsedCase La longueur du mot courant
 */
void interfaceNcurses_afficherGrille(const Plateau pPlateau, const Couple pSelectedCase, 
                                    const Couple* pUsedCase, const int pLgUsedCase) {
    Couple buff;
    
    for (int j = 0 ; j < pPlateau.tailleGrille.x ; ++j) {
         for(int i = 0 ; i < pPlateau.tailleGrille.y ; ++i) {
             buff.x = i;
             buff.y = j;
             if(util_isInArray(pUsedCase, pLgUsedCase+1, buff)) {
                attron(COLOR_PAIR(COULEUR_CASE_CHOISI));
             }             
             if((pSelectedCase.x == i) && (pSelectedCase.y ==j)) {
            	attron(COLOR_PAIR(COULEUR_SELECTION_CASE));
             }
             mvprintw(i+6, j*3+5, " %c ", pPlateau.grille[j][i]);
            
            attroff(COLOR_PAIR(COULEUR_SELECTION_CASE));
            attroff(COLOR_PAIR(COULEUR_CASE_CHOISI));
       }
     }
    for(int i = 3 ; i < NB_LIGNES - 2; ++i) {
        mvprintw(i, pPlateau.tailleGrille.x*3+7, "");         //FIXME .x
        addch(ACS_VLINE);
    }
}

/**
 * Termine le jeu
 * @param fenetre La fenêtre à détruire
 * @param pJeu le jeu à terminer
 */
void interfaceNcurses_terminer(WINDOW* fenetre, Jeu pJeu) {
    delwin(fenetre);
    endwin();
    refresh();
    jeu_stopper(pJeu);
}

void interfaceNcurses_deplacerCurseur(Couple* pSelectedCase, const Couple pLastChoseCase, const char* pMot, const Couple pTailleGrille, const Direction pDirection) {
    switch(pDirection) {
        case GAUCHE:
            if((strlen(pMot) == 0) || (pSelectedCase->y == pLastChoseCase.y) || (pSelectedCase->y == pLastChoseCase.y+1)) {
                pSelectedCase->y = (pSelectedCase->y-1 >= 0) ? pSelectedCase->y-1 : pSelectedCase->y;
            }
            break;
        case DROITE:
            if((strlen(pMot) == 0) || (pSelectedCase->y == pLastChoseCase.y) || (pSelectedCase->y == pLastChoseCase.y-1)) {
                pSelectedCase->y = (pSelectedCase->y+1 < pTailleGrille.x) 
                                        ? pSelectedCase->y+1 : pSelectedCase->y;
            }
            break;
        case HAUT:
            if((strlen(pMot) == 0) || (pSelectedCase->x == pLastChoseCase.x) || (pSelectedCase->x == pLastChoseCase.x+1)) {
            pSelectedCase->x = (pSelectedCase->x-1 >= 0) 
                        ? pSelectedCase->x-1 : pSelectedCase->x;                
            }
            break;
        case BAS:
            if((strlen(pMot) == 0) || (pSelectedCase->x == pLastChoseCase.x) || (pSelectedCase->x == pLastChoseCase.x-1)) {
                pSelectedCase->x = (pSelectedCase->x+1 < pTailleGrille.y) 
                        ? pSelectedCase->x+1 : pSelectedCase->x;
            }
            break;
    }
}

void interfaceNcurses_proposerMot(char* pMot, Jeu* pJeu, Couple* pLastChoseCase) {
    mvprintw(1, 60, "%s", pMot);
    mvprintw(2, 60, "%s", (jeu_proposerMot(pJeu, pMot) ? "Mot correct" : "Mot Incorrect"));

    for(int i = 0 ; i < 31 ; ++i) {
        pMot[i] = '\0';
    }
    pLastChoseCase->x = -1;
    pLastChoseCase->y = -1;
}

void interfaceNcurses_selectionnerLettre(char* pMot, const Couple pSelectedCase, 
                                        Couple* pLastChoseCase, Plateau pPlateau,
                                        Couple* pUsedCase) {
    if(((pSelectedCase.x != pLastChoseCase->x) || (pSelectedCase.y != pLastChoseCase->y))
            && (!util_isInArray(pUsedCase, strlen(pMot)+1, pSelectedCase))) {
        pMot[strlen(pMot)] = pPlateau.grille[pSelectedCase.y][pSelectedCase.x];
        pUsedCase[strlen(pMot)] = pSelectedCase;
        mvprintw(0, 50, "%s", pMot);
        *pLastChoseCase = pSelectedCase;
    }
}
/**
 * Lance le mode Ncurses
 * @param pJeu Le jeu à lancer
 */
void jeu_lancerModeNcurses(Jeu pJeu) {
    Couple selectedCase;
    Couple lastChoseCase;
    Couple usedCase[32];
    Direction direction = NEANT;
    WINDOW* fenetre;
    char mot[32] = "";
    char buff[32];
    int ch;

    selectedCase.x = 0;
    selectedCase.y = 0;
    lastChoseCase.x = -1;
    lastChoseCase.y = -1;; 

    jeu_lancer(&pJeu, false);
    fenetre = interfaceNcurses_initialiser();

    do {
        clear();
        switch(ch) {
            case KEY_LEFT:
                direction = GAUCHE;
            break;
            case KEY_RIGHT:
                direction = DROITE;
                break;
            case KEY_UP:
                direction = HAUT;
                break;
            case KEY_DOWN:
                direction = BAS;
                break;
            case 'h':
                mvprintw(2,55, "%d mots possibles", (resolveur_resolveUneCase(pJeu.plateau, pJeu.dico, selectedCase)).nbMots);
                break;
            case ' ':  //touche espace
                interfaceNcurses_selectionnerLettre(mot,selectedCase,&lastChoseCase,pJeu.plateau, usedCase);
                break;
            case '\n': // Touche entrée 
                interfaceNcurses_proposerMot(mot, &pJeu, &lastChoseCase);
                break;
            default:
                break;
        }
        if(ch != ' ' && ch != '\n') {
            interfaceNcurses_deplacerCurseur(&selectedCase, lastChoseCase, mot,
                                                 pJeu.plateau.tailleGrille, direction);                                                
        }

        interfaceNcurses_afficherFenetreJeu(pJeu, mot, selectedCase, usedCase);
	refresh();
    ch = getch();
    } while ((ch != 'q') && (!jeu_compteurClaque(pJeu))); 
    
    interfaceNcurses_afficherBoiteDialogue(pJeu);
    interfaceNcurses_terminer(fenetre, pJeu);
}

/**
 * Affiche une boite de dialogue de fin de Jeu
 * @param pJeu Le jeu 
 */
void interfaceNcurses_afficherBoiteDialogue(const Jeu pJeu) {
    WINDOW* winBoiteDialogue;
    char* label= "Fin du jeu";
    winBoiteDialogue = newwin(12,73, 4, 0);
    win_show(winBoiteDialogue, label, 1, pJeu);
    interfaceNcurses_menu(winBoiteDialogue, pJeu);
}

/**
 * Affiche la fenêtre permettant de jouer
 * @param pJeu Le jeu
 * @param pMot Le mot courant
 * @param pSelectedCase La case séléctionnée
 * @param pUsedCase Les cases utilisés pour créer le mot pMot
 */
void interfaceNcurses_afficherFenetreJeu(const Jeu pJeu, char* pMot, const Couple pSelectedCase, Couple* pUsedCase) {
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

/**
 * Affiche un menu permettant de choisir entre quitter et afficher la solution
 * @param pDialogBoxWin La fenêtre danslequel s'affiche le menu
 * @param pJeu Le jeu
 * @return 
 */
void interfaceNcurses_menu(WINDOW* pDialogBoxWin, const Jeu pJeu) {
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
    
    set_item_userptr(items[0],fctMenu);
    set_item_userptr(items[1],fctMenu);
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
            default:
                break;
        }
    } while(continuer);
}

/**
 * Affiche la fenêtre avec la solution complète du jeu
 * @param pJeu Le jeu
 */
void interfaceNcurses_afficherFenetreSolution(const Jeu pJeu) {
    WINDOW* winSolution = newwin(0,0,0,0);
    Couple buff;
    buff.x = buff.y = -1;
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
    
	if(win == NULL) {
		win = stdscr;
    }
	getyx(win, y, x);
	if(startx != 0) {
		x = startx;
    }
	if(starty != 0) {
		y = starty;
    }
	if(width == 0) {
		width = 80;
    }
    
	length = strlen(string);
	temp = (width - length)/ 2;
	x = startx + (int)temp;
	mvwprintw(win, y, x, "%s", string);

    for(int i = 0 ; i < pJeu.solutionUtilisateur.nbMots ; ++i) {
        strncat(affichageSolution, pJeu.solutionUtilisateur.mots[i], strlen(pJeu.solutionUtilisateur.mots[i]));
        strncat(affichageSolution, ", ", 4);
    }
    
	mvwprintw(win, y+4, 1, "%s", affichageSolution);
    mvwprintw(win, y+2, 1, "Vous avez obtenus %d/%d points. Voici les mots que vous avez trouves:", 
            solution_nbPoints(pJeu.solutionUtilisateur), solution_nbPoints(pJeu.plateau.solution));
    mvprintw(win, (int)y+3+j, 1, "%s", affichageSolution);
    
}

/**
 * Retourne le numéro de l'item appelé
 * @param Le nom de l'item
 * @return Le numéro de l'item appelé
 */
int fctMenu(char* name) {
    move(20,0);
    clrtoeol();
    if(strcmp(name, "1") == 0) {
        return 1;
    } else if(strcmp(name, "2") == 0) {
        return 2;
    }
}