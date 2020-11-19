// URL: https://atcoder.jp/contests/joi2016yo/submissions/3605827
// Date: Fri, 16 Nov 2018 09:01:23 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<string> c(n);
	for (int i = 0; i < n; i++)
		cin >> c[i];
	int ans = 1e9;
	for (int w = 1; w < n; w++)
		for (int b = 1; b < n - w; b++)
		{
			int r = n - w - b;
			cerr << w << " " << b << " " << r << endl;
			int cnt = 0;
			for (int i = 0; i < w; i++)
				for (int j = 0; j < m; j++)
					if (c[i][j] != 'W')
						cnt++;
			for (int i = w; i < b + w; i++)
				for (int j = 0; j < m; j++)
					if (c[i][j] != 'B')
						cnt++;
			for (int i = w + b; i < n; i++)
				for (int j = 0; j < m; j++)
					if (c[i][j] != 'R')
						cnt++;
			ans = min(ans, cnt);
		}
	cout << ans << endl;

	return 0;
}
