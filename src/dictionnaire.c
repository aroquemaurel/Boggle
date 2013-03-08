#include "dictionnaire.h"
#include "util.h"
#include <string.h>
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

double dictionnaire_probaLettre(const char pLettre) {
    double proba = 0.0;
    // TODO switch A=>Z
    switch(pLettre) {
        case 'A':
            proba = 0.0;
            break;
        case 'B':
            proba = 0.0;
            break;
        case 'C': // c + ç
            proba = 0.0;
            break;
        case 'D':
            proba = 0.0;
            break;
        case 'E': // e + é + è + ê + ë
            proba = 0.0;
            break;
        case 'F':
            proba = 0.0;
            break;
        case 'G':
            proba = 0.0;
            break;
        case 'H':
            proba = 0.0;
            break;
        case 'I': // i + î + ï
            proba = 0.0;
            break;
        case 'J':
            proba = 0.0;
            break;
        case 'K':
            proba = 0.0;
            break;
        case 'L':
            proba = 0.0;
            break;
        case 'M':
            proba = 0.0;
            break;
        case 'N':
            proba = 0.0;
            break;
        case 'O': // o + ô ö
            proba = 0.0;
            break;
        case 'P':
            proba = 0.0;
            break;
        case 'Q':
            proba = 0.0;
            break;
        case 'R':
            proba = 0.0;
            break;
        case 'S':
            proba = 0.0;
            break;
        case 'T':
            proba = 0.0;
            break;
        case 'U': 
            proba = 0.0;
            break;
        case 'V':
            proba = 0.0;
            break;
        case 'W':
            proba = 0.0;
            break;
        case 'X':
            proba = 0.0;
            break;
        case 'Y':
            proba = 0.0;
            break;
        case 'Z':
            proba = 0.0;
            break;
        default:
            util_affichageDebug("dictionnaire_probaLettre", "La lettre n'existe pas");
    }
    return proba; 
}