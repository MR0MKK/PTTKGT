#include<iostream>
#include<fstream>
using namespace std;
int n,s,t;
int a[100][100];
int daxet[100];
int truoc[100];
void nhap(){
	int i,j;
	cout<<"Dinh bat dau: ";cin>>s;
	cout<<"Dinh ket thuc: ";cin>>t;
	freopen("input5.txt","r",stdin);
	cin>>n;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++) 
		cin>>a[i][j];
	}
	cout<<"So dinh:"<<n<<endl;	
	for(i=1;i<=n;i++){
		daxet[i]=0;
		truoc[i]=0;
	}
}
void xuat(){
	cout<<t<<"<--";
	int j=t;
	while(truoc[j]!=s){
		cout<<truoc[j]<<"<--";
		j=truoc[j];
	}
	cout<<s<<endl;
}
void DFS(int s){
	int u;
	daxet[s]=1;
	for(u=1;u<=n;u++){
//		cout<<"Ahihi vong for u= "<<u<<endl;
		if(a[s][u]==1&&daxet[u]==0){
			daxet[u]=1;
//			cout<<"Da xet: "<<u<<endl;
			truoc[u]=s;
//			cout<<"Truoc u: "<<s<<endl;
			if(u==t) xuat();
			else {
//				cout<<endl<<"DFS: "<<u<<endl;
				DFS(u);
			}
			daxet[u]=0;
//			cout<<"Tra lai chua xet:"<<u<<endl;
		}
	}
}
int main(){
	nhap();
	DFS(s);
	return 0;
}
