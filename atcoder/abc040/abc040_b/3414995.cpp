// URL: https://atcoder.jp/contests/abc040/submissions/3414995
// Date: Mon, 15 Oct 2018 23:49:54 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int ans = 1000000000;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j * i <= n; j++)
			ans = min(ans, abs(i - j) + n - i * j);
	cout << ans << endl;

	return 0;
}
