/* 
 * File:   util.h
 * Author: aroquemaurel
 *
 * Created on 8 mars 2013, 11:39
 */

#ifndef UTIL_H
#define	UTIL_H

#define MODE_DEBUG 1 

inline void util_affichageDebug(const char* pNomFonction, const char* pChaine);
char* util_supprimerAccents(const char* pChaine);
char util_nbAleatoire(const char pDebut, const char pFin);
/* *
 * Retourne le nombre de caractères lus */
int util_substr(const char *chaine, int debut, int fin, char *result);
#endif	/* UTIL_H */

