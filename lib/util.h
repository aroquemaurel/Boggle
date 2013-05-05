/** 
 * \file util.h
 * \brief Fonctions utiles à l'ensemble du projet
 * Toutes les fonctions de bases utiles au projet, ces fonctions travaillent 
 * sur des types de bae et ne sont pas spécfiques au projet, ce module permet de meux organiser le code
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
int util_substr(const char *chaine, int debut, int fin, char *result);
void util_echanger(void** tableau, int a, int b);
void util_quickSort(void** tableau, int debut, int fin);
void util_deplacerCurseurDunMot(FILE* pFichier, const int pSens);
_Bool util_isInArray(const Case* pTableau, const int pTaille, const Case pCase);
void util_conversionTemps(const time_t pTimestamp, int* pMinutes, int* pSecondes);

#endif	/* UTIL_H */

