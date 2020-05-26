// URL: https://atcoder.jp/contests/arc037/submissions/3608495
// Date: Fri, 16 Nov 2018 21:45:47 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> edge[n];
	for (int i = 0; i < m; i++)
	{
		int v1, v2;
		cin >> v1 >> v2;
		edge[v1 - 1].push_back(v2 - 1);
		edge[v2 - 1].push_back(v1 - 1);
	}
	int ans = 0;
	vector<bool> node(n);
	for (int i = 0; i < n; i++)
		if (!node[i])
		{
			bool ok = true;
			queue<pair<int, int>> que;
			que.push(pair<int, int>(-1, i));
			while (que.size())
			{
				pair<int, int> q = que.front();
				que.pop();
				for (int j = 0; j < edge[q.second].size(); j++)
					if (edge[q.second][j] != q.first)
						if (!node[edge[q.second][j]])
						{
							node[edge[q.second][j]] = true;
							que.push(pair<int, int>(q.second, edge[q.second][j]));
						}
						else
							ok = false;
			}
			if (ok)
				ans++;
		}
	cout << ans << endl;

	return 0;
}
