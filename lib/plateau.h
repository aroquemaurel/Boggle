/* 
 * File:   plateau.h
 * Author: aroquemaurel
 *
 * Created on 8 mars 2013, 11:05
 */

#ifndef PLATEAU_H
#define	PLATEAU_H

typedef struct {
    char** grille;
    unsigned int tailleGrille;
} Plateau ;

Plateau plateau_nouveau(const unsigned int pTailleGrille);
void plateau_remplirGrilleAleatoire(Plateau* pPlateau);
#endif	/* PLATEAU_H */
