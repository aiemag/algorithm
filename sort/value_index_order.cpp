#include <stdio.h>

#define N 100

int a[N] = { 1, 1, 1, 2, 3 };
int a_idx[N];
int n = 5;

void order_value_index() {
	puts("\order_value_index()");
	int i, j, max_idx;

	for (i = 0; i < n; i++) {
		a_idx[i] = i;
	}

	for (i = 0; i < n - 1 ; i++) {
		max_idx = i;

		for (j = i+1; j < n; j++) {
			if (a[a_idx[max_idx]] < a[a_idx[j]]) {
				max_idx = j;
			}
		}

		int temp = a_idx[max_idx];
		a_idx[max_idx] = a_idx[i];
		a_idx[i] = temp;
	}
}

void order_value_index_() {
	puts("\order_value_index_()");
	int i, j, max_idx;

	for (i = 0; i < n; i++) {
		a_idx[i] = i;
	}

	for (i = 0; i < n - 1; i++) {
		max_idx = i;

		for (j = n - 1; j > i; j--) {
			if (a[a_idx[max_idx]] < a[a_idx[j]]) {
				max_idx = j;
			}
		}

		int temp = a_idx[max_idx];
		a_idx[max_idx] = a_idx[i];
		a_idx[i] = temp;
	}
}

void order_value_index_asc() {
	puts("\order_value_index_asc()");
	int i, j, max_idx;

	for (i = 0; i < n; i++) {
		a_idx[i] = i;
	}

	for (i = 0; i < n - 1; i++) {
		max_idx = i;

		for (j = i + 1; j < n; j++) {
			if (a[a_idx[max_idx]] < a[a_idx[j]]) {
				max_idx = j;
			}
			else if (a[a_idx[max_idx]] == a[a_idx[j]]) {
				if (a_idx[max_idx] > a_idx[j]) {
					max_idx = j;
				}
			}
		}

		int temp = a_idx[max_idx];
		a_idx[max_idx] = a_idx[i];
		a_idx[i] = temp;
	}
}

void order_value_index_asc_alt() {
	puts("\order_value_index_asc_alt()");
	int i, j;

	for (i = 0; i < n; i++) {
		a_idx[i] = i;
	}

	for (i = 0; i < n - 1; i++) {
		for (j = n-1; j > i; j--) {
			if (a[a_idx[j - 1]] < a[a_idx[j]]) {
				int temp = a_idx[j];
				a_idx[j] = a_idx[j-1];
				a_idx[j-1] = temp;
			}
		}
	}
}

void output(void) {

	int i;

	printf("val - ");
	for (i = 0; i < n; i++) {
		printf("%d ", a[a_idx[i]]);
	}

	puts("");
	printf("idx - ");
	for (i = 0; i < n; i++) {
		printf("%d ", a_idx[i]);
	}
	puts("");
}

int main(void) {
	order_value_index();
	output();
	order_value_index_();
	output();
	order_value_index_asc();
	output();
	order_value_index_asc_alt();
	output();
}