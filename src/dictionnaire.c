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


/** 
 * @return -1 Mot absent. 0 Mot exact trouvé. ou un autre entier contenant le nombre de lettre manquante pour être dans le dico
 * */
int dictonnaire_chercherMot(Dico pDictionnaire, char* pMot) {
    char buff[256];
	char buff2[256];
	int retour;
    fgets(buff, 30, pDictionnaire);
     do {
        buff[strlen(buff)-2] = '\0'; // On enlève le \r et le \n (Merci windows...⁾
      //   printf("strcmp: %d(%s %s)\n", strcmp(buff, pMot),buff, pMot);
     } while (strcmp(buff, pMot) < 0 && fgets(buff, 30, pDictionnaire) != NULL);     
     rewind(pDictionnaire);
   //  printf("SORTIEBOUCLE\n", pMot, buff);
     
	 if(strcmp(buff, pMot) == 0) {
                retour = 1;
                printf("%s\n", pMot);
	 } else {
                if(strlen(pMot) <= strlen(buff2)) {                     
			util_substr(buff,0,strlen(pMot)-1,buff2);
                        //printf("%s %s", pMot, buff2);
			if(strcmp(pMot, buff2) == 0) {

                            //printf("%s\n", buff2);
                 //           printf("if2\n", pMot);
                                retour = 1;
			} else {
                   ///         printf("if3\n", pMot);
                                retour = 0;
			}
		 } else {
        //            printf("if4\n", pMot);
			 retour = 0;
		 }
	 }
     
    return (retour); 
}

