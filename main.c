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

/*
 * 
*/
int main(void) {
    setlocale(LC_CTYPE, "");
    Jeu jeu = jeu_nouveau("Complet.txt", 8, 180);
//   jeu_lancerModeTexte(jeu);
   jeu_lancerModeNcurses(jeu);
    return (EXIT_SUCCESS);
}

