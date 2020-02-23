#include <stdio.h>
#include <malloc.h>

typedef struct Node {
	int data;
	Node* next;
}Node;

typedef struct QueuePointer {
	Node* front;
	Node* rear;
}QueuePointer;

QueuePointer* LQ;

QueuePointer* createLinkedQueue() {
	LQ = (QueuePointer*)malloc(sizeof(QueuePointer));
	LQ->front = NULL;
	LQ->rear = NULL;

	return LQ;
}

int isEmpty(QueuePointer* LQ) {
	if (LQ->front == NULL && LQ->rear == NULL) return 1;
	//if (LQ->front == NULL) return 1;
	else return 0;
}

void enQueue(int item) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = item;
	newNode->next = NULL;
	if (isEmpty(LQ)) {
		LQ->front = newNode;
		LQ->rear = newNode;
	}
	else {
		LQ->rear->next = newNode;
		LQ->rear = newNode;
	}
}

int deQueue() {
	Node* old = LQ->front;
	int item;
	if (isEmpty(LQ)) return 0;
	else {
		item = old->data;
		LQ->front = LQ->front->next;
		if (LQ->front==NULL) {
			LQ->rear = NULL;
		}
		free(old);
		return item;
	}
}

int main(void) {

	createLinkedQueue();
	for (int i = 1; i <= 10; i++) {
		enQueue(i);
	}

	for (int i = 1; i <= 10; i++) {
		printf("%d ",deQueue());
	}
	puts("");

	for (int i = 1; i <= 10; i++) {
		enQueue(i);
	}

	for (int i = 1; i <= 10; i++) {
		printf("%d ", deQueue());
	}
	puts("");

	return 0;
}