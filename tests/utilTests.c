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

// TODO ddl .h,, mettre dans dossier
// Ajouter /usr/lib/libcunit.so makefile
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
    CU_ASSERT(strcmp(tableau[a], "chouette") == 0);
    CU_ASSERT(strcmp(tableau[b], "mahin") == 0);
}


void testUtil_quickSort() {
    char* tableau[8] = {"machin", "chouette", "truc", "chose", "bidul", "test", "hihi"};
    int debut = 1;
    int fin = 5;
    util_quickSort(tableau, debut, fin);
    CU_ASSERT(strcmp(tableau[0], "machin") == 0);
    CU_ASSERT(strcmp(tableau[1], "bidul") == 0);
    CU_ASSERT(strcmp(tableau[2], "chose") == 0);
    CU_ASSERT(strcmp(tableau[3], "chouette") == 0);
    CU_ASSERT(strcmp(tableau[4], "test") == 0);
    CU_ASSERT(strcmp(tableau[5], "truc") == 0);
    CU_ASSERT(strcmp(tableau[6], "hihi") == 0);
}
/*
void testUtil_substr() {
    const char* chaine;
    int debut;
    int fin;
    char* result;
    int result = util_substr(chaine, debut, fin, result);
    if (1 /*check result*) {
        CU_ASSERT(0);
    }
}
 */
void testUtil_supprimerAccents() {
    const char* pChaine = "testéééàààèèèÀÀÀÉÉÉ";
    char* result = util_supprimerAccents(pChaine);
    fprintf(stderr, "%s", result);
    CU_ASSERT (strcmp(result, "testeeeaaaeeeAAAEEE") == 0);
}

void util_afficherTableAscii();

void testUtil_afficherTableAscii() {
    util_afficherTableAscii();
    if (1 /*check result*/) {
        CU_ASSERT(0);
    }
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
    CU_ASSERT(strcmp(pChaine1, "HÉHÉHÉHÉECRITUREENCAPSLOCK") == 0);
    CU_ASSERT(strcmp(pChaine2, "ECRITURECAPSLOCKETPASCAPSLOCK") == 0);
    CU_ASSERT(strcmp(pChaine3, "ECRITURETOUTENLOWERCASE") == 0);
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
            (NULL == CU_add_test(pSuite, "testUtil_deplacerCurseurDunMot", testUtil_deplacerCurseurDunMot)) ||
            (NULL == CU_add_test(pSuite, "testUtil_echanger", testUtil_echanger)) ||
            (NULL == CU_add_test(pSuite, "testUtil_quickSort", testUtil_quickSort)) ||
//            (NULL == CU_add_test(pSuite, "testUtil_substr", testUtil_substr)) ||
            (NULL == CU_add_test(pSuite, "testUtil_supprimerAccents", testUtil_supprimerAccents)) ||
//            (NULL == CU_add_test(pSuite, "testUtil_afficherTableAscii", testUtil_afficherTableAscii)) ||
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
