/**
 * \file jeu.c
 * \brief Gestion du jeu de Boggle
 *  Les fonctions permettant de gérer le Jeu de Boggle.
 * \see Plateau, Resolveur, Dico, Solution
 */

#include <stdlib.h>
#include <string.h>

#include "util.h"
#include "resolveur.h"
#include "jeu.h"
#include "plateau.h"
#include "dictionnaire.h"
#include "interfaceTexte.h"

/**
 * Retourne le nombre de secondes restantes avant la fin du jeu
 * @param pJeu Le jeu pour lequel on veut savoir le temps restant
 * @return Le nombre de secondes restantes
 */
time_t jeu_tempsRestant(const Jeu pJeu) {
	return (-(time(NULL) - pJeu.timestampDepart) + pJeu.lgTimer); // TODO paramètre
}

/**
 * Retourne vrai si le temps est écoulé faux sinon
 * @param pJeu Le jeu pourlequel on veut saoir si le temps est écoulé
 * @return Vrai si le temps est écoulé faux sinon
 */
bool jeu_compteurClaque(const Jeu pJeu) {
    return (jeu_tempsRestant(pJeu) <= 0);
}

/**
 * Créer un nouveau jeu
 * @param pNomDico Le dictionnaire utilisé dans le Jeu
 * @param pTaillePlateau La taille du plateau à créer
 * @param pLgTimer La longeur du timer en secondes
 * @return Le nouveau Jeu
 */
Jeu jeu_nouveau(const char* pNomDico, const Couple pTaillePlateau, const unsigned int pLgTimer) {
    Jeu nouveauJeu;
    nouveauJeu.plateau = plateau_nouveau(pTaillePlateau);
    nouveauJeu.dico = dictionnaire_nouveau(pNomDico);
    nouveauJeu.timestampDepart = time(NULL);
    nouveauJeu.solutionUtilisateur = solution_creer();
    nouveauJeu.lgTimer = pLgTimer;
    return nouveauJeu;
}

/**
 * Lance le jeu
 * @param pJeu Le jeu à lancer
 */
void jeu_lancer(Jeu* pJeu) {  
    plateau_remplirGrilleAleatoire(&(pJeu->plateau));
    interfaceTexte_afficherPlateau(pJeu->plateau);
//    plateau_remplirGrillePredefinie(&(pJeu->plateau));
    resolveTouteLaGrille(&(pJeu->plateau), pJeu->dico);
}

/**
 * Proposer un mot
 * @param pJeu Le jeu pour lequel on veut proposer un mot
 * @param pMot Le mot proposé
 * @return Vrai si le mot est validé
 */
_Bool jeu_proposerMot(Jeu* pJeu, const char* pMot) {
	char* mot = util_supprimerAccents(pMot);
	_Bool retour;
	util_uppercase(mot);

	retour = solution_motEstPresent(pJeu->plateau.solution, mot);
	if(retour) { 
        solution_ajouterMot(&(pJeu->solutionUtilisateur), mot);
	}
	free(mot);
        

	return (retour);
}

/**
 * Fin du jeu
 * @param pJeu Le jeu à terminer
 */
void jeu_stopper(Jeu pJeu) {
    plateau_detruire(&(pJeu.plateau));
    fclose(pJeu.dico.dico);
}

