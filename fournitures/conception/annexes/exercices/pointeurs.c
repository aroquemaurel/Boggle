int *p, *q; // 1
p = NULL; // 2
q = p; //3
p = (int*)(malloc(sizeof(int))); // 4
q = p; // 5
q = (int*)malloc(sizeof(int)) // 6
free(p);
*q = 10;
	
