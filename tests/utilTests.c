/*
 * File:   utilTests.c
 * Author: aroquemaurel
 *
 * Created on 28 avr. 2013, 13:21:11
 */

#include <stdio.h>
#include <stdlib.h>
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "case.h"
#include "util.h"
#include <locale.h>

/*
/*
 * CUnit Test Suite
 */

int init_suite(void) {
    return 0;
}

int clean_suite(void) {
    return 0;
}

void testUtil_deplacerCurseurDunMot() {
    FILE* pFichier;
    const int pSens;
//    util_deplacerCurseurDunMot(pFichier, pSens);
    if (1 /*check result*/) {
        CU_ASSERT(0);
    }
}

void testUtil_echanger() {
    char* tableau[32] = {"test", "truc", "mahin", "chose", "chouette"};
    int a = 2;
    int b = 4;
    util_echanger(tableau, a, b);
    CU_ASSERT_STRING_EQUAL(tableau[a], "chouette");
    CU_ASSERT_STRING_EQUAL(tableau[b], "mahin");
}


void testUtil_quickSort() {
    char* tableau[8] = {"machin", "chouette", "truc", "chose", "bidul", "test", "hihi"};
    int debut = 1;
    int fin = 5;
    util_quickSort(tableau, debut, fin);
    CU_ASSERT_STRING_EQUAL(tableau[0], "machin");
    CU_ASSERT_STRING_EQUAL(tableau[1], "bidul");
    CU_ASSERT_STRING_EQUAL(tableau[2], "chose");
    CU_ASSERT_STRING_EQUAL(tableau[3], "chouette");
    CU_ASSERT_STRING_EQUAL(tableau[4], "test");
    CU_ASSERT_STRING_EQUAL(tableau[5], "truc");
    CU_ASSERT_STRING_EQUAL(tableau[6], "hihi");
}

void testUtil_substr() {
    const char chaine[64] = "coucou je suis une chaine";
    char resultat[32];
    int result = util_substr(chaine, 5, 15, resultat);
    CU_ASSERT_STRING_EQUAL(resultat, "u je suis u");
    CU_ASSERT_DOUBLE_EQUAL(result, 11, 1);
    
    CU_ASSERT_STRING_EQUAL(chaine, "coucou je suis une chaine");
}
 
void testUtil_supprimerAccents() {
    const char* pChaine = "testéééàààèèèÀÀÀÉÉÉ";
    char* result = util_supprimerAccents(pChaine);
    fprintf(stderr, "%s", result);
    CU_ASSERT (strcmp(result, "testeeeaaaeeeAAAEEE") == 0);
}

_Bool util_isInArray(const Case* pTableau, const int pTaille, const Case pCase);

void testUtil_isInArray() {
    Case a, b, c, d, e, f;
    a.i = 1; a.j = 2; b.i = 3; b.j = 4; c.i=5; c.j=6; d.i=7; 
    d.j=8; e.i=9; e.j=10; f.i=11; f.j=12;
    
    Case tableau[8] = {a,b,c,d};
    CU_ASSERT(util_isInArray(tableau, 4, a));
    CU_ASSERT(util_isInArray(tableau, 4, b));
   CU_ASSERT(util_isInArray(tableau, 4, c)); 
   CU_ASSERT(util_isInArray(tableau, 4, d));
   CU_ASSERT(!util_isInArray(tableau, 4, e));
   CU_ASSERT(!util_isInArray(tableau, 4, f));

}

void util_uppercase(char* pChaine);

void testUtil_uppercase() {
    char pChaine1[32] = "HÉHÉHÉHÉECRITUREENCAPSLOCK";
    char pChaine2[32] = "EcritureCapsLockEtPasCapsLock";
    char pChaine3[32] = "ecrituretoutenlowercase";
    util_uppercase(pChaine1);
    util_uppercase(pChaine2);
    util_uppercase(pChaine3);
    CU_ASSERT_STRING_EQUAL(pChaine1, "HÉHÉHÉHÉECRITUREENCAPSLOCK");
    CU_ASSERT_STRING_EQUAL(pChaine2, "ECRITURECAPSLOCKETPASCAPSLOCK");
    CU_ASSERT_STRING_EQUAL(pChaine3, "ECRITURETOUTENLOWERCASE");
}

int main() {
    setlocale(LC_CTYPE, "");
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("utilTests", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if (
//    TODO        (NULL == CU_add_test(pSuite, "testUtil_deplacerCurseurDunMot", testUtil_deplacerCurseurDunMot)) ||
            (NULL == CU_add_test(pSuite, "testUtil_echanger", testUtil_echanger)) ||
            (NULL == CU_add_test(pSuite, "testUtil_quickSort", testUtil_quickSort)) ||
            (NULL == CU_add_test(pSuite, "testUtil_substr", testUtil_substr)) ||
            (NULL == CU_add_test(pSuite, "testUtil_supprimerAccents", testUtil_supprimerAccents)) ||
            (NULL == CU_add_test(pSuite, "testUtil_isInArray", testUtil_isInArray)) ||
            (NULL == CU_add_test(pSuite, "testUtil_uppercase", testUtil_uppercase))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
