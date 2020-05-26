// URL: https://atcoder.jp/contests/abc113/submissions/3533644
// Date: Sun, 04 Nov 2018 21:08:39 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n, t, a, h;
	cin >> n >> t >> a;
	int ans = -1;
	double def = 1000000;
	for (int i = 0; i < n; i++)
	{
		cin >> h;
		if (def > abs((double)t - h * 0.006 - a))
		{
			ans = i + 1;
			def = abs((double)t - h * 0.006 - a);
		}
	}
	cout << ans << endl;

	return 0;
}
