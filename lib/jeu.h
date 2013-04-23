#ifndef JEU_H
#define	JEU_H
#include <time.h>
#include "plateau.h"
#include "dictionnaire.h"
typedef struct {
    Plateau plateau;
    Dico dico;
    time_t timestampDepart;
} Jeu;

Jeu jeu_initialiser(const char* pNomDico, const unsigned char pTaillePlateau);
void jeu_lancer(Jeu* pJeu);
bool jeu_compteurClaque(const Jeu pJeu);
#endif	/* JEU_H */
