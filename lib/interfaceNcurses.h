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

typedef struct {
    unsigned char i;
    unsigned char j;
} Case;

void interfaceNcurses_afficherPlateau(const Plateau pPlateau, Case pCase);

void jeu_lancerModeNcurses(Jeu pJeu);


#endif	/* INTERFACENCURSES_H */

