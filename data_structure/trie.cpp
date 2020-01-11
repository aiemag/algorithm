#include <stdio.h>

#define ALPHABET_N 26
#define MAX_N 1000001

typedef struct NODE {
	NODE* character[ALPHABET_N];
	int cnt;
}NODE;

NODE* head;
NODE mem[MAX_N];
int mem_cnt;

void init(void) {
	int i, j;

	for (i = 0; i < mem_cnt; i++) {
		for (j = 0; j < ALPHABET_N; j++) {
			mem[i].character[j] = NULL;
		}
		mem[i].cnt = 0;
	}
	mem_cnt = 0;
	head = &mem[mem_cnt++];
}

void insert(int str_size, char *str) {

	int i;

	NODE* node = head;
	for (i = 0; i < str_size; i++) {
		int c = str[i] - 'a';
		if (node->character[c] == NULL) {
			node->character[c] = &mem[mem_cnt++];
		}
		node = node->character[c];
		node->cnt++;
	}
}

int get_count(int str_size, char *str) {

	int i;

	NODE* node = head;

	for (i = 0; i < str_size; i++) {
		int c = str[i] - 'a';
		if (node->character[c] == NULL) {
			return 0;
		}

		node = node->character[c];
	}

	return node->cnt;
}

int main(void) {

	init();

	char buf1[100] = "abc";
	insert(3, buf1);

	char buf2[100] = "abdc";
	insert(4, buf2);
	insert(4, buf2);

	printf("cnt : %d\n", get_count(3, buf1));
	printf("cnt : %d\n", get_count(4, buf2));

	return 0;
}