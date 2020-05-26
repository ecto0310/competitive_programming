// URL: https://atcoder.jp/contests/abc085/submissions/3696132
// Date: Sat, 01 Dec 2018 21:07:36 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n, y;
	cin >> n >> y;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n - i; j++)
			if (i * 10000 + j * 5000 + (n - i - j) * 1000 == y)
			{
				cout << i << " " << j << " " << n - i - j << endl;
				return 0;
			}
	cout << "-1 -1 -1" << endl;

	return 0;
}
