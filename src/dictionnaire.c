/**
 * \file dictionnaire.c
 * \brief Gestion du dictionnaire
 * Fonctions de gestion du dictionnaire, le dictionnaire doit être dans un fichier
 * texte avec un mot différent par ligne.
 */

#include <string.h>
#include <stdlib.h>
#include "dictionnaire.h"
#include "util.h"

/**
 * Créer un nouveau dictionnaire à partir d'un fichier
 * @param pNomFichier Le fichier contenant les mots du dictionnaire.
 * @return Le nouveau dictionnaire
 */
Dico dictionnaire_nouveau(const char* pNomFichier) {
    Dico nouveauDico;
    long int test;
    int i = 0;
    char buff[32];
    char caractereCourant = '\0';
    nouveauDico.dico = fopen(pNomFichier, "r+");
    if(nouveauDico.dico == NULL) {
        perror("Le nom de fichier du dictionnaire n'existe pas");
        exit(1);
    }
    rewind(nouveauDico.dico);
    while (fgets(buff, 30, nouveauDico.dico) != NULL) {
        if(caractereCourant != buff[0]) {
            caractereCourant = buff[0];
            nouveauDico.marqueurs[i] = ftell(nouveauDico.dico);
            ++i;
        }
     }      
    nouveauDico.marqueurs[i] = ftell(nouveauDico.dico);

    return nouveauDico;
}


/** 
 * Permet de savoir si un mot est présent dans le dictionnaire
 * @param pDictionnaire Le dictionnaire dans lequel chercher
 * @param pMot Le mot à chercher
 * @return 0 si le mot est absent, 1 si des mots commencent par pMot et 10 si le mot exact est trouvé.
 * */
int dictonnaire_motDansDico(Dico pDictionnaire, char* pMot) {
    char buff[256];
    char buff2[256];
    int retour;

    dictionnaire_rechercheDichotomique(pDictionnaire, pMot, buff);
    if(strcmp(buff, pMot) == 0) {
        retour = 10;    // C'est lot mot exact
    } else { //FIXME Mots en diagonale.
        util_substr(buff,0,strlen(pMot)-1,buff2); // on regarde si la racine du mot correspond à notre mot
        if(strlen(pMot) <= strlen(buff2)) {            
            if(strcmp(pMot, buff2) == 0) {
                retour = 1;
            } else {
                retour = 0;
            }
        } else {
            retour = 0;
        }
    }

    return (retour); 
}

/**
 * Effectue une recherche dichotomique de pMotAChercher dans le dictionnaire
 * @param pDictionnaire Le dictionnaire dans lequel chercher
 * @param pMotAChercher Le mot à chercher
 * @param pMotLePlusProche Le mot le plus proche trouvé, si pMotLePlusProche == pMotAChercher, il est présent dans le dictionnaire
 */
void dictionnaire_rechercheDichotomique(Dico pDictionnaire, char* pMotAChercher, char* pMotLePlusProche) {
    long int debut = pDictionnaire.marqueurs[pMotAChercher[0]-65];
    long int fin = pDictionnaire.marqueurs[(pMotAChercher[0]-65)+1];
    long int milieu = 0;
    int cmp;
    while(debut < fin) {    
        milieu = (debut + fin) /2;
        fseek(pDictionnaire.dico, milieu, SEEK_SET);    
        util_deplacerCurseurDunMot(pDictionnaire.dico, MOT_PRECEDENT);
        
        fgets(pMotLePlusProche, 30, pDictionnaire.dico);
        pMotLePlusProche[strlen(pMotLePlusProche)-2] = '\0';
        
        cmp = strcmp(pMotLePlusProche, pMotAChercher);
        if(cmp == 0) {
            break; // FIXME break complètement dégueulasse. Attendre tests unitaires
        } else if (cmp < 0) {// T[m] < X
            debut = ftell(pDictionnaire.dico);
        } else { 
            fseek(pDictionnaire.dico, -2, SEEK_CUR);
           util_deplacerCurseurDunMot(pDictionnaire.dico, MOT_PRECEDENT); 
            fin = ftell(pDictionnaire.dico); 
        }
    } 
    printf("\n\n");
}