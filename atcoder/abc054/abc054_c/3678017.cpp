// URL: https://atcoder.jp/contests/abc054/submissions/3678017
// Date: Wed, 28 Nov 2018 00:08:51 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

bool vis[8];

int n, m;
bool edge[8][8];

int dfs(int now)
{
	bool ok = true;
	for (int i = 0; i < n; i++)
		if (!vis[i])
			ok = false;
	if (ok)
		return 1;

	int ans = 0;
	for (int i = 0; i < n; i++)
		if (edge[now][i] && !vis[i])
		{
			vis[i] = true;
			ans += dfs(i);
			vis[i] = false;
		}
	return ans;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		edge[a - 1][b - 1] = edge[b - 1][a - 1] = true;
	}
	vis[0] = true;
	cout << dfs(0) << endl;

	return 0;
}
