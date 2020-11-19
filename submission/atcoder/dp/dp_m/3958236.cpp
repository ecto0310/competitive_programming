// URL: https://atcoder.jp/contests/dp/submissions/3958236
// Date: Tue, 08 Jan 2019 02:04:45 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int dp[101][100001];
int sum[100001];

const int mod = 1e9 + 7;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	dp[0][k] = 1;
	for (int i = 0; i < n; i++)
	{
		memset(sum, 0, sizeof(sum));
		sum[0] = dp[i][0];
		for (int j = 1; j <= 100000; j++)
			sum[j] = (sum[j - 1] + dp[i][j]) % mod;
		for (int j = 0; j <= k; j++)
			dp[i + 1][j] = (sum[min(k, j + a[i])] - (j == 0 ? 0 : sum[j - 1]) + mod) % mod;
	}
	cout << dp[n][0] % mod << endl;

	return 0;
}
