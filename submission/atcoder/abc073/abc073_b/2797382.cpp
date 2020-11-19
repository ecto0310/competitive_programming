// URL: https://atcoder.jp/contests/abc073/submissions/2797382
// Date: Fri, 06 Jul 2018 21:34:07 +0900
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
		int l, r;
		cin >> l >> r;
		ans += r - l + 1;
	}
	cout << ans << endl;

	return 0;
}
