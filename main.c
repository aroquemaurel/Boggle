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
#include "jeu.h"
#include "interfaceNcurses.h"
#include "interfaceTexte.h"

/*
 * 
*/
int main(int argc, char** argv) {
    Couple taille;
    char buff1[256];
    char buff2[256];
    setlocale(LC_CTYPE, "");
    taille.x = taille.y = 0;
    do {
        printf("Veuillez entre la taille de la grille de boggle. "
                "Les valeurs doivent être comprise entre 3 et 15");
        printf("\nTaille de la grille: ");
        util_lireChaine(buff1, 3);

        taille.x =  taille.y = atoi( buff1);
    } while(taille.x < 3 || taille.x > 15 || taille.y < 3 || taille.y > 15);
    
    Jeu jeu = jeu_nouveau("Complet.txt", taille, 50);
    
    if(util_cherchePremiereOccurenceDansTableau(argv, argc, "--text") != -1) {
        jeu_lancerModeTexte(jeu);
    } else if(util_cherchePremiereOccurenceDansTableau(argv, argc, "--solveur") != -1) {
        jeu_lancerModeSolveur(jeu);
    } else {
        jeu_lancerModeNcurses(jeu);
    }
    
    return (EXIT_SUCCESS);
}

