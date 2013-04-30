#ifndef JEU_H
#define	JEU_H
#include <time.h>
#include "plateau.h"
#include "dictionnaire.h"

/**
 * \struct Jeu
 * \brief Structure permettant de jouer au Boggle
 * Structure contenant toutes les informations nécessaire au bon déroulement du jeu
 * @see Dico, Plateau, Solution
 */
typedef struct {
    Plateau plateau; /*!< Le plateau de Jeu */
    Dico dico; /*!< Le dictionnaire */
    time_t timestampDepart; /*!< Le timestamp auquel on a commencé à jouer */
    Solution solutionUtilisateur; /*!< La solution que propose l'utilisateur, celle-ci peut ne pas être complète, mais tous les mots présents dans cette solution sont présent dans la grille */
    unsigned int lgTimer; /*< Longueur du timer en secondes */
} Jeu;

Jeu jeu_nouveau(const char* pNomDico, const unsigned char pTaillePlateau, const unsigned int pLgTimer);
void jeu_lancer(Jeu* pJeu);
_Bool jeu_proposerMot(Jeu* pJeu, const char* pMot);
bool jeu_compteurClaque(const Jeu pJeu);
time_t jeu_tempsRestant(const Jeu pJeu);
void jeu_stopper(Jeu pJeu);
#endif	/* JEU_H */
