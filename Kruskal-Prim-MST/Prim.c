#include <stdio.h>
#include <stdlib.h>


typedef struct 
{
    int v1,v2,cost;
}Edge;

typedef struct 
{
    int Dinh,Canh;
    Edge *e;
}Graph;

Graph *createGraph(int n, int m)
{
    Graph *g = malloc(sizeof(Graph));
    g->Dinh = n;
    g->Canh=m;
    g->e=(Edge*)malloc(sizeof(Edge)*g->Canh);
    return g;
}

void freeGraph(Graph* g) {
    free(g->e);
    free(g);
}

void swap(Edge *a, Edge *b)
{
    Edge temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(Edge *arr, int n)
{
    int i, j, minIndex;
    for (i = 0; i < n - 1; i++)
    {
        minIndex = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j].cost > arr[minIndex].cost)
            {
                minIndex = j;
            }
        }
        swap(&arr[i], &arr[minIndex]);
    }
}

void Prim(Graph* g) {
    int i, j, sum=0;
    
    // Sort Edge with Value             
    selectionSort(g->e, (g->Canh) - 1);
	    
    int VF[g->Dinh]; 
    Edge P[g->Dinh - 1]; 
	for (i = 1; i <= g->Dinh; i++)
        VF[i] = 0;
    i = 1;

    P[i] = g->e[0]; 
    VF[P[i].v1] = 1;
    VF[P[i].v2] = 1;
    while (i < g->Dinh - 1)
    {
        j = 1; // Start from the next edge
        while (VF[g->e[j].v1] == VF[g->e[j].v2])
            j++;
        i++;
        P[i] = g->e[j];

        VF[g->e[j].v1] = 1;
        VF[g->e[j].v2] = 1;
    }

    for (i = 1; i < g->Dinh; i++)
    {
        printf("%d-%d %d\n", P[i].v1, P[i].v2, P[i].cost);
        sum=sum+P[i].cost;
    }
    printf("Total cost: %d",sum);
}


int main() 
{
    int SoDinh,SoCanh,i;
    FILE* f;
    Graph *g=NULL;
    

    if((f=fopen("input1.txt","rt"))==NULL)
    {
        printf("Cant open input file.\n");
        exit(1);
    }

    fscanf(f,"%d%d",&SoDinh,&SoCanh);
    g=createGraph(SoDinh,SoCanh);
    for(i=0;i<SoCanh-1;i++)
    {
        fscanf(f,"%d%d%d",&g->e[i].v1,&g->e[i].v2,&g->e[i].cost);
        g->e[i].v1=g->e[i].v1;
        g->e[i].v2=g->e[i].v2;
    }

    
    
    Prim(g);
	freeGraph(g);
    fclose(f);
    return 0;
}

