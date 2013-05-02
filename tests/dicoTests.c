/*
 * File:   newcunittest.c
 * Author: aroquemaurel
 *
 * Created on 1 mai 2013, 11:31:27
 */

#include <stdio.h>
#include <stdlib.h>
#include "CUnit/Basic.h"
#include "dictionnaire.h"
Dico gdico;
/*
 * CUnit Test Suite
 */

int init_suite(void) {
    return 0;
}

int clean_suite(void) {
    return 0;
}

void testDictionnaire_nouveau() {
    const char* pNomFichier = "Complet.txt";
    gdico = dictionnaire_nouveau(pNomFichier);
    CU_ASSERT_PTR_NOT_NULL(gdico.dico);
}

void testDictonnaire_motDansDico() {
    char pMot[32] = "TEST";
    CU_ASSERT_DOUBLE_EQUAL(dictonnaire_motDansDico(gdico, pMot), 10, 0);
    strcpy(pMot, "TEA");
    CU_ASSERT_DOUBLE_EQUAL(dictonnaire_motDansDico(gdico, pMot), 1, 0);
    strcpy(pMot, "KAMOULOX");
    CU_ASSERT_DOUBLE_EQUAL(dictonnaire_motDansDico(gdico, pMot), 0, 0);
}

int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("dicoTests", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "testDictionnaire_nouveau", testDictionnaire_nouveau)) ||
            (NULL == CU_add_test(pSuite, "testDictonnaire_motDansDico", testDictonnaire_motDansDico))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
