// URL: https://atcoder.jp/contests/joi2016yo/submissions/3691090
// Date: Sat, 01 Dec 2018 00:05:55 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int ba = 1; ba < m + 1; ba++)
		for (int i = 0; i < n - 1; i++)
			if (a[i + 1] % ba < a[i] % ba)
				swap(a[i], a[i + 1]);
	for (int i = 0; i < n; i++)
		cout << a[i] << endl;

	return 0;
}
