typedef struct etIte* Iterateur;

Iterateur creerIterateur(LDC);
Element next(Iterateur iterateur);
Element previous(Iterateur iterateur);
void begin(Iterateur iterateur);
void end(Iterateur iterateur);
int hasNext(Iterateur iterateur);
int hasPrevious(Iterateur iterateur);

