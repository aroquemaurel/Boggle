#include <string.h>
#include <wchar.h>

#include "util.h"
void util_affichageDebug(const char* pNomFonction, const char* pChaine) {
    // TODO
}
void util_afficherTableAscii() {
    for (int i = 0 ; i < 256 ; ++i) {
        printf("%c : %d\n", i, i);
    }
}
char* util_supprimerAccents(char* pChaine) {
    char* retour = calloc(100, sizeof(char));
    wchar_t* buffer = calloc(100, sizeof(wchar_t));
    mbstowcs(buffer,pChaine,100);

    for(int i=0 ;  i < wcslen(buffer) ; ++i) {
        switch(buffer[i]) {
            case L'é':
            case L'è':
            case L'ê':
            case L'ë':              
                retour[i] = 'e';
                break;
            case L'ô':
            case L'ö':
                retour[i] = 'o';
                break;
            case L'à':
            case L'â':
                retour[i] = 'a';
                break;
            case L'ù':
                retour[i] = 'u';
                break;
            case L'î':
            case L'ï':
                retour[i] = 'i';
                break;
            default:
                retour[i] = pChaine[i];
        }
    }

    return retour;
}
