#include <stdio.h>
//#define true 1
//#define false 0
#define MAXSTACK 10
typedef struct {int Top; char StackItem[MAXSTACK];} TYPE_STACK;

void InitializeStack(TYPE_STACK *Stack) {
	int i;
	for (i = 0; i < MAXSTACK; i++) {
		Stack -> StackItem[i] = '\0';
	}
	Stack -> Top = 0;
}

int Pop(TYPE_STACK *Stack, char *Item) {
	if (Stack -> Top> 0) {
		*Item = Stack -> StackItem[--(Stack -> Top)];
		return true;
	}
	else {
		printf("%s\n", "StackUnderFlow");
		return false;
	}
}

int Push(TYPE_STACK *Stack, char Item) {
	if (Stack -> Top < MAXSTACK) {
		Stack -> StackItem[(Stack -> Top)++] = Item;
		return true;
	}
	else {
		printf("%s\n", "StackOverFlow");
		return false;
	}
}

int EmptyStack(TYPE_STACK *Stack) {
	return Stack -> Top == 0;
}

int FullStack(TYPE_STACK *Stack) {
	return Stack -> Top == MAXSTACK;
}

int main() {
	TYPE_STACK MyStack;
	InitializeStack(&MyStack);
	char MyItem;
	Pop(&MyStack, &MyItem);
	int i;
	for (i = 0; i < 11; ++i) {
		Push(&MyStack, 'A'+i);
	}
	for (i = 0; i < 11; ++i) {
		Pop(&MyStack, &MyItem);
		printf("%c\n", MyItem);
	}
	return 0;
}
