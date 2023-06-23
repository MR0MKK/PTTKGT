#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <windows.h>
/* Global variable*/
int size;
int capacity;
int *weight,*profit,*selected;

/*Funtion declaration*/
int readFile(char*);
int printResult(int);
int bruteforce(); /*Bruce Force*/
int greedy1();  /*Max Benefit first*/
int greedy2();  /*Min weight first*/
int greedy3(); /*maxprofit/unit first*/
int DynamicProgram();
/* Main function*/
int main(int argc, char ** argv){
	char *input;
	int i,totalProfit=0,totalWeight=0;
	if(argc!=2) {
		printf("\nError: Invalid number of arguments!\n\n");
		return 0;
	}
	input = argv[1];
	readFile(input);
//	printf("%d\n",size);
//	printf("%d\n",capacity);
//	for(i=0;i<size;i++) {
//		printf("%d %d\n",weight[i],profit[i]);
//			
//	}
	printf("\nBruce Force:");
	totalProfit = bruteforce();
	printResult(totalProfit);

	printf("\nGreedy1(Max Benefit First):");
	totalProfit = greedy1();
	printResult(totalProfit);

	printf("\nGreedy2(Min Weight First):");
	totalProfit = greedy2();
	printResult(totalProfit);

	printf("\nGreedy3(Max weight First):");
	totalProfit = greedy3();	
	printResult(totalProfit);

//	 Dynamic programming approach
    printf("\nDynamic Programming Approach:");
    totalProfit=DynamicProgram();
    printResult(totalProfit);
	/*Free the allocated memory*/
	free(selected);
	free(weight);
	free(profit);
	return 0;
}

/* Reads knapsack.txt input file */

int readFile(char * filename) {
	FILE *fp;
	char num[255];
	int i=0,j=0;

	fp = fopen(filename,"r");
	if(fp == NULL) {
		printf("\nERROR in opening the file!\n\n");
		return 0;
	}
	char ch;
	ch=fgetc(fp);
	while(ch!='\n' && ch!=EOF) {
		//Read size;
		while(ch!='\n'){
			num[j++]=ch;
			ch=fgetc(fp);
		}
		num[j]='\n';
		size = atoi(num);
		//Read capacity
		ch=fgetc(fp);
		j=0;
		while(ch!='\n' && ch!=EOF){
			num[j++]=ch;
			ch=fgetc(fp);
		}
		num[j]='\n';
		capacity = atoi(num);
		// create weight and profit array
		weight = (int*) malloc(sizeof(int)*size);
		profit = (int*) malloc(sizeof(int)*size);
		selected = (int*) malloc(sizeof(int)*size);
		
		ch=fgetc(fp);
		//Read the weights.
		for(i=0;i<size;i++){
			j=0;
			while(ch!=',' && ch!='\n'){
				num[j++]=ch;
				ch=fgetc(fp);
			}
			num[j]='\n';
			weight[i]=atoi(num);
			if(ch=='\n')
				break;
			ch=fgetc(fp);
		}
		
		ch=fgetc(fp);
		//Read the profit.
		for(i=0;i<size;i++){
			j=0;
			while(ch!=',' && ch!='\n'){
				num[j++]=ch;
				ch=fgetc(fp);
			}
			num[j]='\n';
			profit[i]=atoi(num);
			if(ch=='\n')
				break;
			ch=fgetc(fp);
		}
				
	}	
	fclose(fp);
	return 0;
}

/* Brute Force Knapsack problem */
int bruteforce() {
	clock_t start_1 = clock();
	int i,j,isSelected=1,maxWt,maxProfit;
	int iter=pow(2.0,size);
	int result=0;
	int temp[size];
	/*Initialize temp array */
	for(i =0;i<size;i++)
		temp[i]=0;
	
	for(i=0;i<iter;i++) {
		isSelected=1;
		maxProfit=0;
		maxWt=0;
		
		for(j=0;j<size;j++){
			if(temp[j]==1){
				maxWt+=weight[j];
				maxProfit+= profit[j];
			}
		}
		if( maxWt <= capacity && maxProfit>result){
			/*Copies the selected item in array. */
			for(j=0;j<size;j++)
				selected[j]=temp[j];
			result=maxProfit;
		}
		
		/*Calculate the next subset */
		for(j=0;j<size;j++){
			temp[j]=temp[j]+isSelected;
			isSelected = temp[j]/2;
			temp[j]=temp[j]%2;	
		} 
	}
	clock_t end_1 = clock();
	double time_spent_1 = (double)(end_1 - start_1) / CLOCKS_PER_SEC;
    //printf("\nRun time: %f seconds.", time_spent_1);
	return result;
}

/* Greedy - Max Profit first */
int greedy1() {
	clock_t start_1 = clock();
	int i,j,temp;
	int result=0,greedyCap=capacity;
	int tempArr[size],tempWt[size],tempProfit[size];
	for(i=0;i<size;i++) {
		tempArr[i]=i;
		tempWt[i]=weight[i];
		tempProfit[i]=profit[i];
		selected[i]=0;
	}

	for(i=0;i<size;i++) {
		for(j=0;j<size - i-1;j++) {
			if(tempProfit[j] < tempProfit[j+1]){
				//swap profit
				temp=tempProfit[j];
				tempProfit[j]=tempProfit[j+1];
				tempProfit[j+1]=temp;
				//swap weights
				temp=tempWt[j];
				tempWt[j]=tempWt[j+1];
				tempWt[j+1]=temp;
				//swap item number as well
				temp=tempArr[j];
				tempArr[j]=tempArr[j+1];
				tempArr[j+1]=temp;
			}
		}
	}
	//sorted
	for(i=0;i<size;i++) {
		if(tempWt[i] <= greedyCap && greedyCap > 0) {
			result+=tempProfit[i];
			greedyCap -=tempWt[i];
			selected[tempArr[i]]=1;
		}	
	}	
	clock_t end_1 = clock();
	double time_spent_1 = (double)(end_1 - start_1) / CLOCKS_PER_SEC;
    //printf("\nRun time: %f seconds.", time_spent_1);
	return result;
	
}

/* Greedy - Min weight first */  
int greedy2() {
	clock_t start_1 = clock();
	int i,j,temp;
	int result=0,greedyCap=capacity;
	int tempArr[size],tempWt[size],tempProfit[size];
	for(i=0;i<size;i++) {
		tempArr[i]=i;
		tempWt[i]=weight[i];
		tempProfit[i]=profit[i];
		selected[i]=0;
	}

	for(i=0;i<size;i++) {
		for(j=0;j<size - i-1;j++) {
			if(tempWt[j] > tempWt[j+1]){
				//swap profit
				temp=tempProfit[j];
				tempProfit[j]=tempProfit[j+1];
				tempProfit[j+1]=temp;
				//swap weights
				temp=tempWt[j];
				tempWt[j]=tempWt[j+1];
				tempWt[j+1]=temp;
				//swap item number as well
				temp=tempArr[j];
				tempArr[j]=tempArr[j+1];
				tempArr[j+1]=temp;
			}
		}
	}
	
	for(i=0;i<size;i++) {
		if(tempWt[i] <= greedyCap && greedyCap > 0) {
			result+=tempProfit[i];
			greedyCap -=tempWt[i];
			selected[tempArr[i]]=1;
		}	
	}	
	clock_t end_1 = clock();
	double time_spent_1 = (double)(end_1 - start_1) / CLOCKS_PER_SEC;
    //printf("\nRun time: %f seconds.", time_spent_1);
	return result;
}  

/* Greedy - Maxprofit/Unit first */
int greedy3() {
	clock_t start_1 = clock();
	int i,j,temp;
	int result=0,greedyCap=capacity;
	int tempArr[size],tempWt[size],tempProfit[size];
	float val1,val2;
	
	for(i=0;i<size;i++) {
		tempArr[i]=i;
		tempWt[i]=weight[i];
		tempProfit[i]=profit[i];
		selected[i]=0;
	}

	for(i=0;i<size;i++) {
		for(j=0;j<size - i-1;j++) {
			val1 = ((float)tempProfit[j]/ (float)tempWt[j]);
			val2 = ((float)tempProfit[j+1]/(float) tempWt[j+1]);
			if( val1 < val2 ){
				//swap profit
				temp=tempProfit[j];
				tempProfit[j]=tempProfit[j+1];
				tempProfit[j+1]=temp;
				//swap weights
				temp=tempWt[j];
				tempWt[j]=tempWt[j+1];
				tempWt[j+1]=temp;
				//swap item number as well
				temp=tempArr[j];
				tempArr[j]=tempArr[j+1];
				tempArr[j+1]=temp;
			}
		}
	}
	
	for(i=0;i<size;i++) {
		if(tempWt[i] <= greedyCap && greedyCap > 0) {
			result+=tempProfit[i];
			greedyCap -=tempWt[i];
			selected[tempArr[i]]=1;
		}	
	}	
	clock_t end_1 = clock();
	double time_spent_1 = (double)(end_1 - start_1) / CLOCKS_PER_SEC;
    //printf("\nRun time: %f seconds.", time_spent_1);
	return result;

}

int DynamicProgram()
{
    clock_t start_1 = clock();
    int B[size + 1][capacity + 1];
    int i, j;

    // Initialize B[][] with 0
    for (i = 0; i <= size; i++)
    {
        for (j = 0; j <= capacity; j++)
        {
            B[i][j] = 0;
        }
    }

    for (i = 1; i <= size; i++)
    {
        for (j = 1; j <= capacity; j++)
        {
            if (weight[i - 1] > j)
            {
                B[i][j] = B[i - 1][j];
            }
            else
            {
                B[i][j] = max(B[i - 1][j], B[i - 1][j - weight[i - 1]] + profit[i - 1]);
            }
        }
    }

    int totalProfit = B[size][capacity];
    i = size;
    j = capacity;

    // Backtrack to find the selected items
    while (i > 0 && j > 0)
    {
        if (B[i][j] != B[i - 1][j])
        {
            selected[i - 1] = 1;
            j -= weight[i - 1];
        }
        else
        {
            selected[i - 1] = 0;
        }
        i--;
    }
    clock_t end_1 = clock();
    double time_spent_1 = (double)(end_1 - start_1) / CLOCKS_PER_SEC;
    //printf("\nRun time: %f seconds.", time_spent_1);
    return totalProfit;
}

int printResult(int totalProfit) {
	int i,totalWeight=0;
	
	printf("\nSelected Items: {");
	for(i=0;i<size;i++) {
		if(selected[i]==1) {
			totalWeight+=weight[i];
			if(i<size-1)
				printf(" (Item: %d, %d, %d),",i+1,weight[i],profit[i]);
			else 
				printf(" (Item: %d, %d, %d)",i+1,weight[i],profit[i]);
		}
	}
	printf(" }\n");
	printf("Total Profit = %d\n",totalProfit);
	printf("Total Weight = %d\n\n",totalWeight);

	return 0;		
}
