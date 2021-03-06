/*
 * File:   plateauTests.c
 * Author: aroquemaurel
 *
 * Created on 1 mai 2013, 11:32:52
 */

#include <stdio.h>
#include <stdlib.h>
#include "CUnit/Headers/Basic.h"
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

void testPlateau_nouveau() {
    Couple pTailleGrille;
    pTailleGrille.x = 5;
    pTailleGrille.y = 5;
    Plateau result = plateau_nouveau(pTailleGrille);
    CU_ASSERT_PTR_NOT_NULL(result.grille);
    CU_ASSERT_PTR_NOT_NULL(result.grid);
    CU_ASSERT_EQUAL(result.tailleGrille.x, 5);
    CU_ASSERT_EQUAL(result.tailleGrille.y, 5);
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
    if ((NULL == CU_add_test(pSuite, "testPlateau_nouveau", testPlateau_nouveau))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
