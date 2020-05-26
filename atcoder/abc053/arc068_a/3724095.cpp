// URL: https://atcoder.jp/contests/abc053/submissions/3724095
// Date: Thu, 06 Dec 2018 02:04:10 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	long long n;
	cin >> n;
	cout << 2 * (n / 11) + (6 < n % 11 ? 1 : 0) + (0 < n % 11 ? 1 : 0) << endl;

	return 0;
}
