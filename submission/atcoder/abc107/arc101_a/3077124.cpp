// URL: https://atcoder.jp/contests/abc107/submissions/3077124
// Date: Sat, 25 Aug 2018 22:01:47 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> x(n);
	for (int i = 0; i < n; i++)
		cin >> x[i];
	int ans = (n == 1 ? abs(x[0]) : 1000000000);
	if (n == k)
	{
		int l = x[0], r = x[k - 1];
		if (l <= 0 && r <= 0)
			ans = min(ans, abs(min(l, r)));
		else if (0 <= l && 0 <= r)
			ans = min(ans, max(l, r));
		else
			ans = min({ans, abs(l) + abs(r * 2), abs(l * 2) + abs(r)});
	}
	for (int i = 0; i <= n - k; i++)
	{
		int l = x[i], r = x[i + k - 1];
		if (l <= 0 && r <= 0)
			ans = min(ans, abs(min(l, r)));
		else if (0 <= l && 0 <= r)
			ans = min(ans, max(l, r));
		else
			ans = min({ans, abs(l) + abs(r * 2), abs(l * 2) + abs(r)});
	}
	cout << ans << endl;

	return 0;
}
