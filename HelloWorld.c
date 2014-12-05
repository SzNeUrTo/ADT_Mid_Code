#include <stdio.h>
void nut (int *a ,int *b)
{
	(*a)++;
	(*b)++;
}
int main(int argc, char *argv[])
{
	int a=2;
	int b=4;
	nut(&a,&b);	
	printf("%d %d %d\n", a, b, &2);
	return 0;
}
