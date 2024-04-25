#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_LEN_STRING	100
#define MAX_LEN_SUBSTRING	10
#define	Error_Oper	"¬вели не правильную операцию"

int calc(char* string) {
	char oper = '0';
	int index_op = 0;
	int num_1, num_2;
	num_1 = atoi(string);
	for (int i = 0; i < (int)strlen(string); ++i) {
		if (string[i] >= 33 && string[i] < 48) {
			oper = string[i];
			index_op = i;
			break;
		}
	}
	char* new_str = (char*)malloc((index_op+1) * sizeof(char));
	if (!new_str) {
		printf("error");
		return -1;
	}
	for (int j = 0; j < index_op + 1; j++) {
		new_str[j] = string[index_op + 1 + j];
	}

	num_2 = atoi(new_str);
	free(new_str);
	switch (oper)
	{
	case '+':
		return num_1 + num_2;
		break;
	case '-':
		return num_1 - num_2;
		break;
	case '*':
		return num_1 * num_2;
		break;
	case '/':
		return num_1 / num_2;
		break;
	case '%':
		return num_1 % num_2;
		break;
	default:
		printf(Error_Oper);
		exit(1);
		break;
	}
}
void replaceSubstring(char* str, char* substr, char* replacement) {
	int substrLen = (int)strlen(substr);
	int replacementLen = (int)strlen(replacement);
	char* currentPos = str;

	while (1) {
		currentPos = strstr(currentPos, substr);
		if (currentPos == NULL) {
			break;
		}

		int startPos = currentPos - str;
		int endPos = startPos + substrLen;

		char* restOfStr = currentPos + substrLen;
		int restOfStrLen = (int)strlen(restOfStr);

		memmove(currentPos + replacementLen, restOfStr, restOfStrLen + 1);
		memcpy(currentPos, replacement, replacementLen);

		currentPos += replacementLen;
	}
	int i, j = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ':' && str[i] != '\t')
		{
			str[j++] = str[i];
		}
	}

}

int main() {
	setlocale(LC_ALL, "Rus");
	
	int SizeArr = MAX_LEN_STRING * sizeof(char);
	char* arr = (char*)malloc(SizeArr);

	if (!arr) {
		printf("error");
		exit(1);
	}

	printf("¬ведите пример: ");

	fgets(arr, MAX_LEN_STRING, stdin);

	printf("%d\n", calc(arr));
	free(arr);

	char* string = (char*)malloc(MAX_LEN_STRING*sizeof(char));
	char* substr = (char*)malloc(MAX_LEN_SUBSTRING * sizeof(char));
	char* replacement = (char*)malloc(MAX_LEN_SUBSTRING * sizeof(char));

	if (!string || !substr || !replacement) {
		printf("error");
		exit(1);
	}
	puts("¬ведите строку: ");
	fgets(string, MAX_LEN_STRING, stdin);
	puts("¬ведите подстроку, которую надо заменить: ");
	scanf_s("%s", substr, MAX_LEN_SUBSTRING);
	puts("¬ведите на что надо заметить подстроку: ");
	scanf_s("%s", replacement, MAX_LEN_SUBSTRING);
	replaceSubstring(string, substr, replacement);

	printf("Result: %s\n", string);
	free(string);
	return 0;
}