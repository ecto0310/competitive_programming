// URL: https://atcoder.jp/contests/joi2017ho/submissions/3818724
// Date: Tue, 18 Dec 2018 17:12:53 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n, q, s, t;
	cin >> n >> q >> s >> t;
	s *= -1;
	t *= -1;
	vector<long long> a(n + 1), dif(n);
	for (int i = 0; i < n + 1; i++)
		cin >> a[i];
	long long ans = 0;
	for (int i = 0; i < n; i++)
	{
		dif[i] = a[i + 1] - a[i];
		if (0 < dif[i])
			ans += dif[i] * s;
		else
			ans += dif[i] * t;
	}
	while (q--)
	{
		int l, r, x;
		cin >> l >> r >> x;
		if (0 < dif[l - 1])
			ans -= dif[l - 1] * s;
		else
			ans -= dif[l - 1] * t;
		dif[l - 1] += x;
		if (0 < dif[l - 1])
			ans += dif[l - 1] * s;
		else
			ans += dif[l - 1] * t;
		if (r != n)
		{

			if (0 < dif[r])
				ans -= dif[r] * s;
			else
				ans -= dif[r] * t;
			dif[r] -= x;
			if (0 < dif[r])
				ans += dif[r] * s;
			else
				ans += dif[r] * t;
		}
		cout << ans << endl;
	}

	return 0;
}
