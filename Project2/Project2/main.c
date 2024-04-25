#include <stdio.h>



int main() {
	FILE* file;
	fopen_s(&file, "test.txt", "r");
	if (file == NULL)
		return 1;
	fclose(file);
	return 0;
}