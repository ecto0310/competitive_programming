// URL: https://atcoder.jp/contests/future-contest-2018-qual/submissions/2509594
// Date: Sun, 13 May 2018 20:51:22 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>
#include<assert.h>

using namespace std;

int main()
{
	int n = 100;
	int a[100][100];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	cout << 1000 << endl;
	for(int i = 0; i < 1000; i++)
	{
		cout << rand() % 100 << " " << rand() % 100 << " " << rand() % 100 + 1 << endl;
	}

	return 0;
}
