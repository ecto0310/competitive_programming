// URL: https://atcoder.jp/contests/dp/submissions/3941711
// Date: Sun, 06 Jan 2019 21:11:13 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

long long dp[1000][1000];

const int mod = 1e9 + 7;

int main()
{
	int h, w;
	cin >> h >> w;
	vector<string> a(h);
	for (int i = 0; i < h; i++)
		cin >> a[i];
	dp[0][0] = 1;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
		{
			if (i + 1 != h && a[i + 1][j] == '.')
				dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % mod;
			if (j + 1 != w && a[i][j + 1] == '.')
				dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % mod;
		}
	cout << dp[h - 1][w - 1] % mod << endl;

	return 0;
}
