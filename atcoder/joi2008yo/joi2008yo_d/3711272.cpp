// URL: https://atcoder.jp/contests/joi2008yo/submissions/3711272
// Date: Mon, 03 Dec 2018 16:22:44 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<pair<int, int>> b(n);
	for (int i = 0; i < n; i++)
		cin >> b[i].first >> b[i].second;
	int m;
	cin >> m;
	map<pair<int, int>, bool> p;
	vector<pair<int, int>> star(m);
	for (int i = 0; i < m; i++)
	{
		cin >> star[i].first >> star[i].second;
		p[{star[i].first, star[i].second}] = true;
	}
	for (int i = 0; i < m; i++)
	{
		int dx = b[0].first - star[i].first, dy = b[0].second - star[i].second;
		bool ok = true;
		for (int j = 1; j < n; j++)
			if (!p[{b[j].first - dx, b[j].second - dy}])
				ok = false;
		if (ok)
		{
			cout << -1 * dx << " " << -1 * dy << endl;
			return 0;
		}
	}

	return 0;
}
