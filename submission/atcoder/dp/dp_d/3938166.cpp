// URL: https://atcoder.jp/contests/dp/submissions/3938166
// Date: Sun, 06 Jan 2019 20:24:45 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

long long dp[101][100001];

int main()
{
	int N, W;
	cin >> N >> W;
	vector<int> w(N), v(N);
	for (int i = 0; i < N; i++)
		cin >> w[i] >> v[i];
	for (int i = 0; i < N; i++)
		for (int j = 0; j <= W; j++)
		{
			if (j + w[i] <= W)
				dp[i + 1][j + w[i]] = max(dp[i + 1][j + w[i]], dp[i][j] + v[i]);
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
		}
	cout << dp[N][W] << endl;

	return 0;
}
