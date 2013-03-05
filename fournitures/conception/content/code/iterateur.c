#include "iterateur.h"

typedef struct etIte {
	LDC l;
	Cell* cour;
} etIterateur;


Iterateur creerIterateur(LDC liste) {
	Iterateur ite;
	ite = (Iterateur) malloc(sizeof(etIterateur));
	assert(ite != NULL); 
	ite->l = liste;
	ite->cour = liste->debut;

	return ite;
}

Element next(Iterateur iterateur) {
	Element ret = iterateur->cour->val;
	assert(hasNext);
	iterateur = iterateur->cour->suivant;

	return ret;
}

Element previous(Iterateur iterateur) {
	Element ret;
	assert(hasPrevious);
	if(iterateur->cour != NULL) 
		iterateur->cour = iterateur->cour->precedent;
	else
		iterateur->cour = iterateur->l->fin;

	ret = iterateur->cour->val;

	return ret;
}
void begin(Iterateur iterateur) {
	iterateur->cour = iterateur->l->debut;
}
void end(Iterateur iterateur) {
	iterateur->cour = NULL; 
}
int hasNext(Iterateur iterateur) {
	return (iterateur->cour != NULL);
}
int hasPrevious(Iterateur iterateur) {
	return (iterateur->cour != iterateur->l->debut);
}
