// URL: https://atcoder.jp/contests/abc075/submissions/3618652
// Date: Sat, 17 Nov 2018 22:48:40 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<long long> x(n), y(n);
	for (int i = 0; i < n; i++)
		cin >> x[i] >> y[i];
	long long ans = LLONG_MAX;
	for (int xt = 0; xt < n; xt++)
		for (int xu = 0; xu < n; xu++)
			for (int yl = 0; yl < n; yl++)
				for (int yr = 0; yr < n; yr++)
				{
					int cnt = 0;
					for (int i = 0; i < n; i++)
						if (x[xu] <= x[i] && x[i] <= x[xt] && y[yl] <= y[i] && y[i] <= y[yr])
							cnt++;
					if (k <= cnt)
						ans = min(ans, abs(x[xt] - x[xu]) * abs(y[yr] - y[yl]));
				}
	cout << ans << endl;

	return 0;
}
