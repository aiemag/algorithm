#include <stdio.h>

int main(void) {

	int i, j;
	int arr[] = {1, 2, 3, 4, 5};
	int n = 5;

	for (i = 0; i < (1 << n); i++) {
		for (j = 0; j < n; j++) {
			if (i& (1 << j)) {
				printf("%d ", arr[j]);
			}
		}
		printf("\n");
	}

	return 0;
}