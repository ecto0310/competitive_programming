// URL: https://atcoder.jp/contests/abc099/submissions/2920790
// Date: Sun, 29 Jul 2018 23:35:16 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n, c, d[30][30];
	cin >> n >> c;
	for (int i = 0; i < c; i++)
		for (int j = 0; j < c; j++)
			cin >> d[i][j];
	int grid[3][30] = {};
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			int c;
			cin >> c;
			grid[(i + j) % 3][c - 1]++;
		}
	int ans = 1000000000;
	for (int i = 0; i < c; i++)
		for (int j = 0; j < c; j++)
		{
			if (i == j)
				continue;
			for (int k = 0; k < c; k++)
			{
				if (i == k || j == k)
					continue;
				int tmp = 0;
				for (int l = 0; l < c; l++)
				{
					tmp += d[l][i] * grid[0][l];
					tmp += d[l][j] * grid[1][l];
					tmp += d[l][k] * grid[2][l];
				}
				ans = min(ans, tmp);
			}
		}
	cout << ans << endl;

	return 0;
}
