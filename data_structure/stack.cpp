#include <stdio.h>

#define MAX_N 100

int stack[MAX_N];
int top = -1;

void push(int value) {
	if (top >= MAX_N-1) return;
	else stack[++top] = value;
}

int pop() {
	if (top == -1) return -1;
	else return stack[top--];
}

int main() {

	int value;

	for (int i = 1; i <= 3; i++) {
		push(i);
	}

	for (int i = 1; i <= 3; i++) {
		printf("popped up : %d\n", pop());
	}
	
	return 0;
}