#include <stdio.h>

int do_binary_search(int ary[], int len, int key) {
	int start = 0;
	int end = len - 1;
	int mid;

	while (start <= end) {
		mid = (start + end) / 2;

		if (ary[mid] == key) {
			return mid;
		}
		else if (ary[mid] > key) {
			end = mid - 1;
		}
		else if (ary[mid] < key) {
			start = mid + 1;
		}
	}
	return -1;
}

int do_binary_serarch_recursive(int ary[], int low, int high, int key) {
	int mid = (low + high) / 2;

	if (key == ary[mid]) {
		return mid;
	}
	else if (key < ary[mid]) {
		return do_binary_serarch_recursive(ary, low, mid - 1, key);
	}
	else if (key > ary[mid]) {
		return do_binary_serarch_recursive(ary, mid+1, high, key);
	}

	return -1;
}

int main(void) {

	int i, j;
	int ary[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int n = 10;

	printf("found index : %d", do_binary_search(ary, n, 7));
	printf("\nfound index : %d", do_binary_serarch_recursive(ary, 0, n-1, 7));

	return 0;
}