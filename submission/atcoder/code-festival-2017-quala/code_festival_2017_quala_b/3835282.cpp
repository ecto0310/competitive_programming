// URL: https://atcoder.jp/contests/code-festival-2017-quala/submissions/3835282
// Date: Sat, 22 Dec 2018 15:11:52 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	bool ok = false;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			if (i * (m - j) + j * (n - i) == k)
				ok = true;
	cout << (ok ? "Yes" : "No") << endl;

	return 0;
}
