// LCS.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stack>
using namespace std;
string input1;
string input2;
int b[500][500];
int c[500][500];
void LCS() {
	int m = input1.length();
	int n = input2.length();
	for (int i = 1; i <=m; i++)
	{
		for (int j = 1; j <=n; j++) {
			if (input1[i-1]==input2[j-1])
			{
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = 1;
			}
			else if (c[i - 1][j] >= c[i][j - 1]) {
				c[i][j] = c[i - 1][j];
				b[i][j] = 2;
			}
			else
			{
				c[i][j] = c[i][j - 1];
				b[i][j] = 3;
			}
		}

	}
}
stack<char>output;
void printLCS(int i, int j) {
	if (i == 0 || j == 0) {
		return;
	}
	if (b[i][j] == 1) {
		output.push(input1[i - 1]);
		printLCS(i - 1, j - 1);
	}
	else if (b[i][j] == 2) {
		printLCS(i - 1, j);
	}
	else if(b[i][j]==3)
	{
		printLCS(i, j - 1);
	}

}
int main()
{
	memset(b, 0, sizeof(b));
	memset(c, 0, sizeof(c));
	cin >> input1 >> input2;
	LCS();
	int m = input1.length();
	int n = input2.length();
	cout << c[m][n] << endl;
	printLCS(m, n);
	while (!output.empty())
	{
		cout << output.top();
		output.pop();
	}
	cout << endl;
    return 0;
}

