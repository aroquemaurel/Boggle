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
    unsigned char i; /*!< Abscisse */
    unsigned char j; /*!< ordonnée */
} Case;

#endif	/* CASE_H */

