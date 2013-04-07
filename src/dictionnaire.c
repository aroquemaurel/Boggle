#include <string.h>

#include "dictionnaire.h"
#include "util.h"

Dico dictionnaire_nouveau(const char* pNomFichier) {
    Dico nouveauDico = fopen(pNomFichier, "r+");
    if(nouveauDico == NULL) {
        perror("Le nom de fichier du dictionnaire n'existe pas");
    }
    
    return nouveauDico;
}

bool dictonnaire_motEstPresent(Dico pDictionnaire, const char* pMot) {
    char buff[256];
    fgets(buff, 30, pDictionnaire);
     do {
        buff[strlen(buff)-1] = '\0'; // On enlève le \n de fin de ligne
     } while (strcmp(buff, pMot) != 0 && fgets(buff, 30, pDictionnaire) != NULL);
     
    return (strcmp(buff, pMot) == 0); 
}

