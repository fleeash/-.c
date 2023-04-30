#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void compare(char arr[], int j) {
	while (arr[j] != '\n') {
		

		j++;
	}
}
int main(void) {
	char arr[100];
	int j = 0;
	for (int i = 0; i < 100; i++) {
		scanf("%c", &arr[i]);
		if (arr[i] == '\n') {
			for (j; arr[j] != '\n'; j++) {
				compare(arr, j);
			}
		}
		j++;
		if (arr[i] == '0')
			break;
	}

	return 0;
}