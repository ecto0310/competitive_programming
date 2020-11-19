// URL: https://atcoder.jp/contests/abc050/submissions/2853156
// Date: Sun, 15 Jul 2018 23:25:56 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n, t[100], m, p[100][2];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> t[i];
	cin >> m;
	for (int i = 0; i < m; i++)
		cin >> p[i][0] >> p[i][1];
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += t[i];
	for (int i = 0; i < m; i++)
		cout << sum - t[p[i][0] - 1] + p[i][1] << endl;

	return 0;
}
