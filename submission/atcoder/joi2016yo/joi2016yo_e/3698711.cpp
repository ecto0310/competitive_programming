// URL: https://atcoder.jp/contests/joi2016yo/submissions/3698711
// Date: Sun, 02 Dec 2018 14:30:38 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n, m, k, s, p, q;
	cin >> n >> m >> k >> s >> p >> q;
	vector<int> bad(k);
	for (int i = 0; i < k; i++)
	{
		cin >> bad[i];
		bad[i]--;
	}
	vector<vector<int>> edge(n);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		edge[a - 1].push_back(b - 1);
		edge[b - 1].push_back(a - 1);
	}
	vector<long long> cost(n, p);
	for (int i = 0; i < k; i++)
	{
		vector<int> tmp(n, s + 1);
		queue<int> que;
		que.push(bad[i]);
		tmp[bad[i]] = 0;
		while (que.size())
		{
			int now = que.front();
			que.pop();
			for (int j : edge[now])
				if (tmp[now] + 1 < tmp[j])
				{
					cost[j] = q;
					tmp[j] = tmp[now] + 1;
					que.push(j);
				}
		}
	}
	cost[n - 1] = 0;
	for(int t:bad)
		cost[t] = 1e9;
	vector<long long> ans(n, 1e18);
	queue<int> que;
	ans[0] = 0;
	que.push(0);
	while (que.size())
	{
		int now = que.front();
		que.pop();
		for (int j : edge[now])
			if (ans[now] + cost[j] < ans[j])
			{
				ans[j] = ans[now] + cost[j];
				que.push(j);
			}
	}
	cout << ans[n - 1] << endl;

	return 0;
}
