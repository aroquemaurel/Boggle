#include <string.h>

#include "dictionnaire.h"
#include "util.h"

Dico dictionnaire_nouveau(const char* pNomFichier) {
    Dico nouveauDico;
    long int test;
    int i = 0;
    char buff[32];
    char caractereCourant = '\0';
    nouveauDico.dico = fopen(pNomFichier, "r+");
    if(nouveauDico.dico == NULL) {
        perror("Le nom de fichier du dictionnaire n'existe pas");
    }
    rewind(nouveauDico.dico);
    while (fgets(buff, 30, nouveauDico.dico) != NULL) {
        if(caractereCourant != buff[0]) {
            caractereCourant = buff[0];
            nouveauDico.marqueurs[i] = ftell(nouveauDico.dico);
            ++i;
        }
     }      

    return nouveauDico;
}


/** 
 * @return -1 Mot absent. 0 Mot exact trouvé. ou un autre entier contenant le nombre de lettre manquante pour être dans le dico
 * */
int dictonnaire_chercherMot(Dico pDictionnaire, char* pMot) {
    char buff[256];
    char buff2[256];
    int retour;

    fseek(pDictionnaire.dico, pDictionnaire.marqueurs[pMot[0]-65], SEEK_SET);    
    fgets(buff, 30, pDictionnaire.dico);
    do {
        buff[strlen(buff)-2] = '\0'; // On enlève le \r et le \n (Merci windows...⁾
     } while (strcmp(buff, pMot) < 0 && fgets(buff, 30, pDictionnaire.dico) != NULL);     

    if(strcmp(buff, pMot) == 0) {
        retour = 10;
    } else {
            util_substr(buff,0,strlen(pMot)-1,buff2);

        if(strlen(pMot) <= strlen(buff2)) {            
            if(strcmp(pMot, buff2) == 0) {
                retour = 1;
            } else {
                retour = 0;
            }
        } else {

            retour = 0;
        }
    }

    return (retour); 
}

