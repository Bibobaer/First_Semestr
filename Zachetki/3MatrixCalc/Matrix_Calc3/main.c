#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <direct.h>
#include <string.h>

#define Not_Square_Matrix	"Данные(ая) матрицы(а) не являются(ется) квадратными(ой)"
#define Col_Dont_Equal_Row	"Кол-во столбцов первой матрицы не совпадает с кол-вом строк второй"
#define Alloc_Error		"Не удалось выделить память"
#define Not_right	"Вы ввели что-то не так"
#define File_Not_Open	"Не удалось открыть файл"

typedef struct Matrix{
	int Row;
	int Col;
	int** ArrayofNumbers;
}Matrix;

void Print_Matrix(Matrix MM) {
	for (int i = 0; i < MM.Row; i++) {
		for (int j = 0; j < MM.Col; j++) {
			printf("%d ", MM.ArrayofNumbers[i][j]);
		}
		printf("\n");
	}
}

void FilePrintMatrix(Matrix matrix, int det) {
	_mkdir("Results");
	char namefile[50] = { NULL };
	time_t mytime = time(NULL);
	struct tm* t = localtime(&mytime);
	sprintf(namefile, "Results/result__%d_%d_%d__%d_%d_%d.txt\0", t->tm_mday, t->tm_mon + 1, t->tm_year + 1900, t->tm_hour, t->tm_min, t->tm_sec);
	FILE* file_3;
	fopen_s(&file_3, namefile, "w");
	if (file_3 == NULL) {
		printf(File_Not_Open);
		return;
	}
	if (matrix.Row != 0 && matrix.Col != 0 && matrix.ArrayofNumbers != NULL) {
		for (int i = 0; i < matrix.Row; i++) {
			for (int j = 0; j < matrix.Col; j++) {
				fprintf(file_3, "%d", matrix.ArrayofNumbers[i][j]);
			}
			fprintf(file_3, "\n");
		}
	}
	else{
		fprintf(file_3, "%d", det);
	}
	fclose(file_3);
}
void Alloc_the_Matrix(Matrix* mainMatrix, int rows, int cols) {
	mainMatrix->Row = rows;
	mainMatrix->Col = cols;
	mainMatrix->ArrayofNumbers = (int**)malloc((mainMatrix->Row) * sizeof(int*));
	if (!mainMatrix->ArrayofNumbers) {
		printf(Alloc_Error);
		return;
	}

	for (int i = 0; i < (mainMatrix->Row); i++) {
		mainMatrix->ArrayofNumbers[i] = (int*)malloc((mainMatrix->Col) * sizeof(int));
		if (!mainMatrix->ArrayofNumbers[i]) {
			printf(Alloc_Error);
			return;
		}
	}
}

void CountintRowsandCols(FILE* file, const char* FileName, int rows, int cols, int tmp) {
	while (fscanf_s(file, "%d", &tmp) == 1)
	{
		if (fgetc(file) == '\n')
		{
			rows++;
		}
	}
	fseek(file, 0, SEEK_SET);
	while (fscanf_s(file, "%d", &tmp) == 1)
	{
		cols++;
		if (fgetc(file) == '\n')
			break;
	}
	fclose(file);
}

void AddNumberstoMatrix(Matrix* matrix, FILE* file, const char* FileName, int number) {
	fopen_s(&file, FileName, "r");
	if (file == NULL)
		exit(1);
	while (!feof(file)) {
		for (int i = 0; i < matrix->Row; i++) {
			for (int j = 0; j < matrix->Col; j++) {
				fscanf_s(file, "%d", &number);
				matrix->ArrayofNumbers[i][j] = number;
			}
		}
	}
	fclose(file);
}

Matrix Addition_Matrix(Matrix mat_1, Matrix mat_2) {
	Matrix Result = {0, 0, NULL};
	if (mat_1.Col == mat_1.Row && mat_2.Col == mat_2.Row && mat_1.Col == mat_2.Row) {
		Alloc_the_Matrix(&Result, mat_1.Row, mat_2.Col);
		for (int i = 0; i < Result.Row; i++)
			for (int j = 0; j < Result.Col; j++)
				Result.ArrayofNumbers[i][j] = mat_1.ArrayofNumbers[i][j] + mat_2.ArrayofNumbers[i][j];
		return Result;
	}

	printf(Not_Square_Matrix);
	exit(1);
}

Matrix Subtraction_Matrix(Matrix mat_1, Matrix mat_2) {
	Matrix Result = {0, 0, NULL};
	if (mat_1.Col == mat_1.Row && mat_2.Col == mat_2.Row && mat_1.Col == mat_2.Row) {
		Alloc_the_Matrix(&Result, mat_1.Row, mat_2.Col);
		for (int i = 0; i < Result.Row; i++)
			for (int j = 0; j < Result.Col; j++)
				Result.ArrayofNumbers[i][j] = mat_1.ArrayofNumbers[i][j] - mat_2.ArrayofNumbers[i][j];
		return Result;
	}
	printf(Not_Square_Matrix);
	exit(1);
}

Matrix Multiply_Matrix(Matrix mat_1, Matrix mat_2) {
	Matrix Result = { 0, 0, NULL };
	if (mat_1.Col == mat_2.Row) {
		Alloc_the_Matrix(&Result, mat_1.Row, mat_2.Col);
		for (int i = 0; i < mat_1.Row; i++) {
			for (int j = 0; j < mat_2.Col; j++) {
				Result.ArrayofNumbers[i][j] = 0;
				for (int k = 0; k < mat_1.Col; k++) {
					Result.ArrayofNumbers[i][j] += mat_1.ArrayofNumbers[i][k] * mat_2.ArrayofNumbers[k][j];
				}
			}
		}
		return Result;
	}
	printf(Col_Dont_Equal_Row);
	exit(1);
}

Matrix Transposition_Matrix(Matrix matrix) {
	Matrix Result = {0,0,NULL};
	Alloc_the_Matrix(&Result, matrix.Col, matrix.Row);
	for (int i = 0; i < matrix.Row; i++)
		for (int j = 0; j < matrix.Col; j++)
			Result.ArrayofNumbers[j][i] = matrix.ArrayofNumbers[i][j];
	return Result;
}

int Determinant_Matrix(Matrix matrix) {
	Matrix submatrix = {0, 0, NULL };
	if (matrix.Row == matrix.Col) {
		int det = 0;
		if (matrix.Row == 1) {
			det = matrix.ArrayofNumbers[0][0];
			return det;
		}
		else if (matrix.Row == 2) {
			det = matrix.ArrayofNumbers[0][0] * matrix.ArrayofNumbers[1][1] - matrix.ArrayofNumbers[1][0] * matrix.ArrayofNumbers[0][1];
			return det;
		}
		else if (matrix.Row == 3) {
			det = matrix.ArrayofNumbers[0][0] * matrix.ArrayofNumbers[1][1] * matrix.ArrayofNumbers[2][2] + 
				matrix.ArrayofNumbers[0][1] * matrix.ArrayofNumbers[1][2] * matrix.ArrayofNumbers[2][0] + 
				matrix.ArrayofNumbers[0][2] * matrix.ArrayofNumbers[1][0] * matrix.ArrayofNumbers[2][1] - 
				matrix.ArrayofNumbers[0][2] * matrix.ArrayofNumbers[1][1] * matrix.ArrayofNumbers[2][0] - 
				matrix.ArrayofNumbers[0][0] * matrix.ArrayofNumbers[1][2] * matrix.ArrayofNumbers[2][1] - 
				matrix.ArrayofNumbers[0][1] * matrix.ArrayofNumbers[1][0] * matrix.ArrayofNumbers[2][2];
			return det;
		}
		else {
			int tmp = matrix.Row;
			Alloc_the_Matrix(&submatrix, matrix.Row - 1, matrix.Col - 1);
			for (int i = 0; i < tmp; i++) {
				int sub_i = 0;
				for (int j = 1; j < tmp; j++) {
					int sub_j = 0;
					for (int k = 0; k < tmp; k++) {
						if (k == j)
							continue;
						submatrix.ArrayofNumbers[sub_i][sub_j] = matrix.ArrayofNumbers[j][k];
						sub_j++;
					}
					sub_i++;
				}
				det += (i % 2 == 0 ? 1 : -1) * matrix.ArrayofNumbers[0][i] * Determinant_Matrix(submatrix);
			} 
			return det;
		}
	}
	printf(Not_Square_Matrix);
	exit(1);
}

void CalcMatrix(Matrix Matrix_A, Matrix Matrix_B, char operation) {
	char tmp = '0';
	Matrix tm = { 0, 0, NULL };
	switch (operation)
	{
	case '+':
		Print_Matrix(Addition_Matrix(Matrix_A, Matrix_B));
		FilePrintMatrix(Addition_Matrix(Matrix_A, Matrix_B), 0);
		break;
	case '-':
		Print_Matrix(Subtraction_Matrix(Matrix_A, Matrix_B));
		FilePrintMatrix(Subtraction_Matrix(Matrix_A, Matrix_B), 0);
		break;
	case '*':
		Print_Matrix(Multiply_Matrix(Matrix_A, Matrix_B));
		FilePrintMatrix(Multiply_Matrix(Matrix_A, Matrix_B), 0);
		break;
	case 't':
		printf("Какую матрицу вы хотите транспонировать?(А или В): ");
		scanf_s(" %c", &tmp, 1);
		if (tmp == 'A') {
			Print_Matrix(Transposition_Matrix(Matrix_A));
			FilePrintMatrix(Transposition_Matrix(Matrix_A), 0);
			break;
		}
		else if (tmp == 'B') {
			Print_Matrix(Transposition_Matrix(Matrix_B));
			FilePrintMatrix(Transposition_Matrix(Matrix_B), 0);
			break;
		}
		else {
			printf(Not_right);
			break;
		}
		break;
	case 'd':
		printf("Какой матрицы вы хотите найти определитель?(А или В): ");
		scanf_s(" %c", &tmp, 1);
		if (tmp == 'A') {
			printf("%d", Determinant_Matrix(Matrix_A));
			FilePrintMatrix(tm, Determinant_Matrix(Matrix_A));
			break;
		}
		else if (tmp == 'B') {
			printf("%d", Determinant_Matrix(Matrix_B));
			FilePrintMatrix(tm, Determinant_Matrix(Matrix_B));
			break;
		}
		else {
			printf(Not_right);
			break;
		}
		break;
	default:
		printf(Not_right);
		break;
	}
}


int main() {
	setlocale(LC_ALL, "Rus");
	const char* filename_1 = "Matrix_1.txt";
	const char* filename_2 = "Matrix_2.txt";
	FILE* file_1;
	FILE* file_2;
	fopen_s(&file_1, filename_1, "r");
	fopen_s(&file_2, filename_2, "r");

	int num_1 = 0;
	int num_2 = 0;

	char oper = '0';

	int rows_1 = 1;
	int cols_1 = 0;
	int rows_2 = 1;
	int cols_2 = 0;

	Matrix matrix_A = { 0, 0, NULL };
	Matrix matrix_B = { 0, 0, NULL };

	CountintRowsandCols(file_1, filename_1, rows_1, cols_1, num_1);
	CountintRowsandCols(file_2, filename_2, rows_2, cols_2, num_2);

	Alloc_the_Matrix(&matrix_A, rows_1, cols_1);
	Alloc_the_Matrix(&matrix_B, rows_2, cols_2);

	AddNumberstoMatrix(&matrix_A, file_1, filename_1, num_1);
	AddNumberstoMatrix(&matrix_B, file_2, filename_2, num_2);

	printf("Матрица А:\n");
	Print_Matrix(matrix_A);
	printf("\n");
	printf("Матрица В\n");
	Print_Matrix(matrix_B);
	printf("\n");
	printf("Какую операцию вы хотите сделать?\n(+,-,*,t-транспонирование,d-определитель)\n");
	scanf_s(" %c", &oper, 1);
	CalcMatrix(matrix_A, matrix_B, oper);

	return 0;
}