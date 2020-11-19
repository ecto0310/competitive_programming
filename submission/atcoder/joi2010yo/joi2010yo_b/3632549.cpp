// URL: https://atcoder.jp/contests/joi2010yo/submissions/3632549
// Date: Wed, 21 Nov 2018 00:23:19 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> s(n), d(m);
	for (int i = 0; i < n; i++)
		cin >> s[i];
	for (int i = 0; i < m; i++)
		cin >> d[i];
	int now = 1;
	for (int i = 0; i < m; i++)
	{
		now += d[i];
		now += s[now - 1];
		if (now >= n)
		{
			cout << i + 1 << endl;
			return 0;
		}
		cerr << now << endl;
	}

	return 0;
}
