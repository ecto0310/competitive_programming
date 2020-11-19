// URL: https://atcoder.jp/contests/ddcc2019-qual/submissions/3647788
// Date: Fri, 23 Nov 2018 21:43:16 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

const int mod = 1000000007;

long long _pow(long long x, long long p)
{
	long long ret = 1;
	for (int i = 0; i < p; i++)
		ret = ret * x % mod;
	return ret % mod;
}

int main()
{
	int n;
	cin >> n;
	long long ans = 0;
	for (int maxp = 1; maxp <= n; maxp++)
	{
		long long maxq = n / maxp;
		long long cntp = (_pow(maxp, 10) + mod - _pow(maxp - 1, 10))%mod, cntq = _pow(maxq, 10);
		ans = (ans + (cntp * cntq % mod)) % mod;
	}
	cout << ans % mod << endl;

	return 0;
}
