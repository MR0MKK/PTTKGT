#include <stdio.h>

int cot[9], duong_cheo_thuan[17], duong_cheo_nguoc[17], x[9];
int count = 0;
int only_one_solution = 1;

void Try(int i);
void Print_Queen_Position();
void Print_Board();
void Find_Solutions(int num_solutions);

void Try(int i) {
    int j;
    if (i > 8) {
        Print_Queen_Position();
        Print_Board();
        count++;
        return;
    }
    
    for (j = 1; j <= 8; j++) {
        if (cot[j] && duong_cheo_thuan[i + j] && duong_cheo_nguoc[i - j]) {
            x[i] = j;
            cot[j] = 0;
            duong_cheo_thuan[i + j] = 0;
            duong_cheo_nguoc[i - j] = 0;
            
            Try(i + 1);
            
            cot[j] = 1;
            duong_cheo_thuan[i + j] = 1;
            duong_cheo_nguoc[i - j] = 1;
            
            if (only_one_solution && count > 0) {
                return;
            }
        }
    }
}

void Print_Queen_Position() {
    int i;
    printf("Cach xep hau %d:\n", count + 1);
    for (i = 1; i <= 8; i++) {
        printf("(%d, %d)\n", i, x[i]);
    }
    printf("\n");
}

void Print_Board() {
    int i, j;
    printf("Ket qua:\n");
    for (i = 1; i <= 8; i++) {
        for (j = 1; j <= 8; j++) {
            if (x[i] == j) {
                printf("A ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void Find_Solutions(int num_solutions) {
    only_one_solution = (num_solutions == 1);
    Try(1);
    
    printf("Tong cong %d giai phap.\n", count);
}

int main() {
    int num_solutions;
    
    printf("Nhap so luong gia tri muon tim (nhap 1 de tim mot gia tri, nhap 0 de tim tat ca): ");
    scanf("%d", &num_solutions);
    
    int i;
    for (i = 1; i <= 8; i++) {
        cot[i] = 1;
    }
    for (i = 2; i <= 16; i++) {
        duong_cheo_thuan[i] = 1;
    }
    for (i = -7; i <= 7; i++) {
        duong_cheo_nguoc[i] = 1;
    }
    
    Find_Solutions(num_solutions);
    
    return 0;
}

