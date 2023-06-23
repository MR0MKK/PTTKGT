#include <stdio.h>
#include<conio.h>
int x[8], a[8], b[15], c[15], dem=0;

void print()
{
	int i;
	printf("\n-------------------------------\n");
	printf("Buoc\thang\tcot");
	for (i=0; i<8; i++)
	printf("\n%d\t%d\t%d",i+1,i+1, x[i]+1);
}

void thu(int i)
{
	int j;
	if (i<=7)
	{
		for (j=0; j<8; j++)
		{
			if (a[j] == 1 && b[i+j] ==1 && c[i-j+7] == 1)//chua co quan hau nao o cot j
			{
				x[i] = j; 
				a[j] = 0; b[i+j] = 0; c[i-j+7] = 0;
				thu(i+1);
				a[j] = 1; b[i+j] = 1; c[i-j+7] = 1;
            }
        }
    }
	else
	{ 
		print();dem++;
	}
}

void TamHau()
{
	int i;
	for (i=0; i<8; i++)
	{
		a[i] = 1;
		x[i] = -1;
	}
	for (i=0; i<15; i++)
	{
		b[i] = 1;
		c[i] = 1;
	}
	thu(0);
	printf("\n Tong so cach dat quan Hau: %d",dem);
}

int main()
{ 
TamHau();
getch();
return 0;
}
