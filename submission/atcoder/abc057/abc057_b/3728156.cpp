// URL: https://atcoder.jp/contests/abc057/submissions/3728156
// Date: Thu, 06 Dec 2018 21:41:07 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> s(n), p(m);
	for (int i = 0; i < n; i++)
		cin >> s[i].first >> s[i].second;
	for (int i = 0; i < m; i++)
		cin >> p[i].first >> p[i].second;
	for (int i = 0; i < n; i++)
	{
		int far = 1e9, ans = -1;
		for (int j = 0; j < m; j++)
			if (abs(s[i].first - p[j].first) + abs(s[i].second - p[j].second) < far)
			{
				far = abs(s[i].first - p[j].first) + abs(s[i].second - p[j].second);
				ans = j;
				cerr << i << " " << j << " " << m << endl;
			}
		cout << ans + 1 << endl;
	}

	return 0;
}
