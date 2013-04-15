/* 
 * File:   dictionnaire.h
 * Author: aroquemaurel
 *
 * Created on 8 mars 2013, 11:04
 */

#ifndef DICTIONNAIRE_H
#define	DICTIONNAIRE_H
#include <stdio.h>
#include <stdbool.h>

typedef struct {
    FILE* dico;
    long int marqueurs[32];
} Dico;

Dico dictionnaire_nouveau(const char* pNomFichier);
Dico dictionnaire_positionnerMarqueurs(Dico* pDico);
int dictonnaire_motDansDico(Dico pDictionnaire, char* pMot);
void dictionnaire_rechercheDichotomique(Dico pDictionnaire, 
                                        char* pMotAChercher, 
                                        char* pMotLePlusProche);
#endif	/* DICTIONNAIRE_H */

