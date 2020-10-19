#include <stdio.h>
#define LEN 12

int a[LEN] = {1, 9, 3, 8, 4, 5, 5, 9, 10, 3, 4, 5};
int tree[4*LEN];

int init(int start, int end, int node) {
	
	if (start == end) return tree[node] = a[start];

	int mid = (start + end) / 2;
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

int sum(int start, int end, int node, int left, int right) {
	if(end < left || right < start) return 0;
	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int index, int dif) {
	if (index < start || end < index) return;

	tree[node] += dif;
	if (start == end) return;
	int mid = (start + end) / 2;
	update(start, mid, node * 2, index, dif);
	update(mid + 1, end, node * 2 + 1, index, dif);
}

int main(void) {
	init(0, 11, 1);
	printf("%d\n", sum(0, 11, 1, 0, 11));
	printf("%d\n", sum(0, 11, 1, 4, 8));
	update(0, 11, 1, 5, -5);
	printf("%d\n", sum(0, 11, 1, 0, 11));
}