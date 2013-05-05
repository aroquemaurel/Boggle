/**
 * \file util.c
 * \brief Fonctions utiles à l'ensemble du projet
 * Toutes les fonctions de bases utiles au projet, ces fonctions travaillent 
 * sur des types de bae et ne sont pas spécfiques au projet, ce module permet de meux organiser le code
 */

#include <string.h>
#include <wchar.h>
#include <stdlib.h>
#include <stdbool.h>

#include "util.h"
#include "jeu.h"
#include "case.h"

/**
 * Affiche une chaine de caractère sur la console uniquement si le define MODE_DEBUG est vrai
 * @param pNomFonction Le nom de la fonction de laquelle est appellée cette fonction
 * @param pChaine La chaine de caractère à afficher
 */
 void util_affichageDebug(const char* pNomFonction, const char* pChaine) {
    if(MODE_DEBUG) {
        printf("[%s]: %s", pNomFonction, pChaine);
    }
}

 /**
  * Affiche la tableau ASCII
  */
 void util_afficherTableAscii(void) {
    for (int i = 0 ; i < 256 ; ++i) {
        printf("%c : %d\n", i, i);
    }
}

 /**
  * Supprime les accents d'une chaine de caratère
  * @param pChaine La chaine de caractère avec les accents
  * @return La nouvelle chaine de caractère sans accents
  */
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
                break;
        }
    }

    return retour;
}

/**
 * Modifie la chaine de caractère afin qu'elle soit en majuscule
 * @param pChaine La chaine de caractère à modifier
 */
void util_uppercase(char* pChaine) { // FIXME vérifier que le mot n'est pas en majuscule
	for(int i = 0 ; i  < strlen(pChaine) ; ++i) {
            if((pChaine[i] >= 'a') && (pChaine[i] <= 'z')) {
		pChaine[i] -= 32;
            }
	}
}

/**
 * Retourne un nombre aléatoire entre pDebut et pFin
 * @param pDebut la borne inférieur
 * @param pFin la borne supérieur
 * @return Le nombre généré
 */
char util_nbAleatoire(const char pDebut, const char pFin) {
    static bool premier = true;
    if(premier) {
        srand(time(NULL));
        premier = false;
    }
        return rand() % (pFin + 1 - pDebut) + pDebut;
}

/**
 * Créer une sous-chaine de caractère de chaine depuis début jusqu'à fin
 * @param chaine La chaine sur laquelle s'applique la fonction
 * @param debut Le début du découpage
 * @param fin La fin du découpage
 * @param result La chaine résultat
 * @return La taille de la chaine résultat
 */
int util_substr(const char* chaine, int debut, int fin, char* result) {  
	result[fin+1-debut]='\0';
	memcpy(result,(char *)chaine+debut,fin+1-debut); 

	return (fin+1-debut);
}

/**
 * Echange deux variables dans un tableau de chaine de caractères
 * @param tableau Le tableau sur laquelle on effectue l'échange, tableau de n'importe quel type d'éléments.
 * @param a La première valeure à échanger
 * @param b La seconde valeure
 */
void util_echanger(void** tableau, int a, int b) {
    void* temp = tableau[a];
    tableau[a] = tableau[b];
    tableau[b] = temp;
}
 
/**
 * Effectue un tri sur une porition d'un tableau de chaine de caractère s.
 * Ce tri utilise l'algorithme du tri rapide.
 * @param tableau Le tableau à trier. Les éléments sont de n'importes quels type.
 * @param debut Le début du tableau à trier
 * @param fin La fin du tableau à trier
 */
void util_quickSort(void** tableau, int debut, int fin) { // TODO ajouter foncteur de comparaison
    int gauche = debut-1;
    int droite = fin+1;
    const void* pivot = tableau[debut];
 
    if(debut < fin)  {
        do { 
            do {
                droite--; 
            } while(util_strcmp(tableau[droite], pivot) > 0);
            do {
                gauche++; 
            } while(util_strcmp(tableau[gauche], pivot) < 0);

            if(gauche < droite) {
                util_echanger(tableau, gauche, droite);
            } 
        } while(gauche < droite);

        util_quickSort(tableau, debut, droite);
        util_quickSort(tableau, droite+1, fin);
    }
}

int util_strcmp(char* str1, char* str2) {
    if(strlen(str1) < strlen(str2)) {
        return -1;
    } else if(strlen(str1) > strlen(str2)) {
        return 1;
    } else {
        return strcmp(str1, str2);
    }
}
/**
 * Déplace le curseurdans le fichier au début du mot précédent ou suivant en fonction de pSens
 * @param pFichier Le fichier surlequelle s'apppliqeu le curseur. Celui-ci doit être ouvert en lecture
 * @param pSens le sens du déplacement MOT_PRECEDENT ou MOT_SUIVANT
 */
void util_deplacerCurseurDunMot(FILE* pFichier, const int pSens) {
    int deplacement = (pSens == MOT_PRECEDENT) ? -1 : 1;
        fseek(pFichier, deplacement, SEEK_CUR); 
    while( fgetc(pFichier) != '\r') {
        fseek(pFichier, deplacement-1, SEEK_CUR); 
    } 
    fseek(pFichier, 1, SEEK_CUR);

}

/**
 * Retourne vrai si la case pCase est présente dans le tableau
 * @param pTableau Le tableau sur lequele s'effectue le test
 * @param pTaille La taille du tableau
 * @param pCase La case à chercher
 * @return Vrai si la case existe dans le tableau.
 */
_Bool util_isInArray(const Case* pTableau, const int pTaille, const Case pCase) {
    _Bool continuer = true;
    for(int i = 0 ; (i < pTaille && continuer) ; ++i) {
        if((pTableau[i].i == pCase.i) && (pTableau[i].j == pCase.j)) {
            continuer = false;
        }
    }
    
    return !continuer;
}

/**
 * Convertis un nombre de secondes en minutes et secondes
 * @param pTimestamp Le nombre de secondes à converti
 * @param pMinutes Le nombre de minutes résultat
 * @param pSecondes Le nombre de secondes résultat
 */
void util_conversionTemps(const time_t pTimestamp, int* pMinutes, int* pSecondes) {
    *pMinutes = (pTimestamp / 60 % 60);
    *pSecondes  = pTimestamp % 60;
}
