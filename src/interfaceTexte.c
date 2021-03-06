/** 
 * \file interfaceTexte.c
 * \brief Tous les affichages en mode texte seulement
 * Permet l'affichage du jeu en mode texte uniquement, les saisies se font au clavier.
 */

#include <stdio.h>
#include <string.h>

#include "solution.h"
#include "jeu.h"
#include "plateau.h"
#include "interfaceTexte.h"
#include "util.h"

void interfaceTexte_afficherPlateau(const Plateau pPlateau) {
    for(int i=0 ; i < pPlateau.tailleGrille.x ; ++i) {
        for(int j=0 ; j < pPlateau.tailleGrille.y ; ++j) {
            printf("%c ", pPlateau.grille[j][i]);
        }
        printf("\n");
    }
}

/**
 * Affiche la solution en mode texte
 * @param pSolution la solution à afficher
 */
void interfaceTexte_afficherSolution(const Solution pSolution) {
    printf("%d mots. nombre de points : %d\n", pSolution.nbMots, solution_nbPoints(pSolution));
    for(int i = 0 ; i < pSolution.nbMots ; ++i) {
        printf("%s\n", pSolution.mots[i]);
    }
    printf("%d mots. nombre de points : %d\n", pSolution.nbMots, solution_nbPoints(pSolution));    
}

void interfaceTexte_afficherPlateauEtSolution(const Plateau pPlateau, const Solution pSolution) {
    int i;
    printf("\n");
    for(i=0 ; i < pPlateau.tailleGrille.x ; ++i) {
        for(int j=0 ; j < pPlateau.tailleGrille.y ; ++j) {
            printf("%c ", pPlateau.grille[j][i]);
        }
        if(i < pSolution.nbMots) {
            printf("\t\t%s", pSolution.mots[i]);
        }
        printf("\n");
    }
    for(;i < pSolution.nbMots ; ++i) { 
        for(int j = 0 ; j < pPlateau.tailleGrille.x ; ++j) {
            printf("  ");
        }
        printf("\t\t%s", pSolution.mots[i]);
        printf("\n");
    }
    printf("\t\t%d mots. nombre de points : %d", pSolution.nbMots, solution_nbPoints(pSolution));
}
/**
 * Lance le jeu en mode texte
 * @param pJeu le jeu à lancer
 */
void jeu_lancerModeTexte(Jeu pJeu, _Bool pGrillePredefinie) {
    char proposition[32];
    int minutes, secondes;
    jeu_lancer(&pJeu, pGrillePredefinie);
    
    interfaceTexte_afficherPlateau(pJeu.plateau);
  do {
        util_conversionTemps(jeu_tempsRestant(pJeu), &minutes, &secondes);
        printf("\nencore %d min et %d secondes\n", minutes, secondes);
        
        util_lireChaine(proposition, 32);
        util_nettoyerConsole();
		printf("\n%s", jeu_proposerMot(&pJeu, proposition) ? " Mot Correct " : " Mot Inorrect ");
        interfaceTexte_afficherPlateauEtSolution(pJeu.plateau, pJeu.solutionUtilisateur);
    }while((strcmp(proposition, "-1") != 0) && (!jeu_compteurClaque(pJeu)));
    
    printf("\n\n=== Voici la solution complète: \n");
    interfaceTexte_afficherPlateauEtSolution(pJeu.plateau, pJeu.plateau.solution);
    printf("\n\n=== Vous avez trouvés les mots ci-dessous: ");
    interfaceTexte_afficherSolution(pJeu.solutionUtilisateur);
    jeu_stopper(pJeu);
}
