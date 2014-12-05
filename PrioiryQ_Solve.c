#include <stdio.h>

#define MAXQUEUE 5
typedef struct { int Front;
								 int Rear;
								 int Counter;
								 char QueueItem[MAXQUEUE];
								 int Priority[MAXQUEUE];
							 } TYPE_QUEUE;

typedef struct {TYPE_QUEUE Queue[5];
							 } TYPE_PQUEUE;
void InitilizePQ(TYPE_PQUEUE *PQueue) {
	int i;
	for (i = 0; i < 5; ++i) {
		InitilizeQueue(PQUEUE -> Queue[i]);
	}
}

int EmptyPQ(TYPE_QUEUE *PQueue) {
	int i;
	for (i = 0; i < 5; ++i) {
		if (! EmptyQueue(PQueue -> Queue[i]) {
			return 0;	
		}
		return 1;
	}
}

int FullPQ(TYPE_QUEUE *PQueue) {
	int i;
	for (i = 0; i < 5; ++i) {
		if (! FullQueue(PQueue -> Queue[i]) {
			return 0;
		}
		return 1;
	}
}

int InsertPQ(TYPE_QUEUE *PQueue, char Item, int Priority) {
	return (Insert(PQueue -> Queue[Priority], Item);
}

int DeletePQ(TYPE_QUEUE *PQueue, char *Item, int Priority) {
	int i;
	for (i = 0; i < 5; ++i) {
		if (Delete(PQueue -> Queue[i], *Item) {
			return 1;
		}
	}
	return 0;
}
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
	// Try It PQueue eiei
	return 0;
}
