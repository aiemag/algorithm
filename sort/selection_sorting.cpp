#include <stdio.h>

#define N 100

int n;
int a[N];

void sort_selection() {
	int i, j, min_idx, temp;

	for (i = 0; i < n - 1; i++) {
		min_idx = i;
		for (j = i + 1; j < n; j++) {
			if (a[min_idx] > a[j]) {
				min_idx = j;
			}
		}
		if (i != min_idx) {
			temp = a[min_idx];
			a[min_idx] = a[i];
			a[i] = temp;
		}
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
	sort_selection();
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