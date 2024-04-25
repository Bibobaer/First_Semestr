#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_HEIGHT	5
#define ARRAY_WIDTH		6



void swap(int* var_1, int* var_2) {
	int conv_var = *var_1;
	*var_1 = *var_2;
	*var_2 = conv_var;
}

void BubbleSort(int* array, int arrSize) {
	for (int i = 0; i < arrSize; ++i) {
		for (int j = 0; j + 1 < arrSize - i; ++j) {
			if (array[j + 1] < array[j]) {
				swap(&array[j], &array[j + 1]);
			}
		}
	}
}

void Multi_table(int arr[ARRAY_HEIGHT][ARRAY_WIDTH]) {
	for (int i = 0; i < ARRAY_HEIGHT*ARRAY_WIDTH; ++i) {
		arr[i / ARRAY_WIDTH][i % ARRAY_WIDTH] = (i / ARRAY_WIDTH + 1) * (i % ARRAY_WIDTH + 1);
	}
}

void Feel_Arr_Rand(int** arr, int num) {
	for (int i = 0; i < ARRAY_HEIGHT; ++i) {
		for (int j = 0; j < ARRAY_WIDTH; ++j) {
			arr[i][j] = rand() % (2 * num + 1) - num;
		}

	}
}
/*void sortArr(int arr[ARRAY_HEIGHT][ARRAY_WIDTH], int A, int B) {
	for (int i = 0; i < ARRAY_HEIGHT; ++i) {
		for (int j = 0; j < ARRAY_WIDTH; ++j) {
			arr[i][j] = rand() % (B - A + 1) + A;
		}
	}
	printf("Unsorted array:\n");
	PrintStaticArray(arr);

	for (int i = 0; i < ARRAY_HEIGHT; ++i) {
		BubbleSort(arr[i], ARRAY_WIDTH);
	}
	for (int i = 0; i < ARRAY_HEIGHT -1; i++) {
		if (arr[i] > arr[i + 1]) {
			swap(arr[i], arr[i + 1]);
		}
	}

	printf("Sorted array:\n");
	PrintStaticArray(arr);
}*/

void PrintStaticArray(int** arr) {
	for (int i = 0; i < ARRAY_HEIGHT; ++i) {
		for (int j = 0; j < ARRAY_WIDTH; ++j) {
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}
}

int main() {
	srand((unsigned)time(NULL));
	int** arr_1;
	arr_1 = malloc(ARRAY_HEIGHT*(ARRAY_WIDTH*sizeof(int) + sizeof(int*)));
	int arr_2[ARRAY_HEIGHT][ARRAY_WIDTH];
	int arr_3[ARRAY_HEIGHT][ARRAY_WIDTH];
	int A, B;

	int N;

	printf("enter number: >0 ");
	scanf_s("%d", &N);
	Feel_Arr_Rand(arr_1, N);
	PrintStaticArray(arr_1);

	/*PrintStaticArray(arr_1);
	printf("\n");
	Multi_table(arr_2);
	PrintStaticArray(arr_2);

	printf("Enter [A, B] arr random numbers:\n");
	scanf_s("%d %d", &A, &B);*/
	free(arr_1);
	return 0;
}