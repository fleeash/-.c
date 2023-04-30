#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int N;
	scanf("%d", &N);
	for(int i=0; i < N; i+=4)
		printf("long ");
	printf("int");
	return 0;
}