/**
 * \file dictionnaire.h
 * \brief Gestion du dictionnaire
 * Fonctions de gestion du dictionnaire, le dictionnaire doit être dans un fichier
 * texte avec un mot différent par ligne.
 */


#ifndef DICTIONNAIRE_H
#define	DICTIONNAIRE_H
#include <stdio.h>
#include <stdbool.h>

/**
 * \struct Dico
 * \brief Dictionnaire
 * Contient le dictionnaire du jeu.
 */
typedef struct {
    FILE* dico; /*!< Fichier contenant le dictionnaire, celui-ci doit être un fichier texte avec un mot par ligne*/
    long int marqueurs[32]; /*!< Contient les positions de chacunes des lettres de l'alphabets dans le fichier */
} Dico;

Dico dictionnaire_nouveau(const char* pNomFichier);
Dico dictionnaire_positionnerMarqueurs(Dico* pDico);
int dictonnaire_motDansDico(Dico pDictionnaire, char* pMot);
void dictionnaire_rechercheDichotomique(Dico pDictionnaire, 
                                        char* pMotAChercher, 
                                        char* pMotLePlusProche);
#endif	/* DICTIONNAIRE_H */

