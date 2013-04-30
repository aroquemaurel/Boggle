#include <stdlib.h>
#include <stdio.h>
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
 * Ajoute un mot dans la solution pSolution
 * @param pSolution La solution dans laquelle ajouter le mot
 * @param mot Le mot à ajouter
 */
void solution_ajouterMot(Solution* pSolution, const char* mot) {
    int i;
    if(!solution_motEstPresent(*pSolution, mot)) {
        pSolution->mots = realloc(pSolution->mots, (pSolution->nbMots+1) * sizeof(char*));
        pSolution->mots[pSolution->nbMots] = malloc((strlen(mot)+1) * sizeof(char));
        strncpy(pSolution->mots[pSolution->nbMots], mot, sizeof(mot));
        ++(pSolution->nbMots);
    }
}

// TODO déplacer mode text
/**
 * Affiche la solution en mode texte
 * @param pSolution la solution à afficher
 */
void solution_afficher(const Solution pSolution) {
    printf("%d mots. nombre de points : %d\n", pSolution.nbMots, solution_nbPoints(pSolution));
    for(int i = 0 ; i < pSolution.nbMots ; ++i) {
        printf("%s\n", pSolution.mots[i]);
    }
    printf("%d mots. nombre de points : %d\n", pSolution.nbMots, solution_nbPoints(pSolution));    
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
