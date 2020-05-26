// URL: https://atcoder.jp/contests/abc089/submissions/2797708
// Date: Fri, 06 Jul 2018 23:00:47 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int h, w, d;
	cin >> h >> w >> d;
	map<int, pair<int, int>> m;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
		{
			int a;
			cin >> a;
			m[a] = pair<int, int>(i, j);
		}
	int cost[90001] = {};
	for (int i = 1; i <= d; i++)
		for (int now = i + d; now <= h * w; now += d)
			cost[now] = cost[now - d] + abs(m[now].first - m[now - d].first) + abs(m[now].second - m[now - d].second);
	int q;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		int l, r;
		cin >> l >> r;
		cout << cost[r] - cost[l] << endl;
	}

	return 0;
}
