/**
 * \file plateau.h
 * \brief Gestion du plateau de Jeu
 * Fonctions se rapportant à un plateau de jeu, sera sert à gérer la grille de Boggle
 */

#ifndef PLATEAU_H
#define PLATEAU_H

#include "solution.h"
#include "couple.h"
#define TAILLE_MOT_MIN 3
#define TAILLE_MOT_MAX 32

/**
 * \struct Plateau
 * \brief Grille du jeu
 * Contient une grille permettant de jouer au Boggle
 */ 
typedef struct {
    char** grille; /*!< La grille de boggle */
    Couple tailleGrille; /*!< La taille de la grille */
    int** grid;
    Solution solution; /*!< La solution complète de cette grille de Boggle */
} Plateau ;

Plateau plateau_nouveau(const Couple pTailleGrille);
void plateau_remplirGrilleAleatoire(Plateau* pPlateau);
void plateau_remplirGrillePredefinie(Plateau* pPlateau);
double plateau_probaLettre(const char pLettre);
char plateau_choisirLettre(void);
void plateau_detruire(Plateau* pPlateau);
#endif	/* PLATEAU_H */

