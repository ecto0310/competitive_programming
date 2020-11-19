// URL: https://atcoder.jp/contests/joi2016yo/submissions/3691164
// Date: Sat, 01 Dec 2018 00:19:11 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	for (int i = 0; i < n; i++)
		cin >> s[i];
	int ans = 100000;
	for (int w = 1; w < n; w++)
		for (int b = w + 1; b < n; b++)
		{
			if (b - w < 1 && n - b < 1)
				continue;
			int cnt = 0;
			for (int i = 0; i < w; i++)
				for (int j = 0; j < m; j++)
					if (s[i][j] != 'W')
						cnt++;
			for (int i = w; i < b; i++)
				for (int j = 0; j < m; j++)
					if (s[i][j] != 'B')
						cnt++;
			for (int i = b; i < n; i++)
				for (int j = 0; j < m; j++)
					if (s[i][j] != 'R')
						cnt++;
			ans = min(ans, cnt);
		}
	cout << ans << endl;

	return 0;
}
