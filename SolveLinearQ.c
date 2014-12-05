#include <stdio.h>

#define MAXSIZE 10
typedef struct { int Front;
								 int Rear;
								 char QueueItem[MAXSIZE];
							 } TYPE_QUEUE;

void InitializeQueue(TYPE_QUEUE *QUEUE) {
	int i;
	for (i = 0; i < MAXSIZE; ++i) {
		QUEUE -> QueueItem[i] = 0x00;
	}
	QUEUE -> Front = 0;
	QUEUE -> Rear = 0;
}

int isEmptyQueue(TYPE_QUEUE *Queue) {
	return Queue -> Rear == 0;
}

int isFullQueue(TYPE_QUEUE *Queue) {
	return Queue -> Front == MAXSIZE;
}

int Insert(TYPE_QUEUE *Queue, char Item) {
	if (Queue -> Rear < MAXSIZE) {
		Queue -> QueueItem[(Queue -> Rear)++] = Item;
		return 1;
	}
	else {
		printf("%s\n", "QueueOverFlow");
		return 0;
	}
}

int Delete(TYPE_QUEUE *Queue, char *Item) {
	if (Queue -> Front != Queue -> Rear) {
		*Item = Queue -> QueueItem[(Queue -> Front)];
		(Queue -> Rear)--;
		int i;
		for (i = 0; i < Queue -> Rear; ++i) {
			Queue -> QueueItem[i] = Queue -> QueueItem[i+1];
		}
		return 1;
	}
	else {
		printf("%s\n", "QueueUnderFlow");
		*Item = 0;
		return 0;
	}
}

int Front(TYPE_QUEUE *Queue) {
	return Queue -> Front;
}

int Rear(TYPE_QUEUE *Queue) {
	return Queue -> Rear;
}

int main(int argc, char *argv[]) {
	TYPE_QUEUE MyQueue;
	InitializeQueue(&MyQueue);
	char MyItem;
	Delete(&MyQueue, &MyItem);
	printf("%c\n", MyItem);
	Insert(&MyQueue, 'A');
	Delete(&MyQueue, &MyItem);
	printf("%c\n", MyItem);
	Insert(&MyQueue, 'A');
	printf("%c\n", MyItem);
	Insert(&MyQueue, 'B');
	Delete(&MyQueue, &MyItem);
	printf("%c\n", MyItem);
	Delete(&MyQueue, &MyItem);
	printf("%c\n", MyItem);
	return 0;
}
