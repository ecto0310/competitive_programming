// URL: https://atcoder.jp/contests/dp/submissions/3936149
// Date: Sun, 06 Jan 2019 20:04:01 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int dp[100000];

int main()
{
	int n;
	cin >> n;
	vector<int> h(n);
	for (int i = 0; i < n; i++)
		cin >> h[i];
	for (int i = 1; i < n; i++)
		if (i == 1)
			dp[i] = abs(h[i] - h[i - 1]);
		else
			dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
	cout << dp[n - 1] << endl;

	return 0;
}
