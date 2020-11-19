// URL: https://atcoder.jp/contests/arc082/submissions/3728020
// Date: Thu, 06 Dec 2018 21:22:25 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
#include <numeric>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> p(n + 1);
	for (int i = 0; i < n; i++)
		cin >> p[i];
	int ans = 0;
	for (int i = 0; i < n; i++)
		if (p[i] == i + 1)
		{
			swap(p[i], p[i + 1]);
			ans++;
		}
	cout << ans << endl;

	return 0;
}
