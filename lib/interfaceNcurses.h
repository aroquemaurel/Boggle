/* 
 * File:   interfaceNcurses.h
 * Author: aroquemaurel
 *
 * Created on 24 avril 2013, 00:45
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

void interfaceNcurses_afficherSolution(const Solution pSolution);
void jeu_lancerModeNcurses(Jeu pJeu);
WINDOW* interfaceNcurses_initialiser(void);
void interfaceNcurses_afficherGrille(const Plateau pPlateau, const Case pSelectedCase, const Case* pUsedCase, const int pLgUsedCase);
void interfaceNcurses_terminer(WINDOW* fenetre);
void jeu_lancerModeNcurses(Jeu pJeu);

#endif	/* INTERFACENCURSES_H */

