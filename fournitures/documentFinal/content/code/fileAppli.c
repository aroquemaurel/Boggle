#include <stdio.h>
#include <stdlib.h>
#include "file.h"

int main(int argc, char** argv) {
	File deParis;
	File deGordeaux;
	File versToulouse;

	deParis = creer();
	// Saisie file
	deBordeaux = creer();
	// Saisie file

	// saisie de l'info manifestant

	if(manifestation) {
		versToulouse = concat(deParis, deBordeaux);
	} else {
		versToulouse = mixe(deParis, deBordeaux);
	}
	return 0;
}
