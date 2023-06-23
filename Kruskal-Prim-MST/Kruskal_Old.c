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

int partition(Edge *arr, int low, int high)
{
    int j;
    Edge pivot = arr[high];
    int i = (low - 1);
    for (j = low; j <= high - 1; j++)
        if (arr[j].cost < pivot.cost)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(Edge *arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void Kruskal(Graph *g)
{
    int i, j, k=0, Selected = -1, sum = 0;
    int D[g->Dinh];

    for (i = 0; i < g->Dinh; i++)
        D[i] = 0;

    Edge a[g->Dinh];
    quickSort(g->e, 0, g->Canh - 1);

    i = 0;

    while (Selected < g->Dinh - 1 && i < g->Canh)
    {
        int v1 = g->e[i].v1;
        int v2 = g->e[i].v2;

        if (D[v1] == 0 && D[v2] == 0) 
        {
            Selected++;
            a[Selected] = g->e[i];
            k++;
            D[v1] = k;
            D[v2] = k;
        }
        else if (D[v1] == 0 && D[v2] != 0)
        {
            Selected++;
            a[Selected] = g->e[i];
            D[v1] = D[v2];
        }
        else if (D[v1] != 0 && D[v2] == 0) 
        {
            Selected++;
            a[Selected] = g->e[i];
            D[v2] = D[v1];
        }
        else if (D[v1] != D[v2])
        {
            Selected++;
            a[Selected] = g->e[i];
            int old = D[v2], new = D[v1];

            for (j = 0; j < g->Dinh; j++)
            {
                if (D[j] == old)
                    D[j] = new;
            }
        }

        i++;
    }

    for (i = 0; i < g->Dinh - 1; i++)
    {
        printf("%d-%d %d\n", a[i].v1 + 1, a[i].v2 + 1, a[i].cost);
        sum += a[i].cost;
    }

    printf("Total cost: %d", sum);
}

int main()
{   
    int SoDinh,SoCanh,i;
    FILE* f;
    Graph *g=NULL;
    

    if((f=fopen("input.txt","rt"))==NULL)
    {
        printf("Cant open input file.\n");
        exit(1);
    }

    fscanf(f,"%d%d",&SoDinh,&SoCanh);
    g=createGraph(SoDinh,SoCanh);

    for(i=0;i<SoCanh;i++)
    {
        fscanf(f,"%d%d%d",&g->e[i].v1,&g->e[i].v2,&g->e[i].cost);
        g->e[i].v1=g->e[i].v1-1;
        g->e[i].v2=g->e[i].v2-1;
    }
    Kruskal(g);
	freeGraph(g);
    fclose(f);
    return 0;
}
