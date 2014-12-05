#include <stdio.h>
#define MAXSTACK 10
#define TRUE 1
#define FALSE 0

int StackItem[MAXSTACK];
int TOP;
void InitializeStack() {
	for (int i = 0; i < MAXSTACK; i++) {
		StackItem[i] = 0;
	}
	TOP = 0;
}

int Push(int Item) {
	if (TOP < MAXSTACK) {
		StackItem[TOP++] = Item;
		return TRUE;
	}
	else {
		printf("%s\n", "OverFlow");
		return FALSE;
	}
}

int Pop(int *Item) {
	if (TOP > 0) {
		*Item = StackItem[--TOP];
		return TRUE;
	}
	else {
		printf("%s\n", "UnderFlow");
		*Item = 0;
		return FALSE;
	}
}

int EmptyStack() {
	return TOP == 0;
}

int FullStack() {
	return TOP == MAXSTACK;
}

int Top() {
	return TOP;
}

int main() {
	InitializeStack();
	printf("%d\n",EmptyStack());
	int Item = 0;
	Pop(&Item);
	return 0;
}
