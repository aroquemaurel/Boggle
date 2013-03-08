#include "plateau.h"

Plateau plateau_nouveau(const unsigned int pTailleGrille) {
    Plateau nouveauPlateau;
    nouveauPlateau.tailleGrille = pTailleGrille;
    
    // malloc
    plateau_remplirGrilleAleatoire(&nouveauPlateau);
    
    return nouveauPlateau;
}

void plateau_remplirGrilleAleatoire(Plateau* pPlateau) {
    
}
