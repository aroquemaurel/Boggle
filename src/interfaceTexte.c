#include "interfaceTexte.h"

void interfaceTexte_afficherPlateau(const Plateau pPlateau) {
    for(int i=0 ; i < pPlateau.tailleGrille ; ++i) {
        for(int j=0 ; j < pPlateau.tailleGrille ; ++j) {
            printf("%c ", pPlateau.grille[j][i]);
        }
        printf("\n");
    }
}

void interfaceTexte_proposerMOt() {
    
}