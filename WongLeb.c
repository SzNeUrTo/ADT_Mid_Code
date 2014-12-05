#include <stdio.h>
#define TRUE 1
#define FALSE 0
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
		return TRUE;
	}
	else {
		printf("%s\n", "StackUnderFlow");
		return FALSE;
	}
}

int Push(TYPE_STACK *Stack, char Item) {
	if (Stack -> Top < MAXSTACK) {
		Stack -> StackItem[(Stack -> Top)++] = Item;
		return TRUE;
	}
	else {
		printf("%s\n", "StackOverFlow");
		return FALSE;
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
	//char data[] = "1+2*3*(2+3+(2+1))";
	char data[] = ")";
	printf("%s\n", data);
	int i;
	for (i = 0; i < sizeof(data)/sizeof(char); ++i) {
		if (data[i]=='(') {
			Push(&MyStack, data[i]);
		}
		else if (data[i]==')') {
			Pop(&MyStack, &MyItem);
			//printf("%c\n", MyItem);
		}
		printf("%d", MyStack.Top);
	}
	return 0;
}
