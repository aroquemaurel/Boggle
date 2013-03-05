typedef struct etCell* Arbre;

Arbre creerGrd(void);
Arbre ajout(const Arbre arbre, int e);
void afficher(const Arbre arbre);
int estVide(const Arbre arbre);
int appartient(const Arbre arbre, int racine);
