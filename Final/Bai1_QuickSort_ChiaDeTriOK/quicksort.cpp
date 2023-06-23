// bai toan sap xep nhanh
#include"conio.h"
#include"stdio.h"
int a[100];
int n;
void init()
{
	FILE*in ;
	in=fopen("input2.txt","r");
	fscanf(in,"%d",&n);
	for(int i=1;i<=n;i++)
	{
		fscanf(in,"%d",&a[i]);
		
	}
	
}
void swap(int &a, int &b)
{
	int x;
	x=a;
	a=b;
	b=x;
}
int partition(int a[100], int l, int r)
{
	
/*	printf(" l=%d r=%d ",l,r);
	printf("\n");
	printf("i\t j\t" );
	for(int i=l;i<=r;i++)
	{printf("%d\t ",i);}
	printf("\n");*/
	int x=a[l];
	int i=l+1;
	int j=r;
	while(i<=j)
	{
		while(i<=j&&a[i]<=x)i++;
		while(j>=i&&a[j]>x)j--;
		if(i<j)swap(a[i],a[j]);
/*	printf("%d\t ",i);
	printf("%d\t ",j);
	for(int i=l;i<=r;i++)
	{
		printf("%d\t ",a[i]);
	}
	printf("\n");*/
	}swap(a[l],a[j]);
//		printf("%d\t ",i);
//		printf("%d\t ",j);
	
/*	for(int i=l;i<=r;i++)
	{
		printf("%d\t ",a[i]);
	}printf("\n");
	printf("----------------------------------------------------------------------------------------------------");
	printf("\n");
		printf("=== j= %d=== ",j);
	printf("\n");
*/
	return j;
	
		
}
int  quicksort(int a[100], int l, int r)
{
	if(l>=r ) return 0 ;
	int i=partition(a,l,r);
	quicksort(a,l,i-1);
	quicksort(a,i+1,r);
}
main()
{
	init();
	quicksort(a,1,n);
	printf("ket qua sap xep");
	printf("\n");
	for(int i=1;i<=n;i++)
	{
		printf("%d\t",a[i]);
	}
}
