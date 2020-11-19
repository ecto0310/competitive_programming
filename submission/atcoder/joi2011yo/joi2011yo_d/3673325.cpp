// URL: https://atcoder.jp/contests/joi2011yo/submissions/3673325
// Date: Mon, 26 Nov 2018 23:00:02 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

long long dp[105][21];

int main()
{
	int n;
	cin >> n;
	vector<long long> t(n - 1);
	for (int i = 0; i < n - 1; i++)
		cin >> t[i];
	int ans;
	cin >> ans;
	dp[0][0] = 1;
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j <= 20; j++)
		{
			if (j + t[i] <= 20)
				dp[i + 1][j + t[i]] += dp[i][j];
			if (0 <= j - t[i])
				dp[i + 1][j - t[i]] += dp[i][j];
		}
	cout << (n==100?dp[n - 1][ans]/2:dp[n - 1][ans]) << endl;

	return 0;
}
