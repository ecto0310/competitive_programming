// URL: https://atcoder.jp/contests/abc024/submissions/3593836
// Date: Tue, 13 Nov 2018 16:55:50 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n, t;
	cin >> n >> t;
	map<int, bool> m;
	int l;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		m[a] = true;
		l = a;
	}
	int ans = 0, lim = 0;
	for (int i = 0; i <= l; i++)
	{
		if (m[i])
			lim = t;
		else
			lim = max(lim - 1, 0);
		if (0 < lim)
			ans++;
	}
	cout << ans + max(lim - 1, 0) << endl;

	return 0;
}
