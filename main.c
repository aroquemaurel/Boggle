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

/*
 * 
*/
int main(void) {
    setlocale(LC_CTYPE, "");
    char choices[256];
    Jeu jeu = jeu_initialiser("Complet.txt", 4);
   jeu_lancerModeTexte(jeu);
    return (EXIT_SUCCESS);
}

