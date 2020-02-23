#include <stdio.h>

#define HEAP_SIZE 9

int heap[HEAP_SIZE];
int heap_cnt;

void push(int value) {

	if (heap_cnt == HEAP_SIZE) {
		printf("overflow ");
		return;
	}

	heap[heap_cnt] = value;
	int cur = heap_cnt;
	int parent = (cur - 1) / 2;

	while (cur > 0 && heap[cur] < heap[parent]) {

		int temp = heap[cur];
		heap[cur] = heap[parent];
		heap[parent] = temp;

		cur = parent;
		parent = (cur - 1) / 2;
	}

	heap_cnt++;
}

int pop() {

	if (heap_cnt == 0) {
		printf("underflow ");
		return -1;
	}

	int value = heap[0];
	heap[0] = heap[--heap_cnt];

	int cur = 0;
	int lef = cur * 2 + 1;
	int rig = cur * 2 + 2;

	while (lef < heap_cnt) {
		int child;

		if (rig == heap_cnt) {
			child = lef;
		}
		else {
			child = heap[lef] < heap[rig] ? lef : rig;
		}

		if (heap[cur] < heap[child]) break;

		int temp = heap[cur];
		heap[cur] = heap[child];
		heap[child] = temp;

		cur = child;
		lef = cur * 2 + 1;
		rig = cur * 2 + 2;
	}

	return value;
}

void init(void) {
	heap_cnt = 0;
}

void process() {

	int a[10] = { 3, 2, 1, 4, 6, 5, 9, 7, 8, 10 };

	for (int i = 0; i < 10; i++) {
		push(a[i]);
	}
	puts("");
}

void output(void) {

	for (int i = 0; i < 10; i++) {
		printf("%d ", pop());
	}
	puts("");
}

int main(void) {
	init();	
	process();
	output();
}