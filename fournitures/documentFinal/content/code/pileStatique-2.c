Pile remplacer(Pile pPile, Element pX, Element pY) {
	int i;
	for(i=0 ; i < p.nb ; ++i) {
		if(p.tab[i] == x) {
			p.tab[i] = y;
		}
	}

	return p;
}

void afficherPile(Pile pPile) {
	int i;
	for(i=0 ; i < p.nb; ++i) {
		afficheElement(p.tab[i]);
	}
}
