// URL: https://atcoder.jp/contests/abc074/submissions/2670428
// Date: Fri, 15 Jun 2018 20:37:46 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>
#include<assert.h>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		ans += 2 * min(x, k - x);
	}
	cout << ans << endl;

	return 0;
}
