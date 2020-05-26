// URL: https://atcoder.jp/contests/abc004/submissions/3600477
// Date: Wed, 14 Nov 2018 23:56:29 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	string c[4][4];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			cin >> c[i][j];
	for (int i = 3; i >= 0; i--)
		for (int j = 3; j >= 0; j--)
			cout << c[i][j] << (j == 0 ? "\n" : " ");

	return 0;
}
