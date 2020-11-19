// URL: https://atcoder.jp/contests/abc114/submissions/3708901
// Date: Mon, 03 Dec 2018 00:49:20 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int n;
int pri[101][101], p[101] = {};

int creat(int t)
{
	int p = 2, i = t;
	while (i >= p * p)
		if (i % p == 0)
		{
			pri[t][p]++;
			i /= p;
		}
		else
			p++;
	pri[t][i]++;
	return 0;
}

int cnt(int t)
{
	int ret = 0;
	for (int i = 0; i <= 100; i++)
		if (t - 1 <= p[i])
			ret++;
	return ret;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		creat(i);
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= 100; j++)
			p[j] += pri[i][j];
	cout << cnt(75) + cnt(25) * (cnt(3) - 1) + cnt(15) * (cnt(5) - 1) + cnt(5) * (cnt(5) - 1) * (cnt(3) - 2) / 2 << endl;

	return 0;
}
