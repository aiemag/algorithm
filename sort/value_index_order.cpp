#include <stdio.h>

#define N 100

int a[N];
int a_idx[N];
int n;

void order_value_index() {
	int i, j, min_idx;

	for (i = 0; i < n; i++) {
		a_idx[i] = i;
	}

	for (i = 0; i < n - 1 ; i++) {
		min_idx = i;

		for (j = i + 1; j < n; j++) {
			if (a[a_idx[min_idx]] < a[a_idx[j]]) {
				min_idx = j;
			}
		}

		int temp = a_idx[min_idx];
		a_idx[min_idx] = a_idx[i];
		a_idx[i] = temp;
	}
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
	order_value_index();
}

void output(void) {

	int i;

	printf("idx - ");
	for (i = 0; i < n; i++) {
		printf("%d ", a_idx[i]);
	}

	puts("");
	printf("val - ");
	for (i = 0; i < n; i++) {
		printf("%d ", a[a_idx[i]]);
	}
}

int main(void) {
	input();
	process();
	output();
}