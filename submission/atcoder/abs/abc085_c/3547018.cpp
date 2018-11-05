// URL: https://atcoder.jp/contests/abs/submissions/3547018
// Date: Mon, 05 Nov 2018 17:08:30 +0900
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
			if (i * 10000 + j * 5000 + 1000 * (n - i - j) == y)
			{
				cout << i << " " << j << " " << n - i - j << endl;
				return 0;
			}
	cout << "-1 -1 -1" << endl;

	return 0;
}
