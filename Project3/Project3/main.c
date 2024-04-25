#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void Reverse_Array(int *arr, int n) {
	for (int i = 0; i < n/2; ++i) {
		int tmp = arr[i];
		arr[i] = arr[n - i - 1];
		arr[n - i - 1] = tmp;
	}
}


int* dec_to_bin(int num, int bytes, int* mas) {
	int n = 8 * bytes;
	int i = 0;
	for (int j = 0; j < n; ++j)
		mas[j] = 0;

	if (num < 0) {
		num = abs(num)-1;
		while (num)
		{
			*(mas + i) = num % 2;
			num /= 2;
			i++;

		}
		for (int m = 0; m < n; m++) {
			if (mas[m] == 1)
				mas[m] = 0;
			else
				mas[m] = 1;
		}
		Reverse_Array(mas, n);
		*mas = 1;
	}
	else {
		while (num)
		{
			*(mas + i) = num % 2;
			num /= 2;
			i++;

		}

		Reverse_Array(mas, n);
	}
	

	return mas;
}
void Print_Qwart_Arr(int* arr, int n) {
	for (int i = 1; i <= n;i++) {
		printf("%d", arr[i-1]);
		if (i % 4 == 0) {
			printf(" ");
		}
	}
}

void Print_Array(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main() {
	setlocale(LC_ALL, "Rus");
	int number, dimension;

	int mas_to_rev[] = {0, 10, 20, 30, 40};
	int cnt_elem = sizeof(mas_to_rev) / sizeof(*mas_to_rev);

	Print_Array(mas_to_rev, cnt_elem);
	Reverse_Array(mas_to_rev, cnt_elem);
	Print_Array(mas_to_rev, cnt_elem);

	printf("¬ведите разд€дность: ");
	scanf_s("%d", &dimension);
	printf("¬ведите число, которое хотите перевести: ");
	scanf_s("%d", &number);

	int size = 8 * dimension;
	int* arr = (int*)malloc(size * sizeof(int));
	if (!arr) {
		printf("error");
	}
	arr = dec_to_bin(number, dimension, arr);
	Print_Qwart_Arr(arr, size);
	free(arr);

	return 0;
}