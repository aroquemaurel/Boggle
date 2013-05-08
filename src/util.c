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
#include <locale.h>

#include "util.h"
#include "jeu.h"
#include "couple.h"

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
    static _Bool premierAppel = true;
    char* retour = malloc(100*sizeof(char));
    wchar_t* buffer = malloc(100*sizeof(wchar_t));
    mbstowcs(buffer,pChaine,100);

    if(premierAppel) {
        setlocale(LC_CTYPE, "");
        premierAppel = false;
    }
    
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
void util_uppercase(char* pChaine) { 
	for(int i = 0 ; i  < strlen(pChaine) ; ++i) {
            if((pChaine[i] >= 'a') && (pChaine[i] <= 'z')) {
		pChaine[i] -= 32;
            }
	}
    printf("%s", pChaine);
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
 * Effectue un tri sur une portion d'un tableau de chaine de caractère s.
 * Ce tri s'effectue en fonction du critère de la fonction de comparaison fctCmp
 * Ce tri utilise l'algorithme du tri rapide.
 * @param tableau Le tableau à trier. Les éléments sont de n'importes quels type.
 * @param debut Le début du tableau à trier
 * @param fin La fin du tableau à trier
 * @param fctCmp Pointeurs de fonction pour la comparaison de deux éléments du tableau.
 * retourne un nombre inférieur à 0 si param 1 doit être avant 2, supérieur à 0 si après 
 * ou égal à 0 si les deux paramètre sont égaux dans le classement
 */
void util_quickSort(void** tableau, int debut, int fin, int (*fctCmp)(void*,void*)) { // TODO ajouter foncteur de comparaison
    int gauche = debut-1;
    int droite = fin+1;
    const void* pivot = tableau[debut];
 
    if(debut < fin)  {
        do { 
            do {
                droite--; 
            } while(((*fctCmp)(tableau[droite], pivot)) > 0);
            do {
                gauche++; 
            } while(((*fctCmp)(tableau[gauche], pivot)) < 0);

            if(gauche < droite) {
                util_echanger(tableau, gauche, droite);
            } 
        } while(gauche < droite);

        util_quickSort(tableau, debut, droite, util_strcmp);
        util_quickSort(tableau, droite+1, fin, util_strcmp);
    }
}

int util_strcmp(void* str1, void* str2) {
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
_Bool util_isInArray(const Couple* pTableau, const int pTaille, const Couple pCase) {
    _Bool continuer = true;
    for(int i = 0 ; ((i < pTaille) && (continuer)) ; ++i) {
        if((pTableau[i].x == pCase.x) && (pTableau[i].y == pCase.y)) {
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

int util_cherchePremiereOccurenceDansTableau(char** pTableau, const int pTaille, char* pRecherche) {
    int position = 0;

    while ((position < pTaille - 1) && (strcmp( pTableau[position], pRecherche) != 0)) {
        ++position;
    }

    return ((position == pTaille - 1) && (strcmp( pTableau[position], pRecherche) != 0)) ? -1 : position;
}

/**
 * Nettoie toute la console
 */
void util_nettoyerConsole(void) {
    printf("%c[2J", 0x1B); 
}


void util_viderBuffer(void) {
    int c = 0;
    while ((c != '\n') && (c != EOF)) {
        c = getchar();
    }
}
  
int util_lireChaine(char *chaine, int longueur) {
    char *positionEntree = NULL;
    if (fgets(chaine, longueur, stdin) != NULL) {
        positionEntree = strchr(chaine, '\n');
        if (positionEntree != NULL) {
            *positionEntree = '\0';
        } else {
            util_viderBuffer();
        }
        return 1;
    } else {        
        util_viderBuffer();
        return 0;
    }
}