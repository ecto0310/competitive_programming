// URL: https://atcoder.jp/contests/dp/submissions/3950071
// Date: Mon, 07 Jan 2019 00:41:03 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

long long dp[10001][2][100];

const int mod = 1e9 + 7;

int main()
{
	string k;
	int d;
	cin >> k >> d;
	int size = k.size();
	dp[0][0][0] = 1;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < 2; j++)
			for (int l = 0; l < d; l++)
				for (int n = 0; n <= (j == 0 ? k[i] - '0' : 9); n++)
					dp[i + 1][j || (n < k[i] - '0')][(l + n) % d] = (dp[i + 1][j || (n < k[i] - '0')][(l + n) % d] + dp[i][j][l]) % mod;
	cout << (-1<dp[size][0][0] + dp[size][1][0] - 1?dp[size][0][0] + dp[size][1][0] - 1:mod-1) % mod << endl;

	return 0;
}
