/*
 * File:   solutionTests.c
 * Author: aroquemaurel
 *
 * Created on 1 mai 2013, 12:13:50
 */

#include <stdio.h>
#include <stdlib.h>
#include "CUnit/Headers/Basic.h"
#include "solution.h"

Solution gSolution;
/*
 * CUnit Test Suite
 */

int init_suite(void) {
    return 0;
}

int clean_suite(void) {
    return 0;
}

void testSolution_ajouterMot() {
    char mot[32] = "TEST";
    solution_ajouterMot(&gSolution, mot);
    CU_ASSERT(gSolution.nbMots == 1);
    CU_ASSERT_STRING_EQUAL(gSolution.mots[0], mot);
    strcpy(mot, "TESTOSTERONE");
    solution_ajouterMot(&gSolution, mot);
    strcpy(mot, "MACHIN");
    solution_ajouterMot(&gSolution, mot);
    strcpy(mot, "TRUC");
    solution_ajouterMot(&gSolution, mot);
    CU_ASSERT_DOUBLE_EQUAL(gSolution.nbMots, 4,0);
    CU_ASSERT_STRING_EQUAL(gSolution.mots[3], mot);
    strcpy(mot, "TESTONS");
    solution_ajouterMot(&gSolution, mot);
    strcpy(mot, "CHOSE");
    solution_ajouterMot(&gSolution, mot);
    strcpy(mot, "CHOUETTE");
    solution_ajouterMot(&gSolution, mot);
    CU_ASSERT_DOUBLE_EQUAL(gSolution.nbMots, 7,0);
    CU_ASSERT_STRING_EQUAL(gSolution.mots[6], mot);
    strcpy(mot, "TESTOUILLE");
    solution_ajouterMot(&gSolution, mot);
    strcpy(mot, "BIDULE");
    solution_ajouterMot(&gSolution, mot);
    CU_ASSERT_DOUBLE_EQUAL(gSolution.nbMots, 9,0);
    CU_ASSERT_STRING_EQUAL(gSolution.mots[8], mot);
    
}

void testSolution_creer() {
    gSolution = solution_creer();

    CU_ASSERT(gSolution.nbMots == 0);
}

void testSolution_detruire() {
    solution_detruire(&gSolution);
    CU_ASSERT(gSolution.nbMots == 0);
    CU_ASSERT_PTR_NULL(gSolution.mots);
}

void testSolution_motEstPresent() {
    CU_ASSERT(solution_motEstPresent(gSolution, "CHOUETTE"));
    CU_ASSERT(solution_motEstPresent(gSolution, "BIDULE"));
    CU_ASSERT(solution_motEstPresent(gSolution, "CHOSE"));
    CU_ASSERT(!solution_motEstPresent(gSolution, "mlkjsdfmlkdf"));
    CU_ASSERT(!solution_motEstPresent(gSolution, "MLKQFMLKDF"));
    CU_ASSERT(!solution_motEstPresent(gSolution, "LEJF"));
}

void testSolution_nbPoints() {
    Solution pSolution;
    int result = solution_nbPoints(pSolution);
    if (1 /*check result*/) {
        CU_ASSERT(0);
    }
}

int solution_getNbMotsDebut(Solution pSolution, char* pDebut);

void testSolution_getNbMotsDebut() {
    char* pDebut = "TEST";
//    CU_ASSERT_DOUBLE_EQUAL(gSolution.nbMots, 9,0);
    CU_ASSERT_EQUAL(solution_getNbMotsDebut(gSolution, pDebut), 4);
}

int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("solutionTests", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "testSolution_creer", testSolution_creer)) ||
            (NULL == CU_add_test(pSuite, "testSolution_ajouterMot", testSolution_ajouterMot)) ||
            (NULL == CU_add_test(pSuite, "testSolution_motEstPresent", testSolution_motEstPresent)) ||
//            (NULL == CU_add_test(pSuite, "testSolution_nbPoints", testSolution_nbPoints)) ||
            (NULL == CU_add_test(pSuite, "testSolution_getNbMotsDebut", testSolution_getNbMotsDebut)) ||
            (NULL == CU_add_test(pSuite, "testSolution_detruire", testSolution_detruire))
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
