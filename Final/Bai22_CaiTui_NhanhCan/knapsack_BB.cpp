#include <iostream>
#include <fstream>
using namespace std;

#define MAX 100
struct item
{
    float w;     // weight
    float v;     // value
    float unit;  // unit price = v/w
    int num = 0; // 0 or 1
};

int W,                                        // khoi luong toi da cua tui
    N;                                        // so item
item Items[MAX + 1];                          // mang luu cac vat
int d[MAX + 1] = {0};                         // mang luu vet tam thoi cac vat duoc them hoac khong
float curr_val = 0,                           // current total value
    curr_weight = 0;                          // current total weight
float maxVal = 0, totalWeight = 0, total = 0; // gia tri toi uu
float g;                                      // can tren

void Input()
{
    ifstream infile;
    infile.open("input4.txt");
    infile >> N >> W;
//    cout << "n=" << N << " w=" << W << "\n";
    for (int i = 1; i <= N; i++)
    {
        infile >> Items[i].w >> Items[i].v;
        Items[i].unit = Items[i].v / Items[i].w;

//        cout << "#" << i << ": " << Items[i].w << " " << Items[i].v << "\n";
    }
    infile.close();
}

/* Sap ti theo ty so giam dan (unit price) */
void swap(item *a, item *b)
{
    item t = *a;
    *a = *b;
    *b = t;
}
void qSort(int left, int right)
{
    int i = left, j = right;
    item pivot = Items[(left + right) / 2]; // chon pivot o giua

    /* partition */
    while (i <= j)
    {
        while (Items[i].unit < pivot.unit)
            i++;
        while (Items[j].unit > pivot.unit)
            j--;

        if (i <= j)
        {
            swap(&Items[i], &Items[j]);
            i++;
            j--;
        }
    }

    /* recursion */
    if (left < j)
        qSort(left, j);
    if (i < right)
        qSort(i, right);
}

/* Kiem tra + cap nhat gia tri toi uu */
void test()
{
    if (curr_val > maxVal)
    {
        maxVal = curr_val;
        totalWeight = curr_weight;
        total = 0;
        for (int i = 1; i <= N; i++)
        {
            Items[i].num = d[i];
            total += d[i];
        }
    }
}

void Try(int k)
{
    for (int i = 0; i <= 1; i++)
    { // thu 2 truong hop, chon (1) hoac khong (0)
        if (curr_weight + i * Items[k].w <= W)
        {
            curr_weight += i * Items[k].w;
            curr_val += i * Items[k].v;
            d[k] = i;

            if ((k == N) && (curr_weight <= W))
            {
                test();
            }
            else
            {
               
                float remaining_cap = W - curr_weight; 
                g = curr_val + Items[k + 1].v * remaining_cap / Items[k + 1].w;
                
                
                if (g > maxVal)
                {
                    Try(k + 1);
                }
            }

            curr_weight -= i * Items[k].w;
            curr_val -= i * Items[k].v;
            d[k] = 0;
        }
    }
}

void PrintResult()
{
    printf("\nSelected Items: {");
    for (int i = 1; i <= N; i++)
    {
        if (Items[i].num)
        {
            cout << "( Item: " << i << " " << Items[i].w << " " << Items[i].v << "),";
        }
    }
    cout << "}\n";
    cout << "\nTotal Profit: " << maxVal;
    cout << "\nTotal Weight: " << totalWeight << endl;
}

int main()
{
    Input();
    qSort(0, N - 1);
    Try(1);
    PrintResult();
}
