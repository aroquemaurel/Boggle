File concat(File f1, File f2) {
	File retour = creer();
	Cell* courant = f1->premier;
	int i;
	for(i=0 ; i < 2 ; ++i) {
		while(courant != NULL) {
			enfiler(retour, courant->elem);
			courant = courant->suivant;
		}
		courant = f2->premier;
	}

	return retour;
}

File mixe(File f1, File f2) {
	File fileRetour = creer();
	Cell* courant1 = f1->premier;
	Cell* courant2 = f2->premier;
	
	while(courant1 != NULL || courant2 != NULL) {
		if(courant1 != NULL) {
			enfiler(fileRetour, courant1);			
			courant1 = courant1->suivant;
		}
		if(courant2 != NULL) {
			enfiler(fileRetour, courant2);			
			courant2 = courant2->suivant;
		}
	}

	return retour;
}
