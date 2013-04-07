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

/*
 * 
*/
int main(int argc, char** argv) {
    setlocale(LC_CTYPE, "");
    //Dico test = dictionnaire_nouveau("coucou");
    char* testChaine = "abcdefgééôèé";
    char* truc;
    Plateau plateau = plateau_nouveau(3);
    plateau_afficher(plateau);
    plateau_detruire(&plateau);
    /*wchar_t* x = calloc(100, sizeof(wchar_t));
    wchar_t* y = calloc(100, sizeof(char));

    fread(y, 1, 99, stdin);
    mbstowcs(x,y,100);*/
    /*if(x[0] = 'è') {
        printf("ooooh");
        
        free(x);
        free (y);
    }*/
    //printf("\n%c", testChaine);
    //printf(" %d ", (unsigned char) testChaine[4]);
    //printf("%d", dictonnaire_motEstPresent(test, "salut"));
    //util_afficherTableAscii();
    //truc = util_supprimerAccents(testChaine);
    //printf("%s", truc);
    return (EXIT_SUCCESS);
}

