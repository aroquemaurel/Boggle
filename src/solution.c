/**
 * \file solution.c
 * \brief Gère la solution d'une grille de boggle
 * Toutes les fonctions se rapportant à la solution d'une grille
 * \see plateau
 */

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "solution.h"

/**
 * Créer la structure de données la solution
 * @return La nouvelle solution
 */
Solution solution_creer(void) {
    Solution nouvelleSolution;

    nouvelleSolution.nbMots = 0;
    nouvelleSolution.mots = malloc(sizeof(char*));

    return nouvelleSolution;
}

/**
 * Retourne vrai si le mot pMot est présent dans la solution
 * @param pSolution La solution dans laquelle chercher
 * @param pMot Le mot à chercher
 * @return Vrai si pMot est présent dans pSolution
 */
_Bool solution_motEstPresent(const Solution pSolution, const char* pMot) {
    _Bool retour = false;            

    for(int i = 0 ; (i < pSolution.nbMots) ; ++i) {
        if(strcmp(pSolution.mots[i], pMot) == 0) {
            retour = true;
            break;
        }
    }
    
    return retour;
}

/**
 * Retourne le nombre de mots présents dans la solution commençant pas la chaine de caractère pDebut
 * @param pSolution La solution
 * @param pDebut Le début de la chaine
 * @return Le nombre de mots commençant par pDebut
 */
int solution_getNbMotsDebut(Solution pSolution, char* pDebut) {
    char buff[32];
    int retour = 0;
    for(int i=0 ; i < pSolution.nbMots ; ++i) {
        util_substr(pSolution.mots[i],0,strlen(pDebut)-1,buff);
        if(strcmp(buff, pDebut) == 0) {
            ++retour;
        }
    }
    
    return retour;
}
/**
 * Ajoute un mot dans la solution pSolution
 * @param pSolution La solution dans laquelle ajouter le mot
 * @param mot Le mot à ajouter
 */
void solution_ajouterMot(Solution* pSolution, const char* mot) {
    if(!solution_motEstPresent(*pSolution, mot)) {
        pSolution->mots = realloc(pSolution->mots, (pSolution->nbMots+1) * sizeof(char*));
        pSolution->mots[pSolution->nbMots] = malloc((strlen(mot)+1) * sizeof(char));
        strncpy(pSolution->mots[pSolution->nbMots], mot, strlen(mot)+1);
        ++(pSolution->nbMots);
    }
}

/**
 * Détruit la solution
 * @param pSolution La solution à détruire
 */
void solution_detruire(Solution* pSolution) {
    for(int i = 0 ; i < pSolution->nbMots ; ++i) {
        free(pSolution->mots[i]);
    }
    free(pSolution->mots);
    pSolution->mots = NULL;
    pSolution->nbMots = 0;
}

/**
 * Retourn le nombre de points pouvant être obtenus avec la solution pSolution
 * @param pSolution la solutino pour laquelle compter le nombre de points
 * @return Le nombres de points à compter
 */
int solution_nbPoints(Solution pSolution) {
    int retour = 0;
    int taille;
    for(int i = 0 ; i < pSolution.nbMots ; ++i) {
        taille = strlen(pSolution.mots[i]);
        if((taille == 3) || (taille == 4)) {
            retour += 1;
        } else if (taille == 5) {
            retour += 2;  
        } else if (taille == 6) {
            retour += 3;
        } else if (taille == 7) {
            retour += 5;   
        } else if (taille >= 8) {
            retour += 11;    
        } else {
            retour += 0;
        }
    }
    
    return retour;
}
