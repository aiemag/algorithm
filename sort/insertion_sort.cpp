#include <stdio.h>

#define N 100

int n;
int a[N];

void do_insertion_sort() {
	int i, j, key;

	for (i = 1; i<n ; i++) {
		key = a[i];

		for (j = i - 1; j > -1 && a[j] > key ; j--) {
			a[j + 1] = a[j];
		}
		a[j + 1] = key;
	}
}

void init(void) {

}

void input(void) {
	int i;
	freopen("./input.txt", "r", stdin);

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
}

void process() {
	do_insertion_sort();
}

void output(void) {
	int i, j;
	for (i = 0; i < n; i++) {		
		printf("%d ", a[i]);				
	}
	puts("");
}

int main(void) {
	init();
	input();
	process();
	output();
}