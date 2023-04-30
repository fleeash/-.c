#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int chess88(char bord[][50], int x, int y) {
	int err = 0;
	for (int i = x; i < x + 8; i++) {
		for (int j = y; j < y + 8; j++) {
			if (j == y + 7 && i != x + 7) {
				if (bord[i][j] != bord[i + 1][j - 7]) {
					err++;
				}
			}
			if (bord[i][j] == bord[i][j + 1])
				err++;
		}
	}
	return err / 2; // 에러의 개수 반환
}

int main(void) {
	int N = 0, M = 0;
	char bord[50][50];
	scanf("%d %d", &N, &M);
	if (N < 8 || M < 8)
		return -1;
	if (N > 50 || M > 50)
		return -1;
	/* bord 읽기 */
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %c", &bord[i][j]);
		}
	}
	int Err[100];  // Err의 수를 저장할 배열
	int ErrNum = 0; // Err의 인덱스 값을 표현
	int x = 0, y = 0;    // 잘라올 부분
	// int repeatNum = (N - 8) + (M - 8) + (N - 8) * (M - 8);  

	for ( x = 0; x < (N - 7); x ++) {
		for ( y = 0; y < (M - 7); y++) {
			Err[ErrNum] = chess88(bord, x, y);
			ErrNum++;
		}
	}
	ErrNum -= 1;
	int MinErr = Err[0];
	for (int i = 0; i <= ErrNum; i++) {
		if (MinErr > Err[i])
			MinErr = Err[i];
	}
	printf("%d", MinErr);
	return 0;
}