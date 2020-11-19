// URL: https://atcoder.jp/contests/joi2007yo/submissions/3632442
// Date: Tue, 20 Nov 2018 23:56:02 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> c(2 * n);
	for (int i = 0; i < 2 * n; i++)
		c[i] = i + 1;
	while (m--)
	{
		int k;
		cin >> k;
		if (k == 0)
		{
			vector<int> a(n), b(n);
			for (int i = 0; i < n; i++)
				a[i] = c[i];
			for (int i = 0; i < n; i++)
				b[i] = c[n + i];
			for (int i = 0; i < n; i++)
			{
				c[i * 2] = a[i];
				c[i * 2 + 1] = b[i];
			}
		}
		else
		{
			vector<int> a(k);
			for (int i = 0; i < k; i++)
				a[i] = c[i];
			for (int i = 0; i < 2 * n - k; i++)
				c[i] = c[k + i];
			for (int i = 0; i < k; i++)
				c[2 * n - k + i] = a[i];
		}
	}
	for (int i = 0; i < 2 * n; i++)
		cout << c[i] << endl;

	return 0;
}
