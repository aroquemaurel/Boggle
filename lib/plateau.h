/* 
 * File:   plateau.h
 * Author: aroquemaurel
 *
 * Created on 8 mars 2013, 11:05
 */

#ifndef PLATEAU_H
#define	PLATEAU_H
#include "solution.h"
#define TAILLE_MOT_MIN 3
#define TAILLE_MOT_MAX 32

typedef struct {
    char** grille;
    unsigned int tailleGrille;
    int** grid;
    Solution solution;
} Plateau ;

Plateau plateau_nouveau(const unsigned char pTailleGrille);
void plateau_remplirGrilleAleatoire(Plateau* pPlateau);
void plateau_remplirGrillePredefinie(Plateau* pPlateau);
double plateau_probaLettre(const char pLettre);
char plateau_choisirLettre(void);
Plateau plateau_detruire(Plateau* pPlateau);
#endif	/* PLATEAU_H */

