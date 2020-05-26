// URL: https://atcoder.jp/contests/joi2013yo/submissions/3404461
// Date: Sun, 14 Oct 2018 18:27:33 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int l, a, b, c, d;
	cin >> l >> a >> b >> c >> d;
	cout << l - max((a + c - 1) / c, (b + d - 1) / d) << endl;

	return 0;
}
