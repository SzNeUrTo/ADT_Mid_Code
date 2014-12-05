#include <stdio.h>

#define MAXQUEUE 5
typedef struct { int Front;
								 int Rear;
								 int Counter;
								 char QueueItem[MAXQUEUE];
								 int Priority[MAXQUEUE];
							 } TYPE_QUEUE;

void InitilizeQueue(TYPE_QUEUE *Queue) {
	int i;
	for (i = 0; i < MAXQUEUE; i++) {
		Queue -> QueueItem[i] = 0;
		Queue -> Priority[i] = 0;
	}
	Queue -> Front = 0;
	Queue -> Rear = 0;
	Queue -> Counter = 0;
}

int Insert(TYPE_QUEUE *Queue, char Item, int Priority) {
	if (Queue -> Counter != MAXQUEUE) {
		int i,j;
		i = Queue -> Rear - 1;
		if (i < 0) i = (MAXQUEUE - 1);
		j = Queue -> Rear;
		if (Queue -> Counter > 0) {
		while (i != Queue -> Front) {
				if (Queue -> Priority[i] > Priority) {
					Queue -> QueueItem[j] = Queue -> QueueItem[i];
					Queue -> Priority[j] = Queue -> Priority[i];
				}
				else {
					break;
				}
				if ((--j) < 0) j = (MAXQUEUE - 1);
				if ((--i) < 0) j = (MAXQUEUE - 1);
			}
		}	
		if (Queue -> Priority[i] > Priority) {
			Queue -> QueueItem[j] = Queue -> QueueItem[i];
			Queue -> Priority[j] = Queue -> Priority[i];
			j--;
			printf("%s\n", "HelloWorld Check");
		}
		Queue -> QueueItem[j] = Item;
		Queue -> Priority[j] = Priority;
		Queue -> Rear = (Queue -> Rear + 1) % MAXQUEUE;
		(Queue -> Counter)++;
		return 1;
	}
	else {
		printf("%s\n", "QueueOverFlow");
		return 0;
	}
}

int Delete(TYPE_QUEUE *Queue, char *Item) {
	if (Queue -> Rear != 0) {
		*Item = Queue -> QueueItem[(Queue -> Front)];
		Queue -> Front = (Queue -> Front + 1) % MAXQUEUE;
		(Queue -> Counter)--;
		return 1;
	}
	else {
		printf("%s\n", "QueueUnderFlow");
		return 0;
	}
}

int EmptyQueue(TYPE_QUEUE *Queue) {
	return (Queue -> Counter == 0);
}

int FullQueue(TYPE_QUEUE *Queue) {
	return (Queue -> Counter == MAXQUEUE);
}

int Front(TYPE_QUEUE *Queue) {
	return Queue -> Front;
}

int Rear(TYPE_QUEUE *Queue) {
	return Queue -> Rear;
}

int main() {
	int i;
	TYPE_QUEUE MyQueue;
	char Data[] = "ABCDE";
	int Priority [] = {3,2,1,2,4};
	for (i = 0; i < MAXQUEUE; ++i) {
		if (Insert(&MyQueue, Data[i], Priority[i]))
		{
			printf("Data %c Priority %d | ", Data[i], Priority[i]);
		}
	}
	printf("\n");
	for (i = 0; i < MAXQUEUE; ++i) {
		printf("Data %c Priority %d | ", MyQueue.QueueItem[i], MyQueue.Priority[i]);
	}
	printf("\n");
	return 0;
}
