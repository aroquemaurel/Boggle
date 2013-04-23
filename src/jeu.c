#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "util.h"
#include "resolveur.h"
#include "jeu.h"
#include "plateau.h"
#include "dictionnaire.h"
#include "interfaceTexte.h"

double jeu_tempsRestant(const Jeu pJeu) {
	return (-(time(NULL) - pJeu.timestampDepart) + 10);
}

bool jeu_compteurClaque(const Jeu pJeu) {
    return (jeu_tempsRestant(pJeu) <= 0);
}
Jeu jeu_initialiser(const char* pNomDico, const unsigned char pTaillePlateau) {
    Jeu nouveauJeu;
    nouveauJeu.plateau = plateau_nouveau(pTaillePlateau);
    nouveauJeu.dico = dictionnaire_nouveau(pNomDico);
    nouveauJeu.timestampDepart = time(NULL);
    nouveauJeu.solutionUtilisateur = solution_creer();
    return nouveauJeu;
}

void jeu_lancer(Jeu* pJeu) {
    char choices[256];
    
   // plateau_remplirGrilleAleatoire(&(pJeu->plateau));
     plateau_remplirGrillePredefinie(&(pJeu->plateau));
    resolveur(&(pJeu->plateau), choices, pJeu->dico);
    
    // départ compteur
}
_Bool jeu_proposerMot(Jeu* pJeu, const char* pMot) {
	char* mot = util_supprimerAccents(pMot);
	_Bool retour;
	util_uppercase(pMot);

	retour = solution_motEstPresent(pJeu->plateau.solution, pMot);
	if(retour) {
		solution_ajouterMot(&(pJeu->solutionUtilisateur), pMot);
	}
	free(mot);

	return (retour);
}

void jeu_stopper(Jeu pJeu) {
    plateau_detruire(&(pJeu.plateau));
    fclose(pJeu.dico.dico);
}

void jeu_lancerModeTexte(Jeu pJeu) {
    char proposition[32];
    jeu_lancer(&pJeu);
    interfaceTexte_afficherPlateau(pJeu.plateau);
	//
  solution_afficher(pJeu.plateau.solution);
  do {
        printf("encore %f secondes", (jeu_tempsRestant(pJeu)));
        scanf("%s", &proposition);
		printf("\n%s", jeu_proposerMot(&pJeu, proposition) ? "Good" : "Bad");
    }while((strcmp(proposition, "-1") != 0) && !jeu_compteurClaque(pJeu));
    solution_afficher(pJeu.solutionUtilisateur);
	jeu_stopper(pJeu);
  //  printf("\nProposer des mots : ");
//    solution_afficher(pJeu.plateau.solution);
}

