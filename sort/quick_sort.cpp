#include <stdio.h>

#define N 100

int n;
int a[N];

void swap(int i1, int i2) {
	int temp = a[i1];
	a[i1] = a[i2];
	a[i2] = temp;
}

int partition(int lef, int rig) {
	int pivot = a[lef];
	int low = lef + 1;
	int high = rig;

	while (low <= high) {
		while (pivot >= a[low] && low <= rig) ++low;
		while (pivot <= a[high] && high >= lef + 1) --high;
		if (low <= high) swap(low, high);
	}
	swap(lef, high);

	return high;
}

void do_quick_sort(int lef, int rig) {
	if (lef <= rig) {
		int pivot = partition(lef, rig);
		do_quick_sort(lef, pivot-1);
		do_quick_sort(pivot+1, rig);
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
	do_quick_sort(0, n-1);
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