// URL: https://atcoder.jp/contests/abc061/submissions/2819086
// Date: Mon, 09 Jul 2018 23:15:24 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int road[50][50] = {};
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		road[a - 1][b - 1]++;
		road[b - 1][a - 1]++;
	}
	for (int i = 0; i < n; i++)
	{
		int ans = 0;
		for (int j = 0; j < n; j++)
			ans += road[i][j];
		cout << ans << endl;
	}

	return 0;
}
