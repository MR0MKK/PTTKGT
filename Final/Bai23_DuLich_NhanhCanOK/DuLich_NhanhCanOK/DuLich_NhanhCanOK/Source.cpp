#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
using namespace std;
int c[10][10], x[10], xmin[10], chuaxet[10], k, n, s = 0, cmin, fmin = 10000;
//cmin là chi phi nho nhat giua 2 thanh pho
//s: chi phi
//xmin[] là chuoi xuat ra
void Nhap()
{
	FILE* f;
	f = fopen("NguoiDuLich1.txt", "r");
	fscanf(f, "%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			fscanf(f, "%d", &c[i][j]);
	fclose(f);
}
void KhoiTao()
{
	cmin = c[1][2];
	for (int i = 1; i <= n; i++)
	{
		chuaxet[i] = 1;
		for (int j = 1; j <= n; j++)
		{
			if (i != j && c[i][j] != 0 && cmin > c[i][j])
				cmin = c[i][j];

		}
	}
	x[1] = 1;
	chuaxet[1] = 0;
}

void Try(int k)
{
	int g, tong, i, j;
	for (j = 2; j <= n; j++)
	{
		if (chuaxet[j] == 1)
		{
			x[k] = j;
			chuaxet[j] = 0;
			s = s + c[x[k - 1]][x[k]];
			//printf("%d\n", j);
			if (k < n)
			{
				g = s + cmin * (n - k + 1);
				if (g < fmin)
				{
					Try(k + 1);
				}

			}
			if (k == n)
			{
				tong = s + c[x[n]][x[1]];
				if (tong < fmin)
				{
					fmin = tong;
					for (i = 1; i <= n; i++)
						xmin[i] = x[i];//xmin[] là chuoi ket qua in ra
				}
			}
			s = s - c[x[k - 1]][x[k]];
			chuaxet[j] = 1;

		}
	}
}
void Xuat()
{
	printf("Chi phi nho nhat la: %d", fmin);
	printf("\nHanh trinh nho nhat la: ");
	for (int i = 1; i <= n; i++)
	{
		printf("%d", xmin[i]);
		printf("->");
	}
	printf("1");
}
int main()
{
	Nhap();
	KhoiTao();
	Try(2);
	Xuat();
	getchar();
	return 0;
}
