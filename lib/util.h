/** 
 * \file util.h
 */

#ifndef UTIL_H
#define	UTIL_H

#include <stdio.h>
#include <time.h>
#include "case.h"
#define MODE_DEBUG 1 
#define MOT_PRECEDENT 1
#define MOT_SUIVANT 1

void util_affichageDebug(const char* pNomFonction, const char* pChaine);
char* util_supprimerAccents(const char* pChaine);
char util_nbAleatoire(const char pDebut, const char pFin);

/* Retourne le nombre de caractères lus */
int util_substr(const char *chaine, int debut, int fin, char *result);
void util_echanger(char* tableau[], int a, int b);
void util_quickSort(char* tableau[], int debut, int fin);

void util_deplacerCurseurDunMot(FILE* pFichier, const int pSens);
_Bool util_isInArray(const Case* pTableau, const int pTaille, const Case pCase);
void util_conversionTemps(const time_t pTimestamp, int* pMinutes, int* pSecondes);

#endif	/* UTIL_H */

