/**
 * \file interfaceNcurses.h
 * \brief Affichage avec la bibliothèque Ncurses
 * Affiche et permet de jouer au jeu de Boggle avec un affichage utilisant la bibliothèque Ncurses
 */

#ifndef INTERFACENCURSES_H
#define	INTERFACENCURSES_H
#include <ncurses.h>
#include "solution.h"
#include "case.h"
#include "plateau.h"
#include "jeu.h"
#include "case.h"
#define COULEUR_SELECTION_CASE 1
#define COULEUR_CASE_CHOISI 2
#define NB_LIGNES 25

void interfaceNcurses_afficherTitre(const char* pTitle);
void interfaceNcurses_afficherSolution(const Solution pSolution);
void jeu_lancerModeNcurses(Jeu pJeu);
WINDOW* interfaceNcurses_initialiser(void);
void interfaceNcurses_afficherGrille(const Plateau pPlateau, const Case pSelectedCase, const Case* pUsedCase, const int pLgUsedCase);
void interfaceNcurses_terminer(WINDOW* fenetre, Jeu pJeu);
void interfaceNcurses_afficherFenetreJeu(const Jeu pJeu, char* pMot, const Case pSelectedCase, Case* pUsedCase);
void interfaceNcurses_afficherBoiteDialogue(const Jeu pJeu);
void interfaceNcurses_afficherFenetreSolution(const Jeu pJeu);
void interfaceNcurses_menu(WINDOW* pDialogBoxWin, const Jeu pJeu);
#endif	/* INTERFACENCURSES_H */

