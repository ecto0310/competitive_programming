// URL: https://atcoder.jp/contests/agc028/submissions/3421215
// Date: Wed, 17 Oct 2018 14:51:32 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	long long n, m;
	string s, t;
	cin >> n >> m >> s >> t;
	long long ans = n / __gcd(n, m) * m;
	bool ok = true;
	for (int i = 0; i < __gcd(n, m); i++)
		if (s[ans / m * i] != t[ans / n * i])
			ok = false;
	if (ok)
		cout << ans << endl;
	else
		cout << -1 << endl;

	return 0;
}
