#include <stdio.h>
int fracN(int n) {
	if(n==0)
		return 1;
	return n * fracN(n-1);
}
int main(int argc, char *argv[])
{
	printf("%d\n", fracN(5));
	return 0;
}
