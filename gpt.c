#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Function to count the number of errors in an 8x8 chessboard
int chess88(char bord[][50], int x, int y) {
    int err = 0;
    for (int i = x; i < x + 8; i++) {
        for (int j = y; j < y + 8; j++) {
            if (bord[i][j] == bord[i + 1][j])
                err++;
            if (bord[i][j] == bord[i][j + 1])
                err++;
        }
    }
    return err / 4; // return the number of errors
}

int main(void) {
    int N = 0, M = 0;
    char bord[50][50];
    scanf("%d %d", &N, &M);
    if (N < 8 || M < 8) // Check if the board is at least 8x8
        return -1;
    if (N > 50 || M > 50) // Check if the board is at most 50x50
        return -1;
    // Read the board
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf(" %c", &bord[i][j]);
        }
    }
    int Err[100]; // Array to store the number of errors
    int ErrNum = 0; // Represents the index value of Err
    int x = 0, y = 0; // part to cut
    // Loop through all possible 8x8 chessboards and count the number of errors
    for (x = 0; x < (N - 7); x++) {
        for (y = 0; y < (M - 7); y++) {
            Err[ErrNum] = chess88(bord, x, y);
            ErrNum++;
        }
    }
    // Find the minimum number of errors
    int MinErr = Err[0];
    for (int i = 0; i < ErrNum; i++) {
        if (MinErr > Err[i])
            MinErr = Err[i];
    }
    printf("%d", MinErr);
    return 0;
}
