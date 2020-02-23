#include <stdio.h>

#define Q_SIZE 6

int que[Q_SIZE];
int front = 0, rear = 0;

int isEmpty() {
	return front == rear ? 1 : 0;
}

int isFull() {
	return (rear + 1) % Q_SIZE == front ? 1 : 0;
}

int enQue(int value) {
	if (isFull()) return -1;
	else {
		rear = (rear + 1) % Q_SIZE;
		que[rear] = value;

		return 0;
	}
}

int deQue() {
	if (isEmpty()) return -1;
	else {
		front = (front + 1) % Q_SIZE;
		return que[front];
	}
}

int peekQue(int idx) {
	if (isEmpty()) return -1;
	else {
		int t_front = (front + idx) % Q_SIZE;
		return que[t_front];
	}
}

int main() {

	for (int i = 1; i<=10 ; i++) {
		printf("%d ",enQue(i));
	}
	puts("");

	for (int i = 1; i <= rear; i++) {
		printf("%d ", peekQue(i));
	}
	puts("");

	for (int i = 1; i <= 10; i++) {
		printf("%d ", deQue());
	}
	puts("");

	return 0;
}