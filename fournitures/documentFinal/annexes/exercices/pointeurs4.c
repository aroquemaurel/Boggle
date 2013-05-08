typedef struct etCell {
	int val;
	struct etCell* suiv;
} Cel

typedef Cel* Ptr;

int main(void) {
	Cel c; //1
	c.val = 10; //2
	c.suiv = (Ptr) malloc(sizeof(Cel)); //3
	(*(c.suiv)).val = 11;
	(*(c.suiv)).suiv = (Ptr)malloc(sizeof(Cel));
	c.suiv->suiv->val = 12; // Ou (*((*(c.suiv)).suiv)).val = 12;
}
