typedef struct etCell {
	struct etCell* prec;
	struct etCell* suiv;
	Elem val;
} Cell;

typedef struct LDCInterne {
	Cell* premier;
	Cell* dernier;
} LDCInterne;

/*
 * Fonction interne
 */
void trouverPlace(LDC l, Element e, Cell** prec, Cell** suiv) {
	Cell* courant = l->premier;
	courant = l->premier;
	*prec = NULL;
	*suiv = courant;

	while(courant != NULL) {
		if(compare(e, courant->val) == 1) {
			*prec = courant;
			*suiv = courant->suiv;
			courant = courant->suiv;
		} else {
			courant = NULL;
		}
	}
}

LDC creer(void) {
	LDC newLdc;
	newLdc = (LDC) malloc(sizeof(LDCInterne));
	newLdc->premier = NULL;
	newLdc->dernier = NULL;

	return newLdc;
}

LDC ajouter(LDC liste, Elem element) {
	Cel* current;
	Cel* avant;
	Cel* apres;
	courant = (Cell*) malloc(sizeof(Cell));
	assert(courant != NULL);
	courat-val = e;
	trouverPlace(liste, element, &avant, &apres);
	courant->prec = avant;
	courant->suiv = apres;

	if(avant == NULL) { //début de liste
		liste->premier = courant;
	} else {
		liste->premier->suiv = courant;
	}

	if(apres == NULL) { //fin de liste
		liste->dernier = courant;
	} else {
		liste->dernier->prec = courant;
	}

	return liste;
}


void affichageCroisant(LDC liste) {
	Cell* courant = liste->premier;
	while(courant != NULL) {
		afficherElement(courant->val);	
		courant = courant->suiv;
	}
}

void afficheDecroissant(LDC liste) {
	Cell* courant = liste->dernier;
	while(courant != NULL) {
		afficherElement(courant->val);	
		courant = courant->prec;
	}
}

LDC supprimer(LDC liste, Elem element) {
	Cell* courant;
	Cell* ajeter;

	courant = liste->premier;
	while(courant != NULL) {
		if(compare(e, courant->val) == 0) {
			// On a trouvé
			if(courant->prec != NULL) {
				courant->prec->suiv = courant->suiv;
			} else {
				l->premier = courat->suiv;
			}

			if(courant->suiv != NULL) {
				courant->suiv->prec = courant->prec;
			} else {
				liste->dernier = courant->prec;
			}

			ajeter = courant;
			courant = courant->suiv;
			free(ajeter);
		} else {
			courant = courant->suiv;
		}
	}
	return liste;
}

LDC map((Element* fc)(Element), LDC liste) {
	Cell* courant;
	courant = liste->premier;
	LDC listeRes = creer();

	while(courant != NULL) {
		listeRes = ajouter(listeResultat, fc(courant->al));
		courant = courant->suiv;
	}

	return liste;
}
