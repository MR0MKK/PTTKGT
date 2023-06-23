#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;
#define max 100
int n;
struct Activity {
	char id[max];
	int start;
	int finish;
};
Activity activities[max];
void activitySelection(Activity activities[], int n);
void NhapFile();
int main()
{
	/*Activity activities[8] = {
		{"a1", 1, 3},
		{"a2", 0, 4},
		{"a3", 1, 2},
		{"a4", 4, 6},
		{"a5", 2, 9},
		{"a6", 5, 8},
		{"a7", 3, 5},
		{"a8", 4, 5}
	};*/

	//number of activities
	//int n = 8;
	NhapFile();
	activitySelection(activities, n);
	system("pause");
	return 0;
}
void NhapFile()
{
	//Activity activities[max];
	fstream f;
	f.open("InputCau10.txt", ios::in);
	f >> n;
	for (int i = 0; i < n; i++)
	{
		f >> activities[i].id;
		f >> activities[i].start;
		f >> activities[i].finish;
	}
	f.close();
}
void activitySelection(Activity activities[], int n)
{
	int i, j;
	Activity temp;
	//step 1
	//sort the activities as per finishing time in ascending order
	for (i = 1; i < n; i++) {
		for (j = 0; j < n - 1; j++) {
			if (activities[j].finish > activities[j + 1].finish) {
				temp = activities[j];
				activities[j] = activities[j + 1];
				activities[j + 1] = temp;
			}
		}
	}

	//sorted
	cout << "Sorted activities as per finish time (ascending order)\n";
	cout << "\tActivity" << "\tStart" << "\tFinish" << endl;
	for (i = 0; i < n; i++) {
		cout << "\t" << activities[i].id << "\t\t" << activities[i].start << "\t" << activities[i].finish << endl;
	}

	//step 2
	//select the first activity
	cout << "-----Selected Activities-----\n";
	cout << "\tActivity" << "\tStart" << "\tFinish" << endl;
	cout <<  "\t" << activities[0].id << "\t\t" << activities[0].start << "\t" << activities[0].finish << endl;

	//step 3
	//select next activity whose start time is greater than
	//or equal to the finish time of the previously selected activity
	i = 0;
	for (j = 1; j < n; j++) {
		if (activities[j].start >= activities[i].finish) {
			cout << "\t" << activities[j].id << "\t\t" << activities[j].start << "\t" << activities[j].finish << endl;
			i = j;
		}
	}
}