// URL: https://atcoder.jp/contests/joi2009yo/submissions/3713772
// Date: Tue, 04 Dec 2018 01:01:02 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int m, n, obj[90][90];

int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

int dfs(int x, int y)
{
	int ret = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i], ny = y + dy[i];
		if (-1 < nx && nx < m && -1 < ny && ny < n && obj[nx][ny] == 1)
		{
			obj[nx][ny] = 0;
			ret = max(ret, dfs(nx, ny) + 1);
			obj[nx][ny] = 1;
		}
	}
	return ret;
}

int main()
{
	cin >> m >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> obj[i][j];
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (obj[i][j] == 1)
				ans = max(ans, dfs(i, j));
	cout << ans << endl;

	return 0;
}
