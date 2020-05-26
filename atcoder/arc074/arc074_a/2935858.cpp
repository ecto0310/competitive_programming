// URL: https://atcoder.jp/contests/arc074/submissions/2935858
// Date: Fri, 03 Aug 2018 00:29:10 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int h, w;
	cin >> h >> w;
	long long ans = 1e10;
	if (h % 3 == 0)
		ans = 0;
	else
		ans = min(ans, (long long)w);
	if (w % 3 == 0)
		ans = 0;
	else
		ans = min(ans, (long long)h);
	for (int i = 0; i <= h; i++)
	{
		long long a = (long long)(i)*w, b = (long long)(h - i) * (w / 2), c = (long long)(h - i) * (w - w / 2);
		ans = min(ans, max({a, b, c}) - min({a, b, c}));
	}
	for (int i = 0; i <= w; i++)
	{
		long long a = (long long)(i)*h, b = (long long)(w - i) * (h / 2), c = (long long)(w - i) * (h - h / 2);
		ans = min(ans, max({a, b, c}) - min({a, b, c}));
	}
	cout << ans << endl;

	return 0;
}
