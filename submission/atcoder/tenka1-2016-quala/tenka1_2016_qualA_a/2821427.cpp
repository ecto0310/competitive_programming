// URL: https://atcoder.jp/contests/tenka1-2016-quala/submissions/2821427
// Date: Tue, 10 Jul 2018 16:55:50 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int ans = 0;
	for (int i = 0; i < 101; i++)
		if (i % 3 != 0 && i % 5 != 0)
			ans += i;
	cout << ans << endl;

	return 0;
}
