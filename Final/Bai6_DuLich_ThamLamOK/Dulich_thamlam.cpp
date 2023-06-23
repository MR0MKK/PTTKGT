//Bai toan nguoi du lich (phuong phap tham lam)
#include <iostream>
#include <time.h>
using namespace std;
#define max 100
	int n;
	int a[max][max]; //ma tran trong so cua do thi
	int TOUR[max];// mang ghi chu trinh
	int Ddau; //diem dau cua chu trinh
	int v; //Dinh dang xet;
	int k; //duyet qua k dinh de chon
	int w; //dinh duoc chon trong moi buoc
	int mini; //chon min cac canh trong moi buoc
	int COST; //trong so nho nhat cua chu trinh
	int daxet [max]; //danh dau cac dinh da xet
	int dem = 0;

void Input (){
	freopen("input1.IN", "r", stdin);
	cin>>n;
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=n; j++){
			cin>>a[i][j];
			if(a[i][j]==0) a[i][j] = max;
		}
	}
}

void Print(int i){
	cout<<"\nTOUR: ";
	for (int j = 1; j<=i; j++) 
	{
		if(TOUR[1]==TOUR[j]&&j!=1)
			cout<<TOUR[j];
		else
			cout<<TOUR[j]<<" -> ";
	}
	
	cout<<"\nCOST = "<<COST<<endl;
}

int GTS (){
	//khoi tao
	for (k=1; k<=n; k++){
		daxet[k] = 0; //chua dinh nao duoc xet
	}
	COST = 0;
	int i;
	v = Ddau; //chon dinh dau
	i = 1;
	TOUR[i] = v; //dua v vao chu trinh
	daxet[v] = 1;
	//tim dinh gan nhat voi dinh dang xet
	while (i<n){
		mini = max;
		for (k=1; k<=n; k++){
			if (!daxet[k]){
				if (mini > a[v][k]){
					mini = a[v][k]; //v dinh dang xet, k la dinh ke dinh dang xet
					w = k;
					//dem ++;
				}
			}
		}
		v = w; //danh dau dinh dang xet v la dinh duoc chon w
		i++;
		TOUR[i] = v; //luu vao hanh trinh
		daxet[v] = 1; //danh dau dinh v da di qua
		COST += mini; //cap nhat lai chi phi
		Print(i);
	}
	//tro ve dinh dau
	i++;
	TOUR[i] = Ddau;
	COST += a[v][Ddau];
	Print(i);
	return COST;
}

int main(){
	cout<<"Nhap diem dau: ";
	cin>>Ddau;
	Input();
	GTS();
	cout << endl;
	//cout << "So hoat dong co ban la: " << dem; 
}
