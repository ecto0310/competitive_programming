// URL: https://atcoder.jp/contests/joi2008yo/submissions/3713432
// Date: Mon, 03 Dec 2018 23:41:36 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

const int INF = 1e9;
int n;

struct Edge
{
	int to, cost;
};

vector<Edge> edge[100];

int dijkstra(int from, int to)
{
	vector<int> d(n, INF);
	queue<int> que;
	d[from] = 0;
	que.push(from);
	while (que.size())
	{
		int now = que.front();
		que.pop();
		for (Edge t : edge[now])
			if (d[now] + t.cost < d[t.to])
			{
				d[t.to] = d[now] + t.cost;
				que.push(t.to);
			}
	}
	return d[to];
}

int main()
{
	int k;
	cin >> n >> k;
	for (int i = 0; i < k; i++)
	{
		int t;
		cin >> t;
		if (t == 0)
		{
			int a, b;
			cin >> a >> b;
			a--;
			b--;
			int ans = dijkstra(a, b);
			cout << (ans == INF ? -1 : ans) << endl;
		}
		else
		{
			int c, d, e;
			cin >> c >> d >> e;
			c--;
			d--;
			edge[c].push_back({d, e});
			edge[d].push_back({c, e});
		}
	}

	return 0;
}
