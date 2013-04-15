/* 
 * File:   main.c
 * Author: aroquemaurel
 *
 * Created on 28 fÃ©vrier 2013, 19:00
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "dictionnaire.h"
#include "util.h"
#include "plateau.h"
#include "resolveur.h"

/*
 * 
*/
int main(void) {
    setlocale(LC_CTYPE, "");
    Dico test = dictionnaire_nouveau("Complet.txt");
    char choices[256];
    //printf("\n==%d", dictonnaire_chercherMot(test, "SLKDJFHLKSDFJH"));
    Plateau plateau = plateau_nouveau(8);
    plateau_remplirGrilleAleatoire(&plateau);
    //plateau_remplirGrillePredefinie(&plateau);
    plateau_afficher(plateau);
    resolveur(&plateau, choices, test);
    solution_afficher(plateau.solution);
    plateau_detruire(&plateau);


    return (EXIT_SUCCESS);
}

