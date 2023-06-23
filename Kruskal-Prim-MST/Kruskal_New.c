#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    int v1,v2,cost;
}Edge;

typedef struct 
{
    int Canh,Dinh;
    Edge *e;
}Graph;

void swap(Edge *a,Edge *b);
int partition(Edge *arr, int low, int high);
void quickSort(Edge *arr, int low, int high);
Graph* createGraph(int n,int m);
void freeGraph(Graph *g);
void Kruskal(Graph *g);


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

void Kruskal(Graph *g)
{
    int i, j, min, max, Selected = -1, sum = 0;
    
    // Create + Insert graph
    int c[g->Dinh];
    for (i = 0; i < g->Dinh; i++)
        c[i] = i;

    // Create Kruskal result
    Edge a[g->Dinh - 1];
    
    // Sort Edge with Value
    selectionSort(g->e, (g->Canh) - 1);

    // Khi chua co chu trinh hoac chua xet het cac canh
    for (i = 0; Selected < g->Dinh - 1 && i < g->Canh; i++)
    {
        if (c[g->e[i].v1] == c[g->e[i].v2])
            continue;

        a[++Selected] = g->e[i];

        if (c[g->e[i].v1] < c[g->e[i].v2])
        {
            min = c[g->e[i].v1];
            max = c[g->e[i].v2];
        }
        else
        {
            max = c[g->e[i].v1];
            min = c[g->e[i].v2];
        }

        for (j = 0; j < g->Dinh; j++)
        {
            if (c[j] == max)
                c[j] = min;
        }
    }

    for (i = 0; i < g->Dinh - 1; i++)
    {
        printf("%d-%d %d\n", a[i].v1, a[i].v2, a[i].cost);
        sum = sum + a[i].cost;
    }

    printf("Total cost: %d", sum);
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

    for(i=0;i<SoCanh;i++)
    {
        fscanf(f,"%d%d%d",&g->e[i].v1,&g->e[i].v2,&g->e[i].cost);
        g->e[i].v1=g->e[i].v1;
        g->e[i].v2=g->e[i].v2;
    }
    Kruskal(g);
	freeGraph(g);
    fclose(f);
    return 0;
}
