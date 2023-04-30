#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    char** board = (char**)malloc(sizeof(char*) * n);
    for (int i = 0; i < n; i++) {
        board[i] = (char*)malloc(sizeof(char) * (m + 1));
        scanf("%s", board[i]);
    }
    int min = 64;
    for (int i = 0; i <= n - 8; i++) {
        for (int j = 0; j <= m - 8; j++) {
            int count1 = 0, count2 = 0;
            for (int k = i; k < i + 8; k++) {
                for (int l = j; l < j + 8; l++) {
                    if ((k + l) % 2 == 0) { // case 1
                        if (board[k][l] == 'B') count1++;
                        else count2++;
                    }
                    else { // case 2
                        if (board[k][l] == 'W') count1++;
                        else count2++;
                    }
                }
            }
            int min_count = count1 < count2 ? count1 : count2;
            if (min_count < min) min = min_count;
            min_count = 64 - min_count;
            if (min_count < min) min = min_count;
        }
    }
    printf("%d\n", min);
    for (int i = 0; i < n; i++) free(board[i]);
    free(board);
    return 0;
}