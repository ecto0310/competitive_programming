// URL: https://atcoder.jp/contests/abc024/submissions/2860519
// Date: Tue, 17 Jul 2018 21:49:56 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int a, b, c, k, s, t;
	cin >> a >> b >> c >> k >> s >> t;
	cout << a * s + b * t - (s + t < k ? 0 : c * (s + t)) << endl;

	return 0;
}
