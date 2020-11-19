// URL: https://atcoder.jp/contests/joi2016yo/submissions/3691069
// Date: Sat, 01 Dec 2018 00:01:34 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	cout << a + b + c + d - min({a, b, c, d}) + e + f - min(e, f) << endl;

	return 0;
}
