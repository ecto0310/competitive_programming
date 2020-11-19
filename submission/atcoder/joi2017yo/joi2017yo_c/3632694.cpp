// URL: https://atcoder.jp/contests/joi2017yo/submissions/3632694
// Date: Wed, 21 Nov 2018 01:11:38 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n, m, d;
	cin >> n >> m >> d;
	vector<string> s(n);
	for (int i = 0; i < n; i++)
		cin >> s[i];
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (s[i][j] == '.')
			{
				if (i <= n - d)
				{
					bool ok = true;
					for (int k = 0; k < d; k++)
						if (s[i + k][j] == '#')
							ok = false;
					if (ok)
						ans++;
				}
				if (j <= m - d)
				{
					bool ok = true;
					for (int k = 0; k < d; k++)
						if (s[i][j + k] == '#')
							ok = false;
					if (ok)
						ans++;
				}
			}
	cout << ans << endl;

	return 0;
}
