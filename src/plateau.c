#include "plateau.h"

Plateau plateau_nouveau(const unsigned int pTailleGrille) {
    Plateau nouveauPlateau;
    nouveauPlateau.tailleGrille = pTailleGrille;
    
    // malloc
    plateau_remplirGrilleAleatoirement(&nouveauPlateau);
    
    return nouveauPlateau;
}

void plateau_remplirGrilleAleatoirement(Plateau* pPlateau) {
    
}