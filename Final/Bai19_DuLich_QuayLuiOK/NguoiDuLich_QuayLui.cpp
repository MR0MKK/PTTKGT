#include <iostream>
#include <fstream>
using namespace std;

#define MAX 100
#define maxE 1000
#define INF 99999

int C[MAX + 1][MAX + 1]; //ma tran chi phi
int X[MAX + 2];         // X de thu cac kha nang
//1... max+1
int BestWay[MAX + 2]; //BestWay de ghi nhan nghiem
int T[MAX + 1];       //T[i] Luu chi phi di tu X[1] den X[i]
bool Free[MAX + 1]; //danh dau, true neu chua di qua thanh pho i
int minSpending;    // chi phi hanh trinh toi uu
int m, n;

void Input()
{
	int i, j;
	freopen("input3.txt", "r", stdin);
	cin>>n;
	cout<<"- So thanh pho la: "<< n;
	cout<<"\n- Ma tran ke la:";
	for(i=1; i<=n; i++)
	{
		cout<<"\n";
		for(j=1; j<=n; j++)
		{
			cin>>C[i][j];
			cout<<"\t"<<C[i][j];
		}
	}
	cout<<"\n";
}

void Init()
{
    for (int i = 1; i <= n; i++)
        Free[i] = true;//cac tp deu danh dau la chua di qua 
    Free[1] = false; //tru thanh pho 1
    X[1] = 1;        //xuat phat tu thanh pho 1
    T[1] = 0;        //chi phi tai thanh pho xuat phat la 0
    minSpending = INF;
}

void PrintResult()
{
    if (minSpending == INF)
        cout << "NO SOLUTION ";
    else
    {
        for (int i = 1; i <= n; i++)
            cout << BestWay[i] << "->";
        cout << "1" << endl;
        cout << "Cost : " << minSpending;
    }
}

void Try(int i) 
{
    for (int j = 2; j <= n; j++) //thu cac tp tu 2 den n
    {
        if (Free[j]) // neu gap thanh pho chua di qua
        {
            X[i] = j;                  //thu di       
            T[i] = T[i - 1] + C[X[i - 1]][j]; //chi phi=chi phi buoc truoc+ chi phi di truc tiep
            if (C[X[i - 1]][j] > 0)// co duong di truc tiep tu X[i-1] den j
            {
	            if (i < n) //neu chua den duoc X[n]
	            {
	                Free[j] = false; //danh dau thanh pho
	                Try(i + 1);      //tim cac kha nang chon
	                Free[j] = true;  //bo qua danh dau de quay len nhanh khac
	            }
	            else
	            {
	                if ((T[n] + C[X[n]][1]) < minSpending) //tu X[n] quay lai 1 van ton chi phi hon truoc
	                {// Cap nhat BestConfig
	                    for (int i = 0; i <= n; i++)
	                        BestWay[i] = X[i];
	                    minSpending = T[n] + C[X[n]][1];
	                }
	            }           	
            }
			
        }
    }
}

int main()
{
    Input();
    Init();
    Try(2);
    PrintResult();
}
