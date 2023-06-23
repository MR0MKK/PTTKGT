//Thuat toan than lam, tim cay khung nho nhat theo Kruskal
#include<stdio.h>
#include<conio.h>
#define nmax 10

typedef struct Egde{
	int x,y;
};
int n,c[nmax][nmax];
void Kruskal(){
	int*D=new int[n];
	Egde*L= new Egde[n-1];
	int min, Dem=0,Sum=0,T=0,Temp;
	for(int i=0;i<n;i++)
	D[i]=0;
	do{
		min=32767;
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		if(c[i][j]>0 &&min>c[i][j]&&!(D[i]!=0&&D[i]==D[j])){
			min=c[i][j];
			L[Dem].x=i;
			L[Dem].y=j;
		}
		//Tao cay moi
		if(D[L[Dem].x]==0&&D[L[Dem].y]==0){
			T++;
			D[L[Dem].x]=D[L[Dem].y]=T;
			
		}
		// Dua dinh tuong ung vao cay
		if(D[L[Dem].x]==0&&D[L[Dem].y]!=0)
			D[L[Dem].x]=D[L[Dem].y];
		// Dua dinh tuong ung vao cay
		if(D[L[Dem].x]!=0 && D[L[Dem].y]==0)
			D[L[Dem].y]=D[L[Dem].x];
		// Gep 2 cay thanh 1 cay moi
		if(D[L[Dem].x]!=D[L[Dem].y]&&D[L[Dem].y]!=0){
			Temp=D[L[Dem].x];
			for(int i=0;i<n;i++)
			if(Temp==D[i])
				D[i]=D[L[Dem].y];
		}
		Sum+=min;
		Dem++;
		
	}
	while(Dem<n-1);
	printf("\nTrong so cua cay khung con nho nhat la: ");
	printf(" %d",Sum);
	printf("\nCay khung con nho nhat la: ");
	for(int i=0;i<n-1;i++)
	printf(" \n(%d - %d)\n",L[i].x+1,L[i].y+1);
}
int main(){
	int i,j;
 	freopen("Kruskal.txt","r",stdin);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
	   for(int j=0;j<n;j++)
		{
			scanf("%d",&c[i][j]);
		}
	}	

	printf("\nSo dinh cua do thi la: %d ",n);
	for(int i=0;i<n;i++)
	{
		printf("\nDong %d:",i+1);
		for(int j=0;j<n;j++)
		printf("%4d ",c[i][j]);
	}
	Kruskal();

	return 0;
}
/*
10
0 2 3 4	5 6 7 0	0 0
2 0 3 0	4 0 5 0	0 0
3 3 0 7	5 6 0 2	9 0
4 0 7 0	0 5 0 2	0 0
5 4 5 0	0 0 0 4	0 0
6 0 6 5	0 0 2 0	0 8
7 5 0 0	0 2 0 1	0 6
0 0 2 2	4 0 1 0	0 5
0 0 0 0	0 0 0 0	0 8
0 0 0 0	0 8 6 5	8 0

8
0 4 4 0 0 0 0 1
4 0 0 8 0 0 0 3
4 0 0 0 0 4 0 2
0 8 0 0 9 0 10 7
0 0 0 9 0 9 18 6
0 0 4 0 9 0 4 4
0 0 0 10 18 4 0 0
1 3 2 7 6 4 0 0

10
0 4 1 4 0 0 0 0 0 0
4 0 5 0 9 9 0 7 0 0
1 5 0 3 0 0 0 9 0 0 
4 0 3 0 0 0 0 10 0 18
0 9 0 0 0 2 4 0 6 0
0 9 0 0 2 0 2 8 0 0
0 0 0 0 4 2 0 9 3 9
0 7 9 10 0 8 9 0 0 8
0 0 0 0 6 0 3 0 0 9
0 0 0 18 0 0 9 8 9 0

10
0 3 1 4 0 0 0 0 0 0
3 0 5 0 9 9 0 7 0 0
1 5 0 3 0 0 0 9 0 0 
4 0 3 0 0 0 0 10 0 18
0 9 0 0 0 2 4 0 6 0
0 9 0 0 2 0 2 8 0 0
0 0 0 0 4 2 0 9 3 9
0 7 9 10 0 8 9 0 0 8
0 0 0 0 6 0 3 0 0 9
0 0 0 18 0 0 9 8 9 0

10
0 2 1 4 0 0 0 0 0 0
2 0 5 0 9 9 0 7 0 0
1 5 0 3 0 0 0 9 0 0 
4 0 3 0 0 0 0 10 0 18
0 9 0 0 0 2 4 0 6 0
0 9 0 0 2 0 2 8 0 0
0 0 0 0 4 2 0 9 3 9
0 7 9 10 0 8 9 0 0 8
0 0 0 0 6 0 3 0 0 9
0 0 0 18 0 0 9 8 9 0

10
0 1 1 4 0 0 0 0 0 0
1 0 5 0 9 9 0 7 0 0
1 5 0 3 0 0 0 9 0 0 
4 0 3 0 0 0 0 10 0 18
0 9 0 0 0 2 4 0 6 0
0 9 0 0 2 0 2 8 0 0
0 0 0 0 4 2 0 9 3 9
0 7 9 10 0 8 9 0 0 8
0 0 0 0 6 0 3 0 0 9
0 0 0 18 0 0 9 8 9 0
*/
