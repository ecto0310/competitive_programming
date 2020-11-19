// URL: https://atcoder.jp/contests/abc051/submissions/2853097
// Date: Sun, 15 Jul 2018 23:12:19 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int k, s;
	cin >> k >> s;
	int ans = 0;
	for (int x = 0; x <= k; x++)
		for (int y = 0; y <= k; y++)
			if (0 <= s - x - y && s - x - y <= k)
				ans++;
	cout << ans << endl;

	return 0;
}
