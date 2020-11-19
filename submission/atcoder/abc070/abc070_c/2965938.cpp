// URL: https://atcoder.jp/contests/abc070/submissions/2965938
// Date: Tue, 07 Aug 2018 00:40:07 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
#include <numeric>

using namespace std;

long long gcd(long long a, long long b)
{
	return (b == 0 ? a : gcd(b, a % b));
}

long long lcm(long long a, long long b)
{
	return a / gcd(a, b) * b;
}

int main()
{
	int n;
	cin >> n;
	long long ans = 1;
	for (int i = 0; i < n; i++)
	{
		long long t;
		cin >> t;
		ans = lcm(ans, t);
	}
	cout << ans << endl;

	return 0;
}
