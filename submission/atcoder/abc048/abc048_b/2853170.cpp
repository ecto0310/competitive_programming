// URL: https://atcoder.jp/contests/abc048/submissions/2853170
// Date: Sun, 15 Jul 2018 23:28:05 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	long long a, b, x;
	cin >> a >> b >> x;
	cout << b / x + 1 - (a == 0 ? 0 : (a - 1) / x + 1) << endl;

	return 0;
}
