#include<iostream>
#include<fstream>
#include<queue>
using namespace std;

int n, s, t;
int a[100][100];
int daxet[100];
int truoc[100];

void nhap(){
	int i, j;
	cout << "Dinh bat dau: ";
	cin >> s;
	cout << "Dinh ket thuc: ";
	cin >> t;
	freopen("input5.txt", "r", stdin);
	cin >> n;
	for (i = 1; i <= n; i++){
		for (j = 1; j <= n; j++) 
			cin >> a[i][j];
	}
	cout << "So dinh:" << n << endl;	
	for (i = 1; i <= n; i++){
		daxet[i] = 0;
		truoc[i] = 0;
	}
}

void xuat(){
	cout << t << "<--";
	int j = t;
	while (truoc[j] != s){
		cout << truoc[j] << "<--";
		j = truoc[j];
	}
	cout << s << endl;
}

void BFS(int s){
	queue<int> q;
	q.push(s);
	daxet[s] = 1;
	while (!q.empty()){
		int u = q.front(); // lay dinh o dau hang doi
		q.pop();	// xoa dinh o dau hang doi
		// duyet cac dinh ke v va chua duoc them va push to queue
		for (int v = 1; v <= n; v++){
			if (a[u][v] == 1 && daxet[v] == 0){
				daxet[v] = 1;
				truoc[v] = u;
				if (v == t){
					xuat();
				
				}
			else{
			     BFS(v);
		      	}	
			daxet[v] = 0;
			}
		}
	}
}

int main(){
	nhap();
	BFS(s);
	return 0;
}
