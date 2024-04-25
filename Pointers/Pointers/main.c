#include <stdio.h>
#include <malloc.h>
#include <locale.h>

void swap(int* var_1, int* var_2) {
	int conv_var = *var_1;
	*var_1 = *var_2;
	*var_2 = conv_var;
}

void bubble_sort(int* arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; ++j) {
			if (arr[j] > arr[j + 1]) {
				int* pJ_1 = &arr[j], * pJ_2 = &arr[j + 1];
				swap(pJ_1, pJ_2);
			}
		}
	}
}
void selection_sort(int* arr, int n) {
	int pos;

	for (int i = 0; i < n-1; ++i) {
		pos = i;
		for (int j = i + 1; j < n; ++j) {
			if (arr[pos] > arr[j])
				pos = j;
		}
		if (pos != i) {
			int* p1 = &arr[i], *p2 = &arr[pos];
			swap(p1, p2);
		}
	}
}

int main() {
	setlocale(LC_ALL, "Rus");
	int x = 243, y = 5;
	int *pX = &x, *pY = &y;

	int n = 4;
	int* arr_1 = (int*)malloc(n * sizeof(int));
	int* arr_2 = (int*)malloc(n * sizeof(int));

	printf("До смены: первое число = %d, второе число = %d\n", *pX, *pY);
	swap(pX, pY);
	printf("После смены: первое число = %d, второе число = %d\n", *pX, *pY);

	if (arr_1 == NULL || arr_2 == NULL) {
		printf("error");
		return -1;
	}

	for (int i = 0; i < n; i++) {
		int x = 0;
		scanf_s("%d", &x);
		arr_1[i] = x;
	}
	bubble_sort(arr_1, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", arr_1[i]);
	}


	for (int i = 0; i < n; i++) {
		int y = 0;
		scanf_s("%d", &y);
		arr_2[i] = y;
	}
	selection_sort(arr_2, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", arr_2[i]);
	}

	free(arr_1);
	free(arr_2);
	return 0;
}