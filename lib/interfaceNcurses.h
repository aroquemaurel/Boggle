/**
 * \file interfaceNcurses.h
 * \brief Affichage avec la bibliothèque Ncurses
 * Affiche et permet de jouer au jeu de Boggle avec un affichage utilisant la bibliothèque Ncurses
 */

#ifndef INTERFACENCURSES_H
#define	INTERFACENCURSES_H
#include <ncurses.h>
#include "solution.h"
#include "couple.h"
#include "plateau.h"
#include "jeu.h"
#include "couple.h"
#define COULEUR_SELECTION_CASE 1
#define COULEUR_CASE_CHOISI 2
#define NB_LIGNES 25

/** 
 * Direction d'un déplacement
 */
typedef enum {GAUCHE, DROITE, HAUT, BAS, NEANT} Direction;

void interfaceNcurses_afficherTitre(const char* pTitle);
void interfaceNcurses_afficherSolution(const Solution pSolution);
void jeu_lancerModeNcurses(Jeu pJeu, _Bool pGrillePredefinie);
WINDOW* interfaceNcurses_initialiser(void);
void interfaceNcurses_afficherGrille(const Plateau pPlateau, const Couple pSelectedCase, const Couple* pUsedCase, const int pLgUsedCase);
void interfaceNcurses_terminer(WINDOW* fenetre, Jeu pJeu);
void interfaceNcurses_afficherFenetreJeu(const Jeu pJeu, char* pMot, const Couple pSelectedCase, Couple* pUsedCase);
void interfaceNcurses_afficherBoiteDialogue(const Jeu pJeu);
void interfaceNcurses_afficherFenetreSolution(const Jeu pJeu);
void interfaceNcurses_menu(WINDOW* pDialogBoxWin, const Jeu pJeu);
void interfaceNcurses_selectionnerLettre(char* pMot, const Couple pSelectedCase, Couple* pLastChoseCase, Plateau pPlateau, Couple* pUsedCase);
void interfaceNcurses_proposerMot(char* pMot, Jeu* pJeu, Couple* pLastChoseCase);
void interfaceNcurses_deplacerCurseur(Couple* pSelectedCase, const Couple pLastChoseCase, const char* pMot, const Couple pTailleGrille, const Direction pDirection);

#endif	/* INTERFACENCURSES_H */

