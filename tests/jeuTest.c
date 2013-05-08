/*
 * File:   jeuTest.c
 * Author: aroquemaurel
 *
 * Created on 7 mai 2013, 19:37:21
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "CUnit/Basic.h"
#include "jeu.h"
#include "interfaceTexte.h"

Jeu jeu;
/*
 * CUnit Test Suite
 */

int init_suite(void) {
    return 0;
}

int clean_suite(void) {
    return 0;
}

void testJeu_compteurClaque() {
    const Jeu pJeu;
    CU_ASSERT(!jeu_compteurClaque(pJeu));
}

void testJeu_nouveau() {
    Couple taille;
    taille.x = taille.y = 4;
    jeu = jeu_nouveau("Complet.txt", taille, 5);
    CU_ASSERT(jeu.dico.dico != NULL);
    CU_ASSERT(jeu.dico.marqueurs != NULL);
    CU_ASSERT(jeu.lgTimer == 5);
    CU_ASSERT(jeu.plateau.tailleGrille.x == 4 && jeu.plateau.tailleGrille.y == 4);
    CU_ASSERT(jeu.plateau.grille != NULL);
//    jeu_lancer(&jeu, true);
}

void testJeu_proposerMot() {
    Jeu* pJeu;
    CU_ASSERT(!jeu_proposerMot(pJeu, "321"));
    CU_ASSERT(!jeu_proposerMot(pJeu, " "));
    CU_ASSERT(!jeu_proposerMot(pJeu, "KLJDF"));
}



int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("jeuTest", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if (    (NULL == CU_add_test(pSuite, "testJeu_nouveau", testJeu_nouveau)) ||
            (NULL == CU_add_test(pSuite, "testJeu_compteurClaque", testJeu_compteurClaque)) ||
            (NULL == CU_add_test(pSuite, "testJeu_proposerMot", testJeu_proposerMot)) 
            ) {
        
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
