/* 
 * File:   resolveur.h
 * Author: aroquemaurel
 *
 * Created on 8 mars 2013, 11:05
 */

#ifndef RESOLVEUR_H
#define	RESOLVEUR_H

#include "dictionnaire.h"
typedef enum{   HAUT, BAS, GAUCHE, DROITE, 
                DIAGO_HAUT_GAUCHE, DIAGO_HAUT_DROITE, 
                DIAGO_BAS_GAUCHE, DIAGO_BAS_DROITE
} Deplacement;

_Bool resolveur_deplacementPossible(const Deplacement pDeplacement, const Plateau pPlateau, const int i, const int j);
void resolveur(Plateau* pPlateau, char* choices, Dico pDico);

#endif	/* RESOLVEUR_H */

