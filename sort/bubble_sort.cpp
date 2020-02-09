#include <stdio.h>

int n = 5;
int a[5] = {3, 2, 4, 5, 1};

void do_bubble_sort() {
	int i, j, temp;

	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j+1];
				a[j + 1] = temp;
			}
		}
	}
}

void process() {
	do_bubble_sort();
}

void output(void) {
	int i, j;
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	puts("");
}

int main(void) {
	process();
	output();
}