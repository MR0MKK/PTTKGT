#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_N 20
#define MAX_W 50

/* Globale variable */
int n, w[MAX_N], v[MAX_N], W;

int main(int argc, char ** argv) {
    char *filename;
	int i,totalProfit=0,totalWeight=0;
	
	if(argc!=2) {
		printf("\nError: Invalid number of arguments!\n\n");
		return 0;
	}
	filename = argv[1];
	FILE *fp = fopen(filename,"w");
	
	
	
	//Enter number item 
    srand(time(NULL));
    printf("Number of item: ");
    scanf("%d",&n);
    fprintf(fp, "%d\n", n);
    
    //Enter max weight
    printf("Maximun of bag can carry: ");
    scanf("%d",&W);
    fprintf(fp,"%d\n",W);
    
    //Write weight in file 
    for (int i = 0; i < n; i++) {
        do {
            w[i] = rand() % MAX_W + 1;
            v[i] = rand() % MAX_W + 1;
        } while ((v[i] >= w[i]*3) || (v[i] <= w[i]*3/2));
        if(i<n-1)
        	fprintf(fp, "%d, ", w[i]);
        else
        	fprintf(fp, "%d", w[i]);
    }
    fprintf(fp, "\n");
    
    
    //Write profit in file 
    for (int i = 0; i < n; i++) {
        if(i<n-1)
        	fprintf(fp, "%d, ", v[i]);
        else
        	fprintf(fp, "%d", v[i]);
    }
    fprintf(fp, "\n");
    
    printf("%d %d\n",n,W);
    for (i=0;i <n;i++)
    {
    	printf("%d %d\n",w[i],v[i]);
	}
    
    



	fclose(fp);
    return 0;
}

