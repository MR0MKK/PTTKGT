//bai toan tim duong di ngan nhat tren do thi (giai thuat Dijkstra)
#include <iostream>
using namespace std;
#define MAX 100
int n; // so dinh do thi
int a[MAX][MAX]; //ma tran trong so do thi
int Daxet[MAX]; //danh dau cac dinh da xet
int TrongSo[MAX]; //mang ghi nhan cac dinh
int Truoc[MAX]; //chua dinh ngay truoc
int s, t;
// Do phuc tap la (E+v)logV
void Input(){
	freopen("input5.IN", "r", stdin);
	cin>>n;
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=n; j++){
			cin>>a[i][j];
			if (a[i][j] == 0) a[i][j] = MAX;
		}
	}
}

void Init()
{
    for(int i=1;i<=n;i++)
    {
        TrongSo[i]= MAX;
        Daxet[i]=0;
        Truoc[i]=0;
    }
}

void Print(int s, int k, int Truoc[MAX]){
	int i;
	cout<<"\nDuong di ngan nhat tu "<<s<<" den "<<k<<" la :";
	cout<< k << " <- ";
	i = Truoc[k];
	while (i!=s){
		cout<<i<<" <- ";
		i = Truoc[i];
	}
	cout<<s;
	cout<<"\nTrong so: "<<TrongSo[k];
	cout<<endl;
}

void Dijkstra(){
	int u, v, minp;
	int h = 1;
    for(int i=1;i<=n;i++)
    {
        TrongSo[i]=a[s][i];
        Truoc[i]=s;
        Daxet[i]=0;
    }
    Truoc[s]=0;
    TrongSo[s] = 0;
    Daxet[s]=1;
    while(h<n) 
    {
        minp=MAX;
        for(int i=1;i<=n;i++)
        {
            if(Daxet[i]==0 && minp > TrongSo[i])
            {
                minp=TrongSo[i];
                u=i;
            }
        }
        Daxet[u]=1;
        for(int i=1;i<=n;i++)
        {
            if(Daxet[i]==0 && TrongSo[u]+a[u][i] < TrongSo[i])
            {
                TrongSo[i]=TrongSo[u]+a[u][i];
                Truoc[i]=u;
            }
        }
        Print(s,u,Truoc);
        h++;
    }
}

int main(){
	cout<<"Nhap dinh dau: ";
	cin>>s;
	Input();
	Init();	
	Dijkstra();
}
