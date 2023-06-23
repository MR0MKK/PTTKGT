// merge sort
#include"stdio.h"
#include"conio.h"
int a[100];
int n;
void init()
{
	FILE*in;
	in=fopen("input1.txt","r");
	fscanf(in,"%d",&n);
	for(int i=1;i<=n;i++)
	{
		fscanf(in,"%d",&a[i]);
	}
	
	
}
void merge(int a[100],int l,int r)
{
	int c[100];
	int t=(l+r)/2;
	int i=l;
	int j=t+1;
	int p=l;
	while(i<=t&&j<=r)
	{
		if(a[i]<a[j])
		{
			c[p]=a[i];
			i++;
		}else{
			c[p]=a[j];
			j++;
		}p++;
		
	}
	while(i<=t)
	{
		c[p]=a[i];
		i++;
		p++;
	}
	while(j<=r)
	{
		c[p]=a[j];
		j++;
		p++;
	}
	for(int i=l;i<=r;i++)
	{
		a[i]=c[i];
	}
	
	
}
int mergesort(int l, int r)
{
	if(l>=r)
	return 0;
	int t=(l+r)/2;
	mergesort(l,t);
	mergesort(t+1,r);
	merge(a,l,r);

}
int main()
{
	init();
	
	mergesort(1,n);
	printf("sap xep la: ");
	for(int i=1;i<=n;i++)
	{
		printf("%d\t",a[i]);
	}
}
