// URL: https://atcoder.jp/contests/code-festival-2017-qualb/submissions/3720812
// Date: Wed, 05 Dec 2018 15:42:51 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	map<int, int> w;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		w[tmp]++;
	}
	bool ok = true;
	int m;
	cin >> m;
	map<int, int> q;
	for (int i = 0; i < m; i++)
	{
		int tmp;
		cin >> tmp;
		q[tmp]++;
		if (w[tmp] < q[tmp])
			ok = false;
	}
	cout << (ok ? "YES" : "NO") << endl;

	return 0;
}
