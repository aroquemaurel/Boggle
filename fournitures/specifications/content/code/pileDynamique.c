typedef struct etCel {
	Element val;
	struct etCel* suiv;
} Cel;

typedef cel* Pile;

Pile creer() {
	return NULL;
}

Pile empiler(Pile p, Element x) {
	Pile pAux;
	pAux = (pile)malloc(sizeof(Cel));
	assert(pAux != NULL);
	pAux->val = x;
	pAux->suiv = p;

	return (pAux);
}

int estVide(Pile p) {
	return (p == NULL);
}

Pile depiler(Pile p) {
	Pile pAux = NULL;
	if(p != NULL) {
		pAux = p->suivant;	
		free(p);
	}

	return pAux;
}

Element sommet(Pile p) {
	return (p->val);
}

int appartient(Pile p, Element x) {
	if(estVide(p))
		return 0;

	while(!estVide(p)) {
		if(p->suiv == x)
			return 1;

		p = p->suiv;
	}

	return 0;
}
