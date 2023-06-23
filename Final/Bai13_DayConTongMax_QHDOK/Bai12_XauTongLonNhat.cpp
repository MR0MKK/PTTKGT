#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn=100000+10;
int n;
int a[maxn];
int MaxS[maxn],MaxE[maxn];
int s1[maxn],s[maxn],e[maxn];
void docfile()
{
	char tenfile[28];
	int i;
	FILE *fp;
	fp=fopen("input.txt","rt");
	if(fp==NULL)
	{
		printf("file khong ton tai!\n");
		exit(0);
	}
	else
	{
		fscanf(fp,"%d",&n);
		for(i=1;i<=n;i++)
			fscanf(fp,"%d",&a[i]);
	}
}
// 16 -18 2 18 -2 4 8 1 -5 -2
int MaxSubSeq(){
	MaxE[1]=a[1];s1[1]=1;
  	MaxS[1]=a[1];s[1]=1;e[1]=1;
  	for(int i=2;i<=n;i++){	
    	// Tinh MaxE[i]=Max(MaxE[i-1],0)+a[i];
    	if (MaxE[i-1]>0){
      		MaxE[i]=MaxE[i-1]+a[i];
      		s1[i]=s1[i-1];
      		
    	}
    	else{
      		MaxE[i]=a[i];
      		s1[i]=i;
    	}
    	// Tinh MaxS[i]=Max(MaxS[i-1],MaxE[i]);
    	if (MaxS[i-1]>=MaxE[i]){
      		MaxS[i]=MaxS[i-1];
      		s[i]=s[i-1];e[i]=e[i-1];
      		}
    	else{
      		MaxS[i]=MaxE[i];
      		s[i]=s1[i];e[i]=i;
      	}
   	 printf("%5d %5d %5d %5d %5d\n",MaxE[i],s1[i],MaxS[i],s[i],e[i]);
  	}
}
int main(){
  docfile();
  MaxSubSeq();
  printf("Day con co tong Max la: ");
  for(int i=s[n];i<=e[n];i++) printf("%d ",a[i]);
  printf("\n");
  printf("Trong so la: %d",MaxS[n]);
  return 0;
}

