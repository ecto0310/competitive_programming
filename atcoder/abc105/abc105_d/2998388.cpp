// URL: https://atcoder.jp/contests/abc105/submissions/2998388
// Date: Sun, 12 Aug 2018 19:38:16 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	long long ans = 0, sum = 0;
	map<long long, long long> ma;
	ma[0] = 1;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		sum = (sum + a) % m;
		ans += ma[sum]++;
	}
	cout << ans << endl;

	return 0;
}
