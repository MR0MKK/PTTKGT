#include <iostream>
using namespace std;
#define max 1000
int a[max][max];//ma tran trong so do thi
int d[max][max];//mang ghi do dai duong di giua cac dinh
int p[max][max];//mang ghi cac dinh giua 
int s[max];//mang ghi duong di
int n, u, v;
void Input(){
	cout<<"Nhap dinh dau: ";
	cin>>u;
	cout<<"\nNhap dinh cuoi: ";
	cin>>v;
	freopen("input6.IN", "r", stdin);
	cin>>n;
	cout<<"\nSo dinh cua do thi: "<< n <<endl;
	
	 for (int i = 1; i <= n; i++){
		  for (int j = 1; j <= n; j++){
			   cin>>a[i][j];
			   if (i != j && a[i][j] == 0)
			   a[i][j] = max;
		  }
	 }
}
void Print(int u, int v){
		//Truy vet
	if (d[u][v] >= max) {
	  		cout<<"\nKhong co duong di"<<endl;
	}
	else {
		cout<<"\nDuong di ngan nhat tu "<<u<<" den "<<v<< " co do dai la "<<d[u][v]<<endl;
		int t = 1; int i=u; int j=v; int k;
		s[t]=v;
		while (p[i][j]!=0) {
			k = p[i][j];
			t++;
			s[t] = k; 
			j = k;
		}
		cout<<"\nDuong di: "<<u;
		int count = t;
		while(count>0) {
			cout<<" -> "<<s[count];
			count--;
		}
	}
}
void Floyd(){
	int i, j, k;
	//Khoi dong ma tran d va p
	for (i=1; i<=n; i++){
		for (j=1; j<=n;j++){
			d[i][j] = a[i][j];
			p[i][j]=0;
		}
	}
	cout << "\nKhoi Tao";
	cout<<"\nMa tran d:"<<endl;
		for (int b = 1; b<=n; b++){
		for (int c = 1; c<= n; c++){
			cout<< d[b][c] <<"	";
			}
			cout<<endl;
		}
		cout<<endl;
		cout<<"Ma tran p:"<<endl;
		for (int b = 1; b<=n; b++){
			for (int c = 1; c<= n; c++){
			cout<< p[b][c]<<"	";
			}
		cout<<endl;
		}
	//Tinh ma tran d va p 
	for (k=1; k<=n;k++)
	{
		for (i=1; i<=n; i++){
			if (d[i][k]>0 & d[i][k]<max){
				for(j=1;j<=n;j++){
					if(d[k][j]>0 && d[k][j]<max){
						if (d[i][k] + d[k][j] < d[i][j]){
							d[i][j] = d[i][k] + d[k][j];
							p[i][j] = k;
						}
					}
				}
			}
		}
		cout<<"\nk = "<<k<<endl;
		cout<<"\nMa tran d:"<<endl;
		for (int b = 1; b<=n; b++){
		for (int c = 1; c<= n; c++){
			cout<< d[b][c] <<"	";
			}
			cout<<endl;
		}
		cout<<endl;
		cout<<"Ma tran p:"<<endl;
		for (int b = 1; b<=n; b++){
			for (int c = 1; c<= n; c++){
			cout<< p[b][c]<<"	";
			}
		cout<<endl;
		}
		cout<<endl;
	}
}
int main(){
	 Input();
	 Floyd();
	 Print(u, v);
}
