/** *
 * \file case.h
 * \brief Structure de données d'une case
 * Structure de données d'une case du plateau.
 */

#ifndef CASE_H
#define	CASE_H
/**
 * \struct Case
 * \brief Une case de la grille
 */
typedef struct {
    unsigned char x; /*!< Premier nombre du couple */
    unsigned char y; /*!< Second nombre du couple */
} Couple;

#endif	/* CASE_H */

