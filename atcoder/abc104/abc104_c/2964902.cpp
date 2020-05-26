// URL: https://atcoder.jp/contests/abc104/submissions/2964902
// Date: Mon, 06 Aug 2018 21:00:00 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int d, g, p[10], c[10];
	cin >> d >> g;
	for (int i = 0; i < d; i++)
		cin >> p[i] >> c[i];
	int ans = 1000;
	for (int bit = 0; bit < (1 << d); bit++)
	{
		int sum = 0, cnt = 0, m = -1;
		for (int i = 0; i < d; i++)
		{
			if (bit >> i & 1)
			{
				sum += 100 * (i + 1) * p[i] + c[i];
				cnt += p[i];
			}
			else
				m = max(m, i);
		}
		if (sum < g)
			if ((g - sum + 100 * (m + 1) - 1) / (100 * (m + 1)) < p[m])
				cnt += (g - sum + 100 * (m + 1) - 1) / (100 * (m + 1));
			else
				continue;
		ans = min(ans, cnt);
	}
	cout << ans << endl;

	return 0;
}
