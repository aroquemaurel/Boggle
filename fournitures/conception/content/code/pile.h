typedef struct etPile* Pile ;

Pile creer();
Pile empiler(Pile p, Element x);
int estVide(Pile p);
Pile depiler(Pile p);
Element sommet(Pile p);
int appartient(Pile p, Element x);
