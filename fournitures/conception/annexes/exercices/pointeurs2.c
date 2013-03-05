typedef int Zone;
typedef Zone *Ptr;

void miseAjour(Ptr p, Zone v) {
	*p = v;
}

int main(void) {
	Ptr p; // 1
	p = (Ptr) malloc(sizeof(Zone)); //2

	if(p != NULL)
		miseAjour(p, 10); // 3
}
