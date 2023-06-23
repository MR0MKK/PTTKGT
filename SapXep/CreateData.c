#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void CreateData(int num)
{
	FILE* fp1;
	char file_name[10];
	sprintf(file_name, "%d_numbers.txt", num);
	fp1 = fopen(file_name, "w");
	int arr[num];
	
	srand(time(NULL));

    for(int i = 0; i < num; i++) {
        arr[i] = rand() % num*1.5;
        fprintf(fp1, "%d ", arr[i]); 
    }
    fclose(fp1);
}

int main() {

	int num;
	do
	{
		printf("Ban muon tao ra danh sach bao nhieu so:");
		scanf("%d",&num);	
	}while(num<=0);
	
	printf("Danh sach da duoc tao");
	CreateData(num);
    return 0;
}

