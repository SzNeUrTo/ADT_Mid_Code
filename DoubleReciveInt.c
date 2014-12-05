#include <stdio.h>
void nut(double *a, double *b)
{
	(*a)++;
	(*b)++;
}
int main(int argc, char *argv[])
{
	int a=12,b=125;
	nut(&a, &b);
	printf("%d %d\n", a,b);
	return 0;
}
