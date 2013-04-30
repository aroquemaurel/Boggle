/**
 * \file resolveur.h
 * \brief Gestion du résolveur
 * Permet de résoudre une grille de Boggle, une fois résolue, la solution se trouve dans
 * le module Solution
 */

#ifndef RESOLVEUR_H
#define	RESOLVEUR_H
#include "plateau.h"
#include "dictionnaire.h"

void resolveur(Plateau* pPlateau, Dico pDico);

#endif	/* RESOLVEUR_H */

