// URL: https://atcoder.jp/contests/joi2019yo/submissions/3790286
// Date: Sat, 15 Dec 2018 13:48:01 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n, m;
	cin >> n;
	vector<int> x(n);
	for (int i = 0; i < n; i++)
		cin >> x[i];
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a;
		cin >> a;
		if (x[a - 1] == 2019)
			continue;
		bool ok = true;
		for (int i = 0; i < n; i++)
			if (x[a - 1] + 1 == x[i])
				ok = false;
		if (ok)
			x[a - 1]++;
	}
	for (int t : x)
		cout << t << endl;

	return 0;
}
