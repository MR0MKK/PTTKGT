#include <iostream>
#include <fstream>
using namespace std;

const int MAX_N = 100; 
int N; 
int W; 
int w[MAX_N]; 
int v[MAX_N]; 

int X[MAX_N]; // Mang chua lua chon toi uu
int optX[MAX_N] = {0}; // Mang chua lua chon toi uu cuoi cung
int optP = 0; // Giá tr? toi uu
int totalValue=0;
int totalWeight=0;

void knapsack(int l = 0) {
    if (l == N) {
        int sum = 0;
        for (int i = 0; i < l; i++) {
            if (X[i])
                sum += w[i];
        }
        if (sum <= W) {
            sum = 0;
            for (int i = 0; i < N; i++) {
                if (X[i])
                    sum += v[i];
            }
            if (sum > optP) {
                optP = sum;
                for (int i = 0; i < N; i++)
                    optX[i] = X[i];
            }
        }
    } else {
        X[l] = 1;
        knapsack(l + 1);
        X[l] = 0;
        knapsack(l + 1);
    }
    
}

void Input() {
    ifstream infile;
    infile.open("input.txt");
    infile >> N >> W;

    for (int i = 0; i < N; i++) {
        infile >> w[i] >> v[i];
    }

    infile.close();
}
void PrintResult()
{
    printf("\nSelected Items: {");
    for (int i = 0; i <= N; i++)
    {
        if (optX[i])
        {
            cout << "( Item: " << i+1 << " " << w[i] << " " << v[i] << ")";
        }
    }
    cout << "}\n";
    for (int i = 0; i < N; i++) {
        if (optX[i])
            totalValue += v[i];
    }
    cout << "\nTotal Profit: " << totalValue;
    for (int i = 0; i < N; i++) {
        if (optX[i])
            totalWeight += w[i];
    }
    cout << "\nTotal Weight: " << totalWeight << endl;
}
int main() {
    Input();

    knapsack();
	
    
	PrintResult();
    return 0;
}

