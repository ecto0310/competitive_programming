// URL: https://atcoder.jp/contests/code-festival-2016-qualc/submissions/3720791
// Date: Wed, 05 Dec 2018 15:38:24 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int k, t;
	cin >> k >> t;
	int m = 0;
	for (int i = 0; i < t; i++)
	{
		int a;
		cin >> a;
		m = max(m, a);
	}
	cout << max(0, 2 * m - k - 1) << endl;

	return 0;
}
