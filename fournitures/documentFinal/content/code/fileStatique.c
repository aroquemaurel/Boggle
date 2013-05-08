#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "file.h"

#define N 1000 

struct eltFile {
	Element Tab[N];
	int nb;
	int tete; // Buffer en rond
} FileInterne;

File creer() {
	File f;
	f = (File) malloc(sizeof(FileInterne));
	assert(f != NULL);
	f->nb = 0;
	f->tete = 0;

	return f;
}

File enfile(File pFile, Element pElement) {
	assert(!estPleine(pFile));
	pFile->tab[(f->n+f->tete)%N] = pElement;
	++f->nb;
	return pFile;
}

int estPleine(File pFile) {
	return (pFile->nb == N);
}

int estVide(File pFile) {
	return (pFile->nb == 0);
}

File defiler(File pFile) {
	if(!estVide(f)) {
		pFile->nb--;
		f->tete = (f->tete+1)%N;
	}

	return pFile;
}

int appartient(File pFile, Elment pElement) {
	int i;
	for( i=0 ; i < f->nb ; ++i ) {
		if(x == f->tab[(i+f->tete)%N])
			return 1;
	}

	return 0;
	
}

Element premier(File pFile) {
	return (pFile->tab[pFile->tete]);
}

Element dernier(File pFile) {
	return (pFile->tab[(f->tete+f->nb-1)%N]);

}
