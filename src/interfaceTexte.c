#include <stdio.h>

#include "solution.h"
#include "jeu.h"
#include "plateau.h"
#include "interfaceTexte.h"

void interfaceTexte_afficherPlateau(const Plateau pPlateau) {
    for(int i=0 ; i < pPlateau.tailleGrille ; ++i) {
        for(int j=0 ; j < pPlateau.tailleGrille ; ++j) {
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

/**
 * Lance le jeu en mode texte
 * @param pJeu le jeu à lancer
 */
void jeu_lancerModeTexte(Jeu pJeu) {
    char proposition[32];
    jeu_lancer(&pJeu);
    interfaceTexte_afficherPlateau(pJeu.plateau);
	//
  interfaceTexte_afficherSolution(pJeu.plateau.solution);
  do {
        printf("encore %f secondes", (jeu_tempsRestant(pJeu)));
        scanf("%s", &proposition);
		printf("\n%s", jeu_proposerMot(&pJeu, proposition) ? " Mot Incorrect " : " Mot Correct ");
    }while((strcmp(proposition, "-1") != 0) && (!jeu_compteurClaque(pJeu)));
    interfaceTexte_afficherSolution(pJeu.solutionUtilisateur);
    interfaceTexte_afficherSolution(pJeu.plateau.solution);
    jeu_stopper(pJeu);
}
