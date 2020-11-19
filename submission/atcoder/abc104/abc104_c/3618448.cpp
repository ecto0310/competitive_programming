// URL: https://atcoder.jp/contests/abc104/submissions/3618448
// Date: Sat, 17 Nov 2018 22:16:48 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int d, g;
	cin >> d >> g;
	vector<int> p(d), c(d);
	for (int i = 0; i < d; i++)
		cin >> p[i] >> c[i];
	int ans = 1e9;
	for (int i = 0; i < (1 << d); i++)
	{
		int sum = 0, cnt = 0, m = -1;
		for (int j = 0; j < d; j++)
			if (i >> j & 1)
			{
				sum += 100 * (j + 1) * p[j] + c[j];
				cnt += p[j];
			}
			else
				m = max(m, j);
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
