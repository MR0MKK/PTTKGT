#include <iostream>
using namespace std;

#define MAX 1000
bool DEBUG = true;

string s1, s2;
int C[MAX + 1][MAX + 1], l1, l2;
char M[MAX + 1];
int maxLen = 0;                // chieu dai xau con chung dai nhat
bool common[MAX + 1][MAX + 1]; // xau con chung dai nhat

/* Bang C luu do dài cua xâu con chung dài nhat tính toi vi trí dang xét (xâu s1[0..i] và s2[0..j]) */
void lcs()
{
    l1 = s1.length(), l2 = s2.length();
    for (int i = 0; i <= l1; i++)
    {
        for (int j = 0; j <= l2; j++)
        {
            common[i][j] = false;

            if (i == 0 || j == 0)
            {
                C[i][j] = 0;
            }
            else if (s1[i - 1] == s2[j - 1])
            {
                C[i][j] = C[i - 1][j - 1] + 1;
                //cout << i << "~" << j << " ~~ " << C[i][j] << " - " << C[i - 1][j - 1] << endl;
                //maxLen = max(maxLen, C[i][j]);
                if (maxLen < C[i][j])
                {
                    maxLen = C[i][j];
                    common[i][j] = true;
                }
                else if (C[i][j] == maxLen)
                {
                    for (int k = maxLen - 1; k >= 0; k--)
                    {
                        if (s1[i - k - 1] == s2[j - k - 1])
                        {
                            common[i - k][j - k] = true;
                            C[i - k][j - k] = C[i - k - 1][j - k - 1] + 1;
                        }
                        else
                            break;
                    }
                }
            }
            else
            {
                C[i][j] = 0;
            }
        }
    }
}

/*Truy vet liet ke nghiem*/
void trace()
{
    int m = 0;
    for (int i = 0; i <= l1;)
    {
        for (int j = 0; j <= l2; j++)
        {
            if (common[i][j] == true)
            {
                if (m != i)
                {
                    if (i != m + 1)
                        cout << endl;
                    cout << s1[i - 1];
                    m = i;
                }
            }
        }
        i++;
    }
    cout << "\nmaxLen = " << maxLen << endl;
}

int main()
{
    s1 = "HOAHONG", s2 = "KHOAHOC";
    s1 = "OldSite:GeeksforGeeks.org", s2 = "NewSite:GeeksQuiz.com";
    s1 = "BAITAPBAIMOI"; s2 = "HAITHAHAIM";

    lcs();
    trace();

    return 0;
}
