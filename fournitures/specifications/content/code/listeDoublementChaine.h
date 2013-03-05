typedef struct LDCInterne* LDC;

LDC creer(void);
LDC ajouter(LDC, Elem);
void affichageCroisant(LDC);
void afficheDecroissant(LDC);
LDC supprimer(LDC, Elem);
LDC map((Element* fc)(Element), LDC liste);
