#include <stdio.h>
int fractotial(int n) {
	if (n == 0) {
		return 1;
	}
	return n * fractotial(n-1);
}
int main(int argc, char *argv[])
{
	printf("%d\n", fractotial(5));	
	return 0;
}
