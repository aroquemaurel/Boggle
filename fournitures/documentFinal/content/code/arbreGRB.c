typedef struct etCell {
	struct etCell* gauche;
	struct etCell* droite;
	int racine;
} Cell;

Arbre creerGrd(void) {
	return (NULL);
}
Arbre ajout(const Arbre arbre, int e) {
	Cell* newCell;
	newCell = (Cell*)malloc(sizeof(Cell));
	newCell->racine = e;
	newCell->gauche = NULL;
	newCell->gauche = NULL;
	if(estVide(arbre)) {
		arbre = newCell;	
	} else {
		if(e <= arbre->racine) {
			arbre->gauche = ajout(arbre->gauche, e);
		} else {
			arbre->droite = ajout(arbre->droite, e);
		}
	}

	return arbre;
}
void afficher(const Arbre arbre) {
	Cell* cous = a;
	if(!estVide(a)) {
		affiche(a->gauche);
		printf("%d", a->racine);
		afficher(a->droite);
	} 
}
int estVide(const Arbre arbre) {
	return (arbre != NULL);
}
int appartient(const Arbre arbre, int val) {
	if(estVide(arbre))
		return 0;
	if(val <= arbre->racine)
		return appartient(arbre->gauche, val);
	if(val > arbre->racine)
		return appartient(arbre->droite, val);

	return 1;
}

