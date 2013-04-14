/* 
 * File:   plateau.h
 * Author: aroquemaurel
 *
 * Created on 8 mars 2013, 11:05
 */

#ifndef PLATEAU_H
#define	PLATEAU_H
#define TAILLE_MOT_MIN 3
#define TAILLE_MOT_MAX 32
typedef struct {
    char** grille;
    unsigned int tailleGrille;
    int** grid;
} Plateau ;

Plateau plateau_nouveau(const unsigned int pTailleGrille);
void plateau_remplirGrilleAleatoire(Plateau* pPlateau);
void plateau_remplirGrillePredefinie(Plateau* pPlateau);
double plateau_probaLettre(const char pLettre);
char plateau_choisirLettre(void);

#endif	/* PLATEAU_H */

