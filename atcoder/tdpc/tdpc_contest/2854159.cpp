// URL: https://atcoder.jp/contests/tdpc/submissions/2854159
// Date: Mon, 16 Jul 2018 10:46:31 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

bool dp[101][10001];

int main()
{
	int n, p[100];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> p[i];
	dp[0][0] = true;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 10001; j++)
			if (dp[i][j])
			{
				dp[i + 1][j] = true;
				dp[i + 1][j + p[i]] = true;
			}
	int ans = 0;
	for (int i = 0; i < 10001; i++)
		if (dp[n][i])
			ans++;
	cout << ans << endl;

	return 0;
}
