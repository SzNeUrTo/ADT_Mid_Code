#include <stdio.h>

//void GG(const char *c) {
void GG(char *c) {
	//c[1] = '6';
	printf("%s\n", "GG");
}

int main(int argc, char *argv[])
{
	char Arr[] = "123456";
	GG(Arr);
	printf("%s\n", Arr);
	return 0;
}
