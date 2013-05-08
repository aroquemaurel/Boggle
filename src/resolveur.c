/**
 * \file resolveur.c
 * \brief Gestion du résolveur
 * Permet de résoudre une grille de Boggle, une fois résolue, la solution se trouve dans
 * le module Solution
 */

#include <string.h>

#include "util.h"
#include "dictionnaire.h"
#include "resolveur.h"
#include "solution.h"
#include "interfaceTexte.h"
#include "jeu.h"

/**
 * Fonction privée récursive permettant de résoudre une grille de Boggle
 * @param pPlateau Le lateau à résoudre
 * @param x L'abscisse de la lettre pour laquelle on part
 * @param y L'ordonné de la lettre pour laquelle on part
 * @param depth La profondeur à laquelle on se trouve
 * @param choices Le mot formé actuellement
 * @param pDico Le dictionnaire dans laquel chercher les mots
 */
void recurse(Plateau* pPlateau, Solution* pSolution, int x, int y, int depth, char* choices, Dico pDico) {
    int res;
    if((x < 0) || (y < 0) || (x >= pPlateau->tailleGrille.x) || (y >= pPlateau->tailleGrille.y)) {
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
            solution_ajouterMot(pSolution, choices);
        }
    } else {
        res = 1;
    }
    
    if((res) && (depth < TAILLE_MOT_MAX)) {        
        recurse(pPlateau, pSolution, x-1, y-1, depth, choices, pDico);
        recurse(pPlateau, pSolution, x, y-1, depth, choices, pDico);
        recurse(pPlateau, pSolution, x+1, y-1, depth, choices, pDico);
        
        recurse(pPlateau, pSolution, x-1, y, depth, choices, pDico);
        recurse(pPlateau, pSolution, x+1, y, depth, choices, pDico);
        
        recurse(pPlateau, pSolution, x-1, y+1, depth, choices, pDico);
        recurse(pPlateau, pSolution, x, y+1, depth, choices, pDico);
        recurse(pPlateau, pSolution, x+1, y+1, depth, choices, pDico);
    }
    pPlateau->grid[x][y] = 0;
}
Solution resolveur_resolveUneCase(Plateau pPlateau, Dico pDico, const Couple pCase) {
    char buff[32];
    Solution retour = solution_creer();
    recurse(&pPlateau, &retour, pCase.y, pCase.x, 0, buff, pDico);
    util_quickSort((void**)retour.mots, 0, retour.nbMots-1, util_strcmp);
    return retour;
}
/**
 * Résoud une grille de boggle
 * @param pPlateau Le plateau à résoudre
 * @param choices 
 * @param pDico le dictionnaire
 */
void resolveTouteLaGrille(Plateau* pPlateau, Dico pDico) {
    char choices[256];
    for(int j = 0 ; j < pPlateau->tailleGrille.y; ++j) {
        for(int i = 0 ; i < pPlateau->tailleGrille.x; ++i) {
            recurse(pPlateau, &(pPlateau->solution), i, j, 0, choices, pDico);
        }
    }
    util_quickSort((void**)pPlateau->solution.mots, 0, pPlateau->solution.nbMots-1, util_strcmp);
}

/**
 * Lance le jeu en mode solveur
 * @param pJeu le jeu à lancer
 */
void jeu_lancerModeSolveur(Jeu pJeu) {
    char buff[4];
    Couple caseAResolver;
    Solution solution;
    
    caseAResolver.x = 1;
    caseAResolver.y = 1;
    util_nettoyerConsole();
    jeu_lancer(&pJeu, false);
    interfaceTexte_afficherPlateau(pJeu.plateau);
    printf("Entrer les coordonnées de la case à partir de laquelle one commence la résolution\n");
    printf("i: ");
    util_lireChaine(buff, 4);
    caseAResolver.x = atoi(buff);
    printf("j: ");
    util_lireChaine(buff, 4);
    caseAResolver.y = atoi(buff);
    solution = resolveur_resolveUneCase(pJeu.plateau, pJeu.dico, caseAResolver);
    interfaceTexte_afficherPlateauEtSolution(pJeu.plateau, solution);
    printf("\n");
}