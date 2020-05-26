// URL: https://atcoder.jp/contests/joi2017yo/submissions/3564351
// Date: Thu, 08 Nov 2018 20:53:20 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> v(m);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		v[i] = pair<int, int>(a, b);
	}
	sort(v.begin(), v.end(), greater<pair<int, int>>());
	int ans = 0;
	for (int i = 0; i < m - 1; i++)
		if (v[i].first < n)
			ans += n - v[i].first;
	cout << ans << endl;

	return 0;
}
