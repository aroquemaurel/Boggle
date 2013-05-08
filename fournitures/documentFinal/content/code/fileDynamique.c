typedef struct etCell {
	struct etCell* suivant;
	Element elem;
} Cell;

typedef struct etFile {
	Cell* premier;
	Cell* dernier;
} FileInterne;


File creer() {
	File f;
	f = (File) malloc(sizeof(FileInterne));
	assert(f != NULL);
	f->premier = NULL;
	f->dernier = NULL;

	return f;
}

File enfile(File pFile, Element pElement) {
	Cell* c;
	c = (Cell*) malloc(sizeof(Cell));
	assert(c != NULL);
	c->elem = pElement;
	c->suivant = NULL;
	if(!estVide(pFile)) {
		pFile->dernier->suivant = c;
	} else {
		pFile->premier = c;
	}
	pFile->dernier = c;

	return pFile;
}

int estPleine(File pFile) {
	return (false);
}

int estVide(File pFile) {
	return (pFile->premier == NULL);
}

File defiler(File pFile) {
	if(!estVide(pFile)) {
		File buff = pFile;
		pFile->premier = pFile->suivant;
		if(pFile->suivant == NULL) {
			pFile->dernier = NULL
		} 

		free(buff);
	}

	return pFile;
}

int appartient(File pFile, Elment pElement) {
	Cell* courant;
	courant = pFile->premier;
	while(courant != NULL) {
		if(pFile->premier->element == pElement) {
			return 1;
		}
		courant = courant->suivant;
	}

	return 0;
}

Element premier(File pFile) {
	return (pFile->premier->elem);
}

Element dernier(File pFile) {
	return (pFile->dernier->elem);

}
