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
#include "couple.h"

#define MODE_DEBUG 1 
#define MOT_PRECEDENT 1
#define MOT_SUIVANT 1

void util_affichageDebug(const char* pNomFonction, const char* pChaine);
char* util_supprimerAccents(const char* pChaine);
char util_nbAleatoire(const char pDebut, const char pFin);
int util_substr(const char *chaine, int debut, int fin, char *result);
void util_echanger(void** tableau, int a, int b);
void util_quickSort(void** tableau, int debut, int fin, int (*fctCmp)(void*,void*));
void util_deplacerCurseurDunMot(FILE* pFichier, const int pSens);
_Bool util_isInArray(const Couple* pTableau, const int pTaille, const Couple pCase);
void util_conversionTemps(const time_t pTimestamp, int* pMinutes, int* pSecondes);
int util_strcmp(void* str1, void* str2);
int util_cherchePremiereOccurenceDansTableau(char** pTableau, const int pTaille, char* pRecherche) ;
void util_nettoyerConsole(void);
int util_lireChaine(char *chaine, int longueur);
void util_uppercase(char* pChaine);
#endif	/* UTIL_H */

