#include <stdbool.h>
#include "plateau.h"
#include "util.h"
#include "resolveur.h"
#include "dictionnaire.h"

_Bool resolveur_deplacementPossible(const Deplacement pDeplacement, const Plateau pPlateau, const int i, const int j) {
    _Bool retour = true;
    
    if(pDeplacement == HAUT || pDeplacement == DIAGO_HAUT_DROITE || pDeplacement == DIAGO_HAUT_GAUCHE) {
        retour = (i > 0);
    }

    if(pDeplacement == BAS || pDeplacement == DIAGO_BAS_DROITE || pDeplacement == DIAGO_BAS_GAUCHE) {
        retour = (i < pPlateau.tailleGrille);
    }
    
    if(pDeplacement == GAUCHE || pDeplacement == DIAGO_BAS_GAUCHE || pDeplacement == DIAGO_HAUT_GAUCHE) {
        retour = (j > 0);
    }
    
    if(pDeplacement == DROITE || pDeplacement == DIAGO_BAS_DROITE || pDeplacement == DIAGO_HAUT_DROITE) {
        retour = (j < pPlateau.tailleGrille);
    }
    
    return retour;
}
void recurse(Plateau* pPlateau, int x, int y, int depth, char* choices, Dico pDico) {
    int res;
    
    if(x < 0 || y < 0 || x >= pPlateau->tailleGrille || y >= pPlateau->tailleGrille) {
        return ;
    }
    
    if(pPlateau->grid[x][y] == 1) {
        return ;
    }
    
    pPlateau->grid[x][y] = 1;
    choices[depth++] = pPlateau->grille[x][y];
    choices[depth] = '\0';
    
    if(depth >= TAILLE_MOT_MIN) {
        res = dictonnaire_chercherMot(pDico, choices);
        //printf("%d %s\n", res, choices);
    } else {
        res = 1;
    }
    
    if(res && depth < TAILLE_MOT_MAX) {        
        recurse(pPlateau, x-1, y-1, depth, choices, pDico);
        recurse(pPlateau, x, y-1, depth, choices, pDico);
        recurse(pPlateau, x+1, y-1, depth, choices, pDico);
        
        recurse(pPlateau, x-1, y, depth, choices, pDico);
        recurse(pPlateau, x+1, y, depth, choices, pDico);
        
        recurse(pPlateau, x-1, y+1, depth, choices, pDico);
        recurse(pPlateau, x, y+1, depth, choices, pDico);
        recurse(pPlateau, x+1, y+1, depth, choices, pDico);
    }
    pPlateau->grid[x][y] = 0;
}

void resolveur(Plateau* pPlateau, char* choices, Dico pDico) {
    for(int j = 0 ; j < pPlateau->tailleGrille ; ++j) {
        for(int i = 0 ; i < pPlateau->tailleGrille ; ++i) {
            recurse(pPlateau, i, j, 0, choices, pDico);
        }
    }
}
