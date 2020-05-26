// URL: https://atcoder.jp/contests/abc044/submissions/2853621
// Date: Mon, 16 Jul 2018 02:00:52 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

// 今,選んだ枚数,合計
long long dp[50][51][2501];

int main()
{
	int n, a, x[50];
	cin >> n >> a;
	for (int i = 0; i < n; i++)
		cin >> x[i];
	dp[0][0][0] = 1;
	dp[0][1][x[0]] = 1;
	for (int i = 1; i < n; i++)
		for (int j = 0; j < n + 1; j++)
			for (int k = 0; k < 2501; k++)
				dp[i][j][k] = dp[i - 1][j][k] + (j == 0 || k - x[i] < 0 ? 0 : dp[i - 1][j - 1][k - x[i]]);
	long long ans = 0;
	for (int i = 1; i < n + 1; i++)
		ans += dp[n - 1][i][i * a];
	cout << ans << endl;
	return 0;
}
