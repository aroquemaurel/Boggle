#ifndef JEU_H
#define	JEU_H
#include <time.h>
#include "plateau.h"
#include "dictionnaire.h"
typedef struct {
    Plateau plateau;
    Dico dico;
    time_t timestampDepart;
    Solution solutionUtilisateur;
} Jeu;

Jeu jeu_nouveau(const char* pNomDico, const unsigned char pTaillePlateau);
void jeu_lancer(Jeu* pJeu);
_Bool jeu_proposerMot(Jeu* pJeu, const char* pMot);
bool jeu_compteurClaque(const Jeu pJeu);
time_t jeu_tempsRestant(const Jeu pJeu);
#endif	/* JEU_H */
