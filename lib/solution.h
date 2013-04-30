/**
 * \file solution.h
 * \brief Gère la solution d'une grille de boggle
 * Toutes les fonctions se rapportant à la solution d'une grille
 * \see plateau
 */
#ifndef SOLUTION_H
#define	SOLUTION_H

/**
 * \struct Solution
 * \brief Solution du jeu
 * Contient une solution pour une grille de Boggle
 */
typedef struct {
    char** mots; /*!< Les mots présents dans la solution */
    unsigned int nbMots; /*!< Le nombre de mots que contient la solution */
} Solution;

Solution solution_creer(void);
void solution_ajouterMot(Solution* pSolution, const char* mot);
void solution_afficher(const Solution pSolution);
void solution_detruire(Solution* pSolution);
_Bool solution_motEstPresent(const Solution pSolution, const char* pMot);
int solution_nbPoints(Solution pSolution);
#endif	/* SOLUTION_H */

