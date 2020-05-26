// URL: https://atcoder.jp/contests/arc069/submissions/3727983
// Date: Thu, 06 Dec 2018 21:18:03 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	long long n, m;
	cin >> n >> m;
	cout << min(n, m / 2) + (n < m / 2 ? (m - 2 * n) / 4 : 0) << endl;

	return 0;
}
