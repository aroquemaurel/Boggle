/* 
 * File:   interfaceNcurses.h
 * Author: aroquemaurel
 *
 * Created on 24 avril 2013, 00:45
 */

#ifndef INTERFACENCURSES_H
#define	INTERFACENCURSES_H
#include "plateau.h"
#include "jeu.h"
#include "case.h"
#define COULEUR_SELECTION_CASE 1
#define COULEUR_CASE_CHOISI 2


void interfaceNcurses_afficherPlateau(const Plateau pPlateau, Case pCase);

void jeu_lancerModeNcurses(Jeu pJeu);


#endif	/* INTERFACENCURSES_H */

