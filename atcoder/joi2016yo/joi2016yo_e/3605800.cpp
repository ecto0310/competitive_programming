// URL: https://atcoder.jp/contests/joi2016yo/submissions/3605800
// Date: Fri, 16 Nov 2018 08:34:54 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n, m, k, s, p, q;
	cin >> n >> m >> k >> s >> p >> q;
	vector<int> c(k);
	for (int i = 0; i < k; i++)
	{
		cin >> c[i];
		c[i]--;
	}
	vector<int> road[n];
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		road[a - 1].push_back(b - 1);
		road[b - 1].push_back(a - 1);
	}
	vector<long long> cost(n, p);
	for (int i = 0; i < k; i++)
	{
		vector<int> tmp(n, 1e9);
		tmp[c[i]] = 0;
		queue<int> que;
		que.push(c[i]);
		while (que.size())
		{
			int qu = que.front();
			que.pop();
			for (int j = 0; j < road[qu].size(); j++)
				if (tmp[qu] + 1 < tmp[road[qu][j]] && tmp[qu] + 1 <= s)
				{
					tmp[road[qu][j]] = tmp[qu] + 1;
					que.push(road[qu][j]);
					cost[road[qu][j]] = q;
				}
		}
	}
	for (int i = 0; i < k; i++)
		cost[c[i]] = 1e18;
	cost[n - 1] = 0;
	vector<long long> ans(n, 1e18);
	ans[0] = 0;
	queue<int> que;
	que.push(0);
	while (que.size())
	{
		int qu = que.front();
		que.pop();
		for (int j = 0; j < road[qu].size(); j++)
			if (ans[qu] + cost[road[qu][j]] < ans[road[qu][j]])
			{
				ans[road[qu][j]] = ans[qu] + cost[road[qu][j]];
				que.push(road[qu][j]);
			}
	}
	cout << ans[n - 1] << endl;

	return 0;
}
