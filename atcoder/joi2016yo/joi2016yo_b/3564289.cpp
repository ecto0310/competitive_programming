// URL: https://atcoder.jp/contests/joi2016yo/submissions/3564289
// Date: Thu, 08 Nov 2018 20:41:07 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	for (int i = 1; i <= m; i++)
		for (int j = 0; j < n - 1; j++)
			if (v[j] % i > v[j + 1] % i)
				swap(v[j], v[j + 1]);
	for (int i = 0; i < n; i++)
		cout << v[i] << endl;

	return 0;
}
