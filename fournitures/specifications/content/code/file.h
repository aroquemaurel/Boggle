#include "element.h"

typedef struct etFile* File ;
File creer();
File enfile(File pFile, Element pElement);
File defiler(File pFile);
int appartient(File pFile, Elment pElement);
Element premier(File pFile);
Element dernier(File pFile);
int estPleine(File pFile);
