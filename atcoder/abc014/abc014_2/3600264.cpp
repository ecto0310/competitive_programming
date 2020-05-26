// URL: https://atcoder.jp/contests/abc014/submissions/3600264
// Date: Wed, 14 Nov 2018 23:12:58 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n, x;
	cin >> n >> x;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		if (x >> i & 1)
			ans += a;
	}
	cout << ans << endl;

	return 0;
}
