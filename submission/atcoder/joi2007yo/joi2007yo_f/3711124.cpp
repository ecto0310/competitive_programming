// URL: https://atcoder.jp/contests/joi2007yo/submissions/3711124
// Date: Mon, 03 Dec 2018 15:49:50 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int a, b;
vector<vector<bool>> o(18, vector<bool>(18, true));

int dfs(int x = 1, int y = 1)
{
	if (x == a && y == b)
		return 1;
	if (a < x || b < y)
		return 0;
	int ret = 0;
	if (o[x + 1][y])
		ret += dfs(x + 1, y);
	if (o[x][y + 1])
		ret += dfs(x, y + 1);
	return ret;
}

int main()
{
	int n;
	cin >> a >> b >> n;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		o[x][y] = false;
	}
	cout << dfs() << endl;

	return 0;
}
