// URL: https://atcoder.jp/contests/abc101/submissions/2722733
// Date: Sat, 23 Jun 2018 21:21:13 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	int ans = 0;
	while (n > 0)
	{
		ans++;
		n -= k - 1;
		if (n == 1)
			break;
	}
	cout << ans << endl;

	return 0;
}
