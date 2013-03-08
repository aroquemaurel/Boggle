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

typedef FILE* Dico;

Dico dictionnaire_nouveau(const char* pNomFichier);
bool dictonnaire_motEstPresent(Dico pDictionnaire, const char* pMot);
double dictionnaire_probaLettre(const char pLettre);
#endif	/* DICTIONNAIRE_H */

