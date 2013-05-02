/*
 * File:   plateauTests.c
 * Author: aroquemaurel
 *
 * Created on 1 mai 2013, 11:32:52
 */

#include <stdio.h>
#include <stdlib.h>
#include "CUnit/Basic.h"
#include "plateau.h"
#include "dictionnaire.h"

/*
 * CUnit Test Suite
 */

int init_suite(void) {
    return 0;
}

int clean_suite(void) {
    return 0;
}

void testPlateau_choisirLettre() {
    char result = plateau_choisirLettre();
    if (1 /*check result*/) {
        CU_ASSERT(0);
    }
}

void testPlateau_detruire() {
    Plateau* pPlateau;
    plateau_detruire(pPlateau);
    if (1 /*check result*/) {
        CU_ASSERT(0);
    }
}

void testPlateau_nouveau() {
    const unsigned char pTailleGrille;
    Plateau result = plateau_nouveau(pTailleGrille);
    if (1 /*check result*/) {
        CU_ASSERT(0);
    }
}

void testPlateau_probaLettre() {
    const char pLettre;
    double result = plateau_probaLettre(pLettre);
    if (1 /*check result*/) {
        CU_ASSERT(0);
    }
}

void testPlateau_remplirGrilleAleatoire() {
    Plateau* pPlateau;
    plateau_remplirGrilleAleatoire(pPlateau);
    if (1 /*check result*/) {
        CU_ASSERT(0);
    }
}

void testPlateau_remplirGrillePredefinie() {
    Plateau* pPlateau;
    plateau_remplirGrillePredefinie(pPlateau);
    if (1 /*check result*/) {
        CU_ASSERT(0);
    }
}

int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("plateauTests", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "testPlateau_choisirLettre", testPlateau_choisirLettre)) ||
            (NULL == CU_add_test(pSuite, "testPlateau_detruire", testPlateau_detruire)) ||
            (NULL == CU_add_test(pSuite, "testPlateau_nouveau", testPlateau_nouveau)) ||
            (NULL == CU_add_test(pSuite, "testPlateau_probaLettre", testPlateau_probaLettre)) ||
            (NULL == CU_add_test(pSuite, "testPlateau_remplirGrilleAleatoire", testPlateau_remplirGrilleAleatoire)) ||
            (NULL == CU_add_test(pSuite, "testPlateau_remplirGrillePredefinie", testPlateau_remplirGrillePredefinie))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
