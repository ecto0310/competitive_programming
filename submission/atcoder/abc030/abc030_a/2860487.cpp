// URL: https://atcoder.jp/contests/abc030/submissions/2860487
// Date: Tue, 17 Jul 2018 21:42:24 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if ((double)b / a > (double)d / c)
		cout << "TAKAHASHI" << endl;
	else if ((double)b / a < (double)d / c)
		cout << "AOKI" << endl;
	else
		cout << "DRAW" << endl;

	return 0;
}
