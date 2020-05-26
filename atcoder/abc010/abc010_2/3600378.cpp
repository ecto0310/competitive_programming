// URL: https://atcoder.jp/contests/abc010/submissions/3600378
// Date: Wed, 14 Nov 2018 23:36:29 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		for (; a % 2 == 0 || a % 3 == 2; a--)
			ans++;
	}
	cout << ans << endl;

	return 0;
}
