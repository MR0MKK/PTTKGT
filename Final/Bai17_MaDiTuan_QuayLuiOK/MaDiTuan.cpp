#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>
int  dx[]={2, 1, -1, -2, -2, -1, 1, 2};
int  dy[]={1, 2, 2, 1, -1, -2, -2, -1};
int n=5;
int h[8][8];
//===================
void Init(int h[8][8], int n, int x, int y)
{
	int i, j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++) 
		{
			h[i][j]=0;
		}	
	}
	h[x][y]=1;//Xuat phat tu toa do (x,y) o buoc thu nhat
}
//=======================
void print(int h[8][8], int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf(" %d\t", h[i][j]);
		}
		printf("\n");
	}
	printf("\n--------------------------------------------\n");
}
//thu cac kha nang co the co
void Try(int i, int x, int y, int h[8][8])
{
	int j, u, v;
	int dem=0;
	if(i<n*n)
	{
		for(j=0;j<8;j++)//tu 1 vi tri co the di den 8 vi tri khac
		{
			u=x+dx[j];
			v=y+dy[j];
			if(h[u][v]==0 && 0<=u && u<n && 0<=v && v<n)//VT moi con tren ban co,chua di qua
			{
				h[u][v]=i+1;// Gan bang buoc do luon 
				Try(i+1,u,v,h);
			  	h[u][v]=0;//Huy buoc di
			}
		}
	}
	else
	{ 
		print(h,n);//In ra ma tran h
	}
}
int main()
{
	int x,y;
	printf("Nhap vi tri ban dau: "); 
	scanf("%d%d",&x, &y);
	Init(h,n,x,y);
	Try(1,x,y,h);
	getch();
	return 0;
}
