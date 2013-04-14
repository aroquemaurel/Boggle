#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "solution.h"

Solution solution_creer(void) {
    Solution nouvelleSolution;

    nouvelleSolution.nbMots = 0;
    nouvelleSolution.mots = malloc(sizeof(char*));

    return nouvelleSolution;
}

void solution_ajouterMot(Solution* pSolution, const char* mot) {
    pSolution->mots = realloc(pSolution->mots, (pSolution->nbMots+1) * sizeof(char*));
    pSolution->mots[pSolution->nbMots] = malloc((strlen(mot)+1) * sizeof(char));
    strcpy(pSolution->mots[pSolution->nbMots], mot);
    ++(pSolution->nbMots);
}
void solution_afficher(const Solution pSolution) {
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
