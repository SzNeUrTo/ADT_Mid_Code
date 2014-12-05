#include <stdio.h>
#define MAXSTACK 10
#define CHAR 1
#define INTEGER 2
#define DOUBLE 3

typedef struct { int ItemType; 
								 union { char cVal;
									 			 int iVal;
												 double dVal;
								 			 } ItemValue;
							 } TYPE_ITEM;
typedef struct { int Top;
								 TYPE_ITEM StackItem[MAXSTACK];
							 } TYPE_STACK;

void InitializeStack(TYPE_STACK *Stack) {
	int i;
	for (i = 0; i < MAXSTACK; ++i) {
		Stack -> StackItem[i].ItemValue.dVal = 0x00;
	}
	Stack -> Top = 0;
}

int isEmptyStack(TYPE_STACK *Stack) {
	return Stack -> Top == 0;
}

int isFullStack(TYPE_STACK Stack) {
	return Stack.Top ==  MAXSTACK;
}

int PushChar(TYPE_STACK *Stack, char Item) {
	if (Stack -> Top < MAXSTACK) {
		Stack -> StackItem[Stack -> Top].ItemType = CHAR;
		Stack -> StackItem[(Stack -> Top)++].ItemValue.cVal = Item;
		return 1;
	}
	else {
		printf("%s\n", "StackOverFlow");
		return 0;
	}

}

int PushInt(TYPE_STACK *Stack, int Item) {
	if (Stack -> Top < MAXSTACK) {
		Stack -> StackItem[Stack -> Top].ItemType = INTEGER;
		Stack -> StackItem[(Stack -> Top)++].ItemValue.iVal = Item;
		return 1;
	}
	else {
		printf("%s\n", "StackOverFlow");
		return 0;
	}
}

int PushDouble(TYPE_STACK *Stack, double Item) {
	if (Stack -> Top < MAXSTACK) {
		Stack -> StackItem[Stack -> Top].ItemType = DOUBLE;
		Stack -> StackItem[(Stack -> Top)++].ItemValue.dVal = Item;
		return 1;
	}
	else {
		printf("%s\n", "StackOverFlow");
		return 0;
	}
}

int Pop(TYPE_STACK *Stack, TYPE_ITEM *Item) {
	if (Stack -> Top > 0) {
		Item -> ItemType = Stack -> StackItem[--(Stack -> Top)].ItemType;
		Item -> ItemValue.dVal = Stack -> StackItem[Stack -> Top].ItemValue.dVal;
		return 1;
	}
	else {
		printf("%s\n", "StackUnderFlow");
		return 0;
	}
}



int main() {
	TYPE_STACK MyStack;
	char Data[] = "1234567890";
	int i;
	TYPE_ITEM Item;
	InitializeStack(&MyStack);
	for (i = 0; i < 10; i++) {
		PushChar(&MyStack, Data[i]);
	}
	//for (i = 0; i < 10; i++) {
	//	Pop(&MyStack, &Item);
	//	printf("%c\n", Item.ItemValue.cVal);
	//}
	if (isFullStack(MyStack)) {
		printf("%s\n", "Full");
	}
	return 0;
}
