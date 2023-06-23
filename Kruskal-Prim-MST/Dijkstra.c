#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define max 500
#define INFINITY 500

typedef struct 
{
    int v1, v2, cost;
} Edge;

typedef struct 
{
    int Canh, Dinh;
    Edge *e;
} Graph;

Graph* createGraph(int n, int m);
void freeGraph(Graph *g);
void dijkstra();
void xuatdd(int s, int k, int Ddnn[]);

Graph *createGraph(int n, int m)
{
    Graph *g = malloc(sizeof(Graph));
    g->Dinh = n;
    g->Canh = m;
    g->e = (Edge*)malloc(sizeof(Edge) * g->Canh);
    return g;
}

void freeGraph(Graph* g) {
    free(g->e);
    free(g);
}

void dijkstra(Graph *g, int s)
{
    int Ddnn[max]; 
    int Daxet[max]; 
    int L[max];
    int i, dht, h, Min, k;
    int a[max][max];

  
    for (i = 1; i <= g->Dinh; i++)
    {
        for (int j = 1; j <= g->Dinh; j++)
        {
            a[i][j] = INFINITY;
        }
    }

    // Populate the adjacency matrix with edge costs
    for (i = 0; i < g->Canh; i++)
    {
        a[g->e[i].v1][g->e[i].v2] = g->e[i].cost;
        a[g->e[i].v2][g->e[i].v1] = g->e[i].cost;
    }

    for (i = 1; i <= g->Dinh; i++)
    {
        Daxet[i] = 0;
        L[i] = INFINITY;
    }
    Daxet[s] = 1;
    L[s] = 0;
    dht = s;
    h = 1;
    while (h <= g->Dinh - 1)
    {
        Min = INFINITY;
        for (i = 1; i <= g->Dinh; i++) 
        {
            if (!Daxet[i])
            {
                if (L[dht] + a[dht][i] < L[i]) 
                {
                    L[i] = L[dht] + a[dht][i];
                    Ddnn[i] = dht;
                }
                if (L[i] < Min) 
                {
                    Min = L[i];
                    k = i;
                }
            }
        }
        
        xuatdd(s, k, Ddnn);
        printf("\nTrong so: %d", L[k]);
        dht = k; // Reinitialize dht
        Daxet[dht] = 1;
        h++;
    }
}

void xuatdd(int s, int k, int Ddnn[])
{
    int i;
    printf("\nDuong di ngan nhat tu %d den %d la: ", s, k);
    i = k;
    while (i != s)
    {
        printf("%d <- ", i);
        i = Ddnn[i];
    }
    printf("%d", s);
}

int main()
{   
    int SoDinh, SoCanh, i;
    FILE* f;
    Graph *g = NULL;

    if ((f = fopen("input2.txt", "rt")) == NULL)
    {
        printf("Can't open input file.\n");
        exit(1);
    }

    fscanf(f, "%d%d", &SoDinh, &SoCanh);
    g = createGraph(SoDinh, SoCanh);

    for (i = 0; i < SoCanh; i++)
    {
        fscanf(f, "%d%d%d", &g->e[i].v1, &g->e[i].v2, &g->e[i].cost);
    }
    
    int s;
    printf("Nhap diem xuat phat: ");
    scanf("%d",&s);
    
    dijkstra(g, s);
    
    freeGraph(g);
    fclose(f);
    
    return 0;
}
