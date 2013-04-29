#include <string.h>
#include <wchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "util.h"
#include "jeu.h"
#include "case.h"

 void util_affichageDebug(const char* pNomFonction, const char* pChaine) {
    if(MODE_DEBUG) {
        printf("[%s]: %s", pNomFonction, pChaine);
    }
}
void util_afficherTableAscii(void) {
    for (int i = 0 ; i < 256 ; ++i) {
        printf("%c : %d\n", i, i);
    }
}
char* util_supprimerAccents(const char* pChaine) {
    char* retour = malloc(100*sizeof(char));
    wchar_t* buffer = malloc(100*sizeof(wchar_t));
    mbstowcs(buffer,pChaine,100);

    for(int i=0 ;  i < wcslen(buffer) ; ++i) {
        switch(buffer[i]) {
            case L'é':
            case L'è':
            case L'ê':
            case L'ë':              
                retour[i] = 'e';
                break;
            case L'É':
            case L'È':
            case L'Ê':
                retour[i] = 'E';
                break;
            case L'À':
                retour[i] = 'A';
                break;
            case L'ô':
            case L'ö':
                retour[i] = 'o';
                break;
            case L'à':
            case L'â':
                retour[i] = 'a';
                break;
            case L'ù':
                retour[i] = 'u';
                break;
            case L'î':
            case L'ï':
                retour[i] = 'i';
                break;
            default:
                retour[i] = pChaine[i];
        }
    }

    return retour;
}
void util_uppercase(char* pChaine) { // FIXME vérifier que le mot n'est pas en majuscule
	for(int i = 0 ; i  < strlen(pChaine) ; ++i) {
            if(pChaine[i] >= 'a' && pChaine[i] <= 'z') {
		pChaine[i] -= 32;
            }
	}
}
char util_nbAleatoire(const char pDebut, const char pFin) {
    static bool premier = true;
    if(premier) {
        srand(time(NULL));
        premier = false;
    }
        return rand() % (pFin + 1 - pDebut) + pDebut;
}

int util_substr(const char *chaine, int debut, int fin, char *result) {  
	result[fin+1-debut]='\0';
	memcpy(result,(char *)chaine+debut,fin+1-debut); 

	return (fin+1-debut);
}

void util_echanger(char* tableau[], int a, int b) {
    char* temp = tableau[a];
    tableau[a] = tableau[b];
    tableau[b] = temp;
}
 
void util_quickSort(char* tableau[], int debut, int fin) {
    int gauche = debut-1;
    int droite = fin+1;
    const char* pivot = tableau[debut];
 
    if(debut >= fin)
        return;
 
    while(1) {
        do droite--; while(strcmp(tableau[droite],pivot) > 0);
        do gauche++; while(strcmp(tableau[gauche], pivot) < 0);
 
        if(gauche < droite)
            util_echanger(tableau, gauche, droite);
        else break;
    }
 
    util_quickSort(tableau, debut, droite);
    util_quickSort(tableau, droite+1, fin);
}

void util_deplacerCurseurDunMot(FILE* pFichier, const int pSens) {
    int deplacement = (pSens == MOT_PRECEDENT) ? -1 : 1;
        fseek(pFichier, deplacement, SEEK_CUR); 
    while( fgetc(pFichier) != '\r') {
        fseek(pFichier, deplacement-1, SEEK_CUR); 
    } 
    fseek(pFichier, 1, SEEK_CUR);

}

_Bool util_isInArray(const Case* pTableau, const int pTaille, const Case pCase) {
    for(int i = 0 ; i < pTaille ; ++i) {
        if(pTableau[i].i == pCase.i && pTableau[i].j == pCase.j) {
            return true;
        }
    }
    
    return false;
}

void util_conversionTemps(const time_t pTimestamp, int* pMinutes, int* pSecondes) {
    *pMinutes = (pTimestamp / 60 % 60);
    *pSecondes  = pTimestamp % 60;
}
