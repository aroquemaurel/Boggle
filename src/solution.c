#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "solution.h"

Solution solution_creer(void) {
    Solution nouvelleSolution;

    nouvelleSolution.nbMots = 0;
    nouvelleSolution.mots = malloc(sizeof(char*));

    return nouvelleSolution;
}
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

void solution_ajouterMot(Solution* pSolution, const char* mot) {
    int i;
    if(!solution_motEstPresent(*pSolution, mot)) {
        pSolution->mots = realloc(pSolution->mots, (pSolution->nbMots+1) * sizeof(char*));
        pSolution->mots[pSolution->nbMots] = malloc((strlen(mot)+1) * sizeof(char));
        strcpy(pSolution->mots[pSolution->nbMots], mot);
        ++(pSolution->nbMots);
    }
}
void solution_afficher(const Solution pSolution) {
    printf("%d mots. nombre de points : %d\n", pSolution.nbMots, solution_nbPoints(pSolution));
    for(int i = 0 ; i < pSolution.nbMots ; ++i) {
        printf("%s\n", pSolution.mots[i]);
    }
}

void solution_detruire(Solution* pSolution) {
    for(int i = 0 ; i < pSolution->nbMots ; ++i) {
        free(pSolution->mots[i]);
    }
    free(pSolution->mots);
}

int solution_nbPoints(Solution pSolution) {
    int retour = 0;
    int taille;
    for(int i = 0 ; i < pSolution.nbMots ; ++i) {
        taille = strlen(pSolution.mots[i]);
        if(taille == 3 || taille == 4) {
            retour += 1;
        } else if (taille == 5) {
            retour += 2;  
        } else if (taille == 6) {
            retour += 3;
        } else if (taille == 7) {
            retour += 5;   
        } else if (taille >= 8) {
            retour += 11;    
        }
    }
    
    return retour;
}