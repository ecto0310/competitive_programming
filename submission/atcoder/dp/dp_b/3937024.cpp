// URL: https://atcoder.jp/contests/dp/submissions/3937024
// Date: Sun, 06 Jan 2019 20:12:18 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

long long dp[100000];

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> h(n);
	for (int i = 0; i < n; i++)
		cin >> h[i];
	for (int i = 1; i < n; i++)
		dp[i] = 1e9;
	for (int i = 1; i < n; i++)
		for (int j = 1; j <= k && -1 < i - j; j++)
			dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
	cout << dp[n - 1] << endl;

	return 0;
}
