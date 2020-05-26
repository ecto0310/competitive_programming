// URL: https://atcoder.jp/contests/dp/submissions/3937575
// Date: Sun, 06 Jan 2019 20:17:50 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int dp[100000][3];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (i == 0)
		{
			dp[i][0] = a;
			dp[i][1] = b;
			dp[i][2] = c;
		}
		else
			for (int j = 0; j < 3; j++)
				for (int k = 0; k < 3; k++)
					if (j != k)
						dp[i][j] = max(dp[i][j], dp[i - 1][k] + (j == 0 ? a : (j == 1 ? b : c)));
	}
	cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});

	return 0;
}
