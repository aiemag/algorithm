#include <stdio.h>

int n = 6;
int a[6] = {-1, 3, 2, 4, 1, 4};	// 5 elements, 0 index is discarded
int b[6];	// answer
int c[6];	// temporary array

void do_count_sort() {
	int i, j;

	for (i = 1; i <n ; i++) {
		c[i] = 0;
	}

	for (i = 1; i < n; i++) {
		c[a[i]]++;
	}

	for (i = 2; i < n; i++) {
		c[i] = c[i - 1] + c[i];
	}
	
	for (i = n - 1; i > 0; i--) {
		b[c[a[i]]--] = a[i];
	}	
}

void process() {
	do_count_sort();
}

void output(void) {
	int i, j;
	for (i = 1; i < n; i++) {
		printf("%d ", b[i]);
	}
	puts("");
}

int main(void) {
	process();
	output();
}