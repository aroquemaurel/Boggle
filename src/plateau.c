#include <stdio.h>
#include <stdlib.h>
#include "solution.h"
#include "plateau.h"
#include "util.h"

Plateau plateau_nouveau(const unsigned char pTailleGrille) {
    Plateau nouveauPlateau;
    nouveauPlateau.tailleGrille = pTailleGrille;
    
    nouveauPlateau.grille = malloc(sizeof(char*)*pTailleGrille);
    nouveauPlateau.grid = malloc(sizeof(char*)*pTailleGrille);
    nouveauPlateau.solution = solution_creer();
    for(int i=0; i < pTailleGrille ; ++i) {
        nouveauPlateau.grille[i] = malloc(sizeof(char)*pTailleGrille);
        nouveauPlateau.grid[i] = malloc(sizeof(char*)*pTailleGrille);
    }
    
    return nouveauPlateau;
}

Plateau plateau_detruire(Plateau* pPlateau) {
    for(int i=0; i < pPlateau->tailleGrille ; ++i) {
        free((pPlateau->grille[i]));
        free((pPlateau->grid[i]));
    }
    free(pPlateau->grille);
    free(pPlateau->grid);
    pPlateau->grille = NULL;
    pPlateau->grid = NULL;
    pPlateau->tailleGrille = 0;
    solution_detruire(&(pPlateau->solution));
}


void plateau_remplirGrilleAleatoire(Plateau* pPlateau) {
    for(int i=0 ; i < pPlateau->tailleGrille ; ++i) {
        for(int j=0 ; j < pPlateau->tailleGrille ; ++j) {
            pPlateau->grille[i][j] = plateau_choisirLettre();
            pPlateau->grid[i][j] = 0;
        }
    }
}

void plateau_remplirGrillePredefinie(Plateau* pPlateau) {
    char* grille = "EDRCANVCIRQAEBRU";
    int k;
    for(int i=0 ; i < pPlateau->tailleGrille ; ++i) {
        for(int j=0 ; j < pPlateau->tailleGrille ; ++j) {
            pPlateau->grille[j][i] = grille[k++];;
            pPlateau->grid[j][i] = 0;
        }
    }
    
// ** Solution de cette grille**
// DENIERA
// QUARRE ENRAIE DENIER CARRAI BRINDE BRANDE BERNAI
// VRAIE REINE RAINE NIERA NARRA ERINE DENIE DENIA DENAR DARNE DAINE CARRE CARRA BRAND BRAIE
// BRADE BERNE BERNA ARQUA ARBRE ANIER
// VRAI RIAD REIN RANI RAND RAIE RADE NIER INDE ERRA DENI DARI BRIN BRIE BRAN BRAI BINE BINA
// AIRE AINE ADNE
// VAU VAR RUA RIE RIA RAI RAD RAC NIE NIB NIA IRE IRA DAN CAR BRU BER ARE ANE AIR AIE

}


char plateau_choisirLettre(void) {
    char lettre;
    lettre = util_nbAleatoire('A', 'Z');
    if(rand() % 100 > plateau_probaLettre(lettre) *100) {
        return plateau_choisirLettre();
    }
    
    return lettre;
}
double plateau_probaLettre(const char pLettre) {
    double proba = 0.0;

    switch(pLettre) {
        case 'A':
            proba = 7.636;
            break;
        case 'B':
            proba = 0.901;
            break;
        case 'C': // c + ç
            proba = 3.260 + 0.085;
            break;
        case 'D':
            proba = 3.669;
            break;
        case 'E': // e + é + è + ê
            proba = 14.715 + 1.904 + 0.271 + 0.225;
            break;
        case 'F':
            proba = 1.066;
            break;
        case 'G':
            proba = 0.866;
            break;
        case 'H':
            proba = 0.737;
            break;
        case 'I': // i + î + ï
            proba = 7.529 + 0.045 + 0.006;
            break;
        case 'J':
            proba = 0.545;
            break;
        case 'K':
            proba = 0.049;
            break;
        case 'L':
            proba = 5.456;
            break;
        case 'M':
            proba = 2.968;
            break;
        case 'N':
            proba = 7.095;
            break;
        case 'O':
            proba = 5.378;
            break;
        case 'P':
            proba = 3.021;
            break;
        case 'Q':
            proba = 1.362;
            break;
        case 'R':
            proba = 06.553;
            break;
        case 'S':
            proba = 7.948;
            break;
        case 'T':
            proba = 7.244;
            break;
        case 'U': 
            proba = 6.311;
            break;
        case 'V':
            proba = 1.628;
            break;
        case 'W':
            proba = 0.114;
            break;
        case 'X':
            proba = 0.387;
            break;
        case 'Y':
            proba = 0.308;
            break;
        case 'Z':
            proba = 0.136;
            break;
        default:
            util_affichageDebug("dictionnaire_probaLettre", "La lettre n'existe pas");
    }
    return proba; 
}