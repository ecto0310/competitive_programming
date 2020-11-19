// URL: https://atcoder.jp/contests/joi2015yo/submissions/3564163
// Date: Thu, 08 Nov 2018 20:16:36 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> a(m);
	for (int i = 0; i < m; i++)
		cin >> a[i];
	vector<int> ans(n);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			int b;
			cin >> b;
			if (b == a[i])
				ans[j]++;
			else
				ans[a[i] - 1]++;
		}
	for (int i = 0; i < n; i++)
		cout << ans[i] << endl;

	return 0;
}
