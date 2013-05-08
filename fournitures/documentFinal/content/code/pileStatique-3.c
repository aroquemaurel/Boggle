#define N 1000 

struct etPile {
	Element Tab[N];
	int nb;
} PileInterne;

Pile creer() {
	Pile p ;
	p = (Pile) malloc(sizeof(PileInterne));
	p->nb = 0;

	return p ;
}

Pile empiler(Pile p, Element x) {
	assert(p->nb < N); // Si la condition est false alors arrête programme
	p->tab[p->nb] = x;
	p->nb++;

	return (p);
}

int estVide(Pile p) {
	return (p->nb == 0);
}

Pile depiler(Pile p) {
	if(!estVide(p)) {
		p->nb--;
	}

	return p;
}

Element sommet(Pile p) {
	asset(!estVide(p)); // Pas indispensable masi plus robuste
	return (p->tab[p->nb-1]);
}

int appartient(Pile p, Element x) {
	if(estVide(p))
		return 0;

	if(x == sommet(p)) {
		return 1;
	}

	return (appartient(depiler(p), x));
}
