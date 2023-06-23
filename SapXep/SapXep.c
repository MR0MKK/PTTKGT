#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
void swap();
void insertionSort();
void selectionSort();
int partition();
void quickSort();
void mergeSort();
void merge();
void Sort_number();
void SetColor (int color)
{
	HANDLE hConsoleColor;
    hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor,color);
}


int main() {
	
	Sort_number(50);
	// IT'S 100
	Sort_number(100);
    
    // IT'S 1000
	Sort_number(1000);
    
    // IT'S 10000
	Sort_number(10000);
	
	// IT'S 100000
	Sort_number(100000);

   	return 0;
}


void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
// Sap Xep Chen
void insertionSort(int arr[], int n) 
{
    int i, key, j;
    for (i = 1; i < n; i++) 
	{
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) 
		{
           arr[j + 1] = arr[j];
           j = j - 1;
        }
       arr[j + 1] = key;
   }
}

// Sap Xep Chon 
void selectionSort(int arr[], int n) 
{
   	int i, j, min_pos;

    for(i = 0; i < n-1; i++) 
	{
        min_pos = i;
        for(j = i+1; j < n; j++){
                
            if(arr[j] < arr[min_pos])
			{
                min_pos = j;
            }
        }
        swap(&arr[min_pos], &arr[i]);
    }
}


// Sap Xep Nhanh
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int L[n1], R[n2];
    
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        
        merge(arr, left, mid, right);
    }
}
// Phuc vu cho vi du tu lon den be
void selectionSort1(int arr[], int n) {
    int i, j, min_idx;

    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] > arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
    }
}

void Sort_number(int num)
{
	SetColor(5);
	printf("\nNow the program is sorting %d value.",num);
	if(num>50000)
	{	
		SetColor(6);
		printf("\nPlease wait for 10 seconds so it can run.");
	}
		
	SetColor(7);
	FILE* fp1;
	char file_name[10];
	sprintf(file_name, "%d_numbers.txt", num);
	
	fp1 = fopen(file_name, "r");
	if(fp1 == NULL) 
	{
        printf("Cannot open file.\n");
        return;
    }	
    int array[num], back_up_array[num], n = 0;
    while(fscanf(fp1, "%d", &array[n]) == 1) 
	{
        n++;
    }
    
    
    /******************************************/
/*  Uncomment khi muon sap xep = worst case		*/   
/* 	selectionSort1(array,n);					*/
/* 												*/
/*  Uncomment khi muon sap xep gan dung			*/
//  insertionSort(array, n*0.95);				
    /******************************************/
   
    
    // Backup array
    memcpy(back_up_array, array, n * sizeof(int));
    // Start timing
    clock_t start_1 = clock();	
    insertionSort(back_up_array, n);
    clock_t end_1 = clock();
    double time_spent_1 = (double)(end_1 - start_1) / CLOCKS_PER_SEC;
    printf("\nTime of insertion sort taken: %f seconds.", time_spent_1);
    
    
    // Backup array
    memcpy(back_up_array, array, n * sizeof(int));
    // Start timing
    clock_t start_2 = clock();	
    selectionSort(back_up_array, n);
    clock_t end_2 = clock();
    double time_spent_2 = (double)(end_2 - start_2) / CLOCKS_PER_SEC;
    printf("\nTime of selection sort taken: %f seconds.", time_spent_2);
    
    
    // Backup array
    memcpy(back_up_array, array, n * sizeof(int));
    // Start timing
    clock_t start_3 = clock();	
    quickSort(back_up_array,0 , n-1);
    clock_t end_3 = clock();
    double time_spent_3 = (double)(end_3 - start_3) / CLOCKS_PER_SEC;
    printf("\nTime of quick sort taken: %f seconds.", time_spent_3);
    
    
    // Backup array
    memcpy(back_up_array, array, n * sizeof(int));
    // Start timing
    clock_t start_4 = clock();	
    mergeSort(back_up_array,0 , n-1);
    clock_t end_4 = clock();
    double time_spent_4 = (double)(end_4 - start_4) / CLOCKS_PER_SEC;
    printf("\nTime of merge sort taken: %f seconds.", time_spent_4);
    
    if(num <=500)
    {
    	printf("\n");
    	
    	for(int i =0;i<num;i++)
    	{
    	printf("%d ",back_up_array[i]);
		}
	}
    
}

