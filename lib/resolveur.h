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
#include "jeu.h"

void resolveTouteLaGrille(Plateau* pPlateau, Dico pDico);
Solution resolveur_resolveUneCase(Plateau pPlateau, Dico pDico, Couple pCase);
void jeu_lancerModeSolveur(Jeu pJeu, _Bool pGrillePredefinie);
#endif	/* RESOLVEUR_H */

