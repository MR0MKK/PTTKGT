#include "iostream"
#include "stdio.h"
using namespace std;
int DX[100], Tong=0;
void SXKhongTangGiaTri(int a[100][2], int n)
{
	int i, j, t;
	for(i=0; i<n; i++)
	{
		for(j=i; j<n; j++)
		{
			if(a[i][0]<a[j][0])
			{
				t = a[j][0];
				a[j][0] = a[i][0];
				a[i][0] = t;
				
				t = a[j][1];
				a[j][1] = a[i][1];
				a[i][1] = t;
			}
		}
	}
	cout<<"\nGia tri cac do vat sau khi sap xep lai:\n";
	for(i=0; i<n; i++)
	{
		cout<<a[i][0]<<" ";
	}
}

void in(int a[100][2], int Daxet[100], int n)
{
	int i, t=0;
	cout<<"\nCac do vat duoc chon: ";
	for(i=0; i<n; i++)
	{
		if(Daxet[i]==1)
		{
			cout<<i+1<<" ";
			t+= a[i][0];
		}
	}
	cout<<"\nGia tri nhan duoc la: "<<t;
}

void kt(int a[100][2], int Daxet[100], int n)
{
	int i, t;
	t=0;
	for(i=0; i<n; i++)
	{
		if(Daxet[i]==1)
		{
			t+= a[i][0];
		}
	}
	if(t>Tong)
	{
		Tong = t;
		for(i=0; i<n; i++)
		{
			DX[i] = Daxet[i];
			//cout<<Daxet[i]<<" ";
		}
		cout<<endl;
	}
}

void quaylui(int a[100][2], int n, int b, int Daxet[100], int t, int j)
{
	if(t>b)
	{
		Daxet[j] = 0;
		kt(a, Daxet, n);
		return ;
	}
	for(int i=0; i<n; i++)
	{
		if(Daxet[i]==0)
		{		
				Daxet[i] = 1;
				t += a[i][1];
				quaylui(a, n, b, Daxet, t, i);
				Daxet[i] = 0;
				t-=a[i][1];
		}
	}
}

int main()
{
	int i, n, b, a[100][2], Daxet[100], t;
	cout<<"Nhap vao so luong do vat: ";
//	cin>>n;
	n=5;
	cout<<"Nhap vao trong luong tui: ";
	//cin>>b;
	b=45;
	cout<<"Nhap vao gia tri va trong luong cac do vat: \n";
	for(i=0; i<n; i++)
	{
		//cin>>a[i][0]>>a[i][1];
		a[i][0] = i+10;
		a[i][1] = i+10;
		Daxet[i] = 0;
	}
	t=0;
	//SXKhongTangGiaTri(a, n);
	SXKhongTangGiaTri(a, n);
	quaylui(a, n, b, Daxet, t, 0);
	in(a, DX, n);
	//cout<<endl<<Tong;
	return 0;
}
