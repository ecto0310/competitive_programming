// URL: https://atcoder.jp/contests/joi2015yo/submissions/3727396
// Date: Thu, 06 Dec 2018 19:43:17 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> d(n), c(m);
	for (int i = 0; i < n; i++)
		cin >> d[i];
	for (int i = 0; i < m; i++)
		cin >> c[i];
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 1e9));
	dp[0][0] = 0;
	for (int i = 1; i <= m; i++)
		for (int j = 0; j <= n; j++)
			if (j == 0)
				dp[i][j] = 0;
			else
				dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1] + c[i - 1] * d[j - 1]);
	cout << dp[m][n] << endl;

	return 0;
}
