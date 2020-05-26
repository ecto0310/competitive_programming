// URL: https://atcoder.jp/contests/abc108/submissions/3118609
// Date: Sat, 01 Sep 2018 22:17:30 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	map<int, long long> m;
	long long ans = 0;
	for (int i = 1; i <= n; i++)
		m[i % k]++;
	for (int a = 0; a < k; a++)
		if (2 * a % k == 0)
			ans += m[a] * m[a] * m[(k - a) % k];
	cout << ans << endl;

	return 0;
}
