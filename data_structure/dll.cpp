#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define NODE_MAX 1000
typedef struct NODE {
	int value;
	NODE* prev;
	NODE* next;
}NODE;

NODE head;
NODE tail;
NODE node_mem[NODE_MAX];
int node_mem_cnt;

void init(void) {
	head.prev = 0;
	head.next = &tail;
	
	tail.next = 0;
	tail.prev = &head;
}

NODE* make_new_node(int value) {
	NODE* node = &node_mem[node_mem_cnt++];
	node->value = value;
	node->prev = 0;
	node->next = 0;

	return node;
}

void output(void) {
	NODE* node = head.next;

	while (node != &tail) {
		printf("%d ", node->value);
		node = node->next;
	}
	puts("");
}

void delete_old_node() {
	head.next = head.next->next;
	head.next->next->prev = &head;
}

void delete_node(int value) {
	NODE* node = head.next;

	while (node) {
		if (node->value == value) {
			node->prev->next = node->next;
			node->next->prev = node->prev;

			break;
		}

		node = node->next;
	}
}

void process() {
	for (int i = 1; i <= 10; i++) {
		NODE* new_node = make_new_node(i);
		
		new_node->prev = tail.prev;
		tail.prev->next = new_node;

		new_node->next = &tail;
		tail.prev = new_node;
	}

	output();
	delete_old_node();
	output();
	delete_node(5);
	output();
}

int main(void) {
	init();
	process();
}