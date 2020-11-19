// URL: https://atcoder.jp/contests/arc071/submissions/2920900
// Date: Mon, 30 Jul 2018 00:11:52 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

long long x[100000], y[100000];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> x[i];
	for (int i = 0; i < m; i++)
		cin >> y[i];
	long long xs = 0, ys = 0;
	for (int i = 0; i < n; i++)
		xs += x[i] * (i - (n - i - 1));
	for (int i = 0; i < m; i++)
		ys += y[i] * (i - (m - i - 1));
	cout << (xs % 1000000007) * (ys % 1000000007) % 1000000007 << endl;

	return 0;
}
