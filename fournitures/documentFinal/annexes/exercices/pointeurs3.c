typedef struct etCell {
	int val;
	int* suiv;
} Cel

typedef Cel* Ptr;

int main(void) {
	Cel c; //1
	c.val = 10; //2
	c.suiv = (int*) malloc(sizeof(int)); //3
	*(c.suiv) = 11; //4
}
