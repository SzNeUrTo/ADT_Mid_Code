#include <stdio.h>
int *iPtr;

void getnum() {
	int num;
	scanf("%d",&num);
	iPtr = &num;
}
void confuse() {
	int x = 5;
}
void confuse2() {
	int y = 10;
}
int main(int argc, char *argv[]) {
	
	getnum();
	printf("%d\n", *iPtr);
	confuse();
	printf("%d\n", *iPtr);
	confuse2();
	printf("%d\n", *iPtr);
	return 0;
}
