/* 
 * File:   main.c
 * Author: aroquemaurel
 *
 * Created on 28 février 2013, 19:00
 */

#include <stdio.h>
#include <stdlib.h>

#include "dictionnaire.h"
/*
 * 
*/
int main(int argc, char** argv) {
Dico test = dictionnaire_nouveau("coucou");
    printf("%d", dictonnaire_motEstPresent(test, "salut"));
    return (EXIT_SUCCESS);
}

