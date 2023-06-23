#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int longest_common_subsequence(char X[], char Y[], char LCS[]) {
    int m = strlen(X);
    int n = strlen(Y);

    // T?o ma tr?n B v?i c�c gi� tr? ban d?u l� 0
    int B[m + 1][n + 1];
    int i, j;

    // Thi?t l?p gi� tr? ban d?u cho ma tr?n B
    for (i = 0; i <= m; i++)
        B[i][0] = 0;
    for (j = 0; j <= n; j++)
        B[0][j] = 0;

    // X�y dung ma tran B
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1])
                B[i][j] = B[i - 1][j - 1] + 1;
            else
                B[i][j] = max(B[i - 1][j], B[i][j - 1]);
        }
    }

    // Tao chuoi chung lon nhat (LCS)
    int index = B[m][n]; // �o d�i cua LCS
    LCS[index] = '\0'; // K� tu ket th�c chuoi

    i = m;
    j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            LCS[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        }
        else if (B[i - 1][j] > B[i][j - 1])
            i--;
        else
            j--;
    }

    return B[m][n]; // Tra ve do d�i cua LCS
}

int main() {
    FILE *file;
    char X[100], Y[100], LCS[100];

    // M? file input.txt d? d?c
    file = fopen("input1.IN", "r");
    if (file == NULL) {
        printf("Kh�ng the mo file.\n");
        return 1;
    }

    // �?c hai chu?i t? file
    fscanf(file, "%s", X);
    fscanf(file, "%s", Y);

    // ��ng file
    fclose(file);

    // T�nh d? d�i c?a d�y con chung l?n nh?t (LCS) v� luu tr? LCS v�o chu?i LCS
    int length = longest_common_subsequence(X, Y, LCS);
    printf("Do dai cua day con chung lon nhat (LCS): %d\n", length);
    printf("Chuoi con chung lon nhat (LCS): %s\n", LCS);

    return 0;
}

