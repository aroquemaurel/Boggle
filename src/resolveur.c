#include <stdbool.h>

#include <string.h>
#include "util.h"
#include "dictionnaire.h"

#include "resolveur.h"
#include "solution.h"
void recurse(Plateau* pPlateau, int x, int y, int depth, char* choices, Dico pDico) {
    int res;
    
    if((x < 0) || (y < 0) || (x >= pPlateau->tailleGrille) || (y >= pPlateau->tailleGrille)) {
        return ;
    }
    
    if(pPlateau->grid[x][y] == 1) {
        return ;
    }
    
    pPlateau->grid[x][y] = 1;
    choices[depth] = pPlateau->grille[x][y];
    ++depth;
    choices[depth] = '\0';
    
    if(depth >= TAILLE_MOT_MIN) {
        res = dictonnaire_motDansDico(pDico, choices);
        if(res == 10) { // ajouter mot dans solution
            solution_ajouterMot(&(pPlateau->solution), choices);
        }
    } else {
        res = 1;
    }
    
    if((res) && (depth < TAILLE_MOT_MAX)) {        
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
    util_quickSort(pPlateau->solution.mots, 0, pPlateau->solution.nbMots-1);
}
