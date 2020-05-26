// URL: https://atcoder.jp/contests/abc057/submissions/2827038
// Date: Wed, 11 Jul 2018 23:52:05 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int a[50], b[50], c[50], d[50];
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i];
	for (int i = 0; i < m; i++)
		cin >> c[i] >> d[i];
	for (int i = 0; i < n; i++)
	{
		int ans = 0, far = 1000000000;
		for (int j = 0; j < m; j++)
			if (far > abs(a[i] - c[j]) + abs(b[i] - d[j]))
			{
				far = abs(a[i] - c[j]) + abs(b[i] - d[j]);
				ans = j;
			}
		cout << ans + 1 << endl;
	}

	return 0;
}
