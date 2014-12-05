#include <stdio.h>

#define MAXQUEUE 10
typedef struct { int Front;
								 int Rear;
								 char QueueItem[MAXQUEUE];
							 } TYPE_QUEUE;

void InitilizeQueue(TYPE_QUEUE *Queue) {
	int i;
	for (i = 0; i < MAXQUEUE; i++) {
		Queue -> QueueItem[i] = 0;
	}
	Queue -> Front = 0;
	Queue -> Rear = 0;
}

int Insert(TYPE_QUEUE *Queue, char Item) {
	if ((Queue -> Rear+1) % MAXQUEUE != Queue -> Front) {
		Queue -> Rear = (Queue -> Rear + 1) % MAXQUEUE;
		Queue -> QueueItem[Queue -> Rear] = Item;
		return 1;
	}
	else {
		printf("%s\n", "QueueOverFlow");
		return 0;
	}
}

int Delete(TYPE_QUEUE *Queue, char *Item) {
	if (Queue -> Rear != Queue -> Front) {
		*Item = Queue -> QueueItem[Queue -> Front];
		Queue -> Front = (Queue -> Front + 1) % MAXQUEUE;
		return 1;
	}
	else {
		printf("%s\n", "QueueUnderFlow");
		*Item = 0;
		return 0;
	}
}

int EmptyQueue(TYPE_QUEUE *Queue) {
	return (Queue -> Front == Queue -> Rear);
}

int FullQueue(TYPE_QUEUE *Queue) {
	return ((Queue -> Rear+1) % MAXQUEUE == Queue -> Front);
}

int Front(TYPE_QUEUE *Queue) {
	return Queue -> Front;
}

int Rear(TYPE_QUEUE *Queue) {
	return Queue -> Rear;
}

int main() {
	//Doit Eiei
	return 0;
}
