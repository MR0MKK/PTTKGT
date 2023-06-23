#include<iostream>
#include<fstream>
#include<climits>
using namespace std;

#define max 100
int a[max];
int n;

void Nhap(char input[])
{
    fstream in;
    in.open(input);
    in >> n;
    for (int i = 0; i < n; i++)
    {
        in >> a[i];
    }
}

int Max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int MaxLeftVector(int i, int j, int& dau)
{
    int MaxSum = INT_MIN;
    int Sum = 0;
    for (int k = j; k >= i; k--)
    {
        Sum += a[k];
        if (MaxSum < Sum) {
            MaxSum = Sum;
            dau = k;
        }
    }
    return MaxSum;
}

int MaxRightVector(int i, int j, int& cuoi)
{
    int MaxSum = -INT_MAX;
    int Sum = 0;
    for (int k = i; k <= j; k++)
    {
        Sum += a[k];
        if (MaxSum < Sum) {
            MaxSum = Sum;
            cuoi = k;
        }
    }
    return MaxSum;
}

int MaxSubVector(int i, int j, int& dau, int& cuoi)
{
    int dau1, dau2, dau3, cuoi3, cuoi1, cuoi2;
    if (i == j) {
        dau = i;
        cuoi = i;
        return a[i];
    }
    else
    {
        int m = (i + j) / 2;
        int wl, wr, wm;
        wl = MaxSubVector(i, m, dau1, cuoi1);
        wr = MaxSubVector(m + 1, j, dau2, cuoi2);
        wm = MaxLeftVector(i, m, dau3) + MaxRightVector(m + 1, j, cuoi3);
        int maxTam = Max(Max(wl, wr), wm);
        if (maxTam == wl) {
            dau = dau1;
            cuoi = cuoi1;
        }
        else if (maxTam == wr) {
            dau = dau2;
            cuoi = cuoi2;
        }
        else if (maxTam == wm) {
            dau = dau3;
            cuoi = cuoi3;
        }
        return maxTam;
    }
}

int main()
{
    int dau, cuoi;
    Nhap("input.txt");
    int maxSum = MaxSubVector(0, n - 1, dau, cuoi);

    cout << "Day con lon nhat:";
    for (int i = dau; i <= cuoi; i++)
    {
        cout << " " << a[i];
    }

    int sum = 0;
    for (int i = dau; i <= cuoi; i++)
    {
        sum += a[i];
    }
    cout << "\nTong cua day con lon nhat: " << sum;

    return 0;
}

