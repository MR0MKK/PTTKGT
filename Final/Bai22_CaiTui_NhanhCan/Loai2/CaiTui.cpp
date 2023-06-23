//thuat toan nhanh can, tim phuong an toi uu
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
const int max = 100;
int w[max], v[max], n; //khai bao mang chua khoi luong, gia tri cua cac do vat, va n
float wv[max];
int soluong;//so luong 
int khoiluong;//khoi luong túi
int khoiluongdovat;//khoi luong do vat chiem trong túi sau khi xep toi uu
int TL=0;//trong luong tong các vat da xep(hien tai)
int dem = 0;
int gt[100];		//cac buoc cua thuat toan
int sl[100],slmax[100];		//nhanh can
int s=0;//tong giá tri tai thoi diem hien tai
int fmax=0;//giá tri lon nhat sau moi lan duyet het
float g;//dieu kien bo nhanh

void input()
{
	FILE *f;
	int i, x, y;
	f = fopen("CaiTui1.txt", "r");
	fscanf(f, "%d", &khoiluong);
	fscanf(f, "%d", &n);
	for (i = 0; i < n; i++)
	{
			fscanf(f, "%d", &x);
			w[i] = x;
			fscanf(f, "%d", &y);
			v[i] = y;
			wv[i] = (float)v[i] / w[i];
	}
	
	fclose(f);
}
void hoandoi(float &a, float &b) {
	float temp = a;
	a = b;
	b = temp;
}
//sap xep theo thu tu giam dan cua v[i]/w[i] tuc la wv[i]
void sort() {
	for (int i = 0; i<n; i++) {
		for (int j = i + 1; j<n; j++) {
			if (wv[j]>wv[i]) {
				hoandoi((float&)w[j], (float&)w[i]);
				hoandoi((float&)v[j], (float&)v[i]);
				hoandoi(wv[j], wv[i]);
			}
			else if (wv[j] == wv[i]) 
			{
				if (w[j]<w[i])//sx tang dan cua khoi luong
				{
					hoandoi((float&)w[j], (float&)w[i]);
					hoandoi((float&)v[j], (float&)v[i]);
					hoandoi(wv[j], wv[i]);
				}
			}
		}
	}
}
//hien thi 
void display() {
	printf("\nDo vat   khoiluong    Giatri      Tyso\n");
	for (int i = 0; i<n; i++) {
		printf("%d  \t  %3d  \t       %3d  \t%5.2f", i+1, w[i], v[i], wv[i]);
		printf("\n");
	}
}
//thuat toan nhanh can
void Try(int i) 
{
	int j;
	soluong = (khoiluong - TL) / w[i];
	for (j = soluong; j >= 0; j--)
	{
		sl[i] = j;
		TL += w[i] * sl[i];
		s += v[i] * sl[i];
		if (i == n-1)
		{
			if (s > fmax)
			{
				for (int k = 0; k < n; k++)
				{
					slmax[k] = sl[k];
				}
				khoiluongdovat = TL;
				fmax = s;
			}
		}
		else
		{
			g = s + (float)v[i + 1] * (khoiluong - TL) / w[i + 1];
			if (g > fmax)
				Try(i + 1);
		}
		TL = TL - w[i] * sl[i];
		s = s - v[i] * sl[i];
	}
}
int main()
{
	input();
	//display();
	printf("\nSau khi sap xep:\n");
	sort();
	display();
	printf("\nThuat toan nhanh can: \n");
	Try(0);
	printf("\nDo vat   soluong   khoiluong    giatri\n");
	for (int i = 0; i<n; i++) 
	{
		printf("%d         %d        %d         %d   \n", i+1,slmax[i],w[i],v[i]);
		printf("\n");
	}
	printf("\nKhoi luong tui da dung: %d", khoiluongdovat);
	printf("\nTong gia tri: %d", fmax);
	getchar();
	getchar();
	return 1;
}
