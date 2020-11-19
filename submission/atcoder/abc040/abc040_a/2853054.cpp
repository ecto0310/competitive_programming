// URL: https://atcoder.jp/contests/abc040/submissions/2853054
// Date: Sun, 15 Jul 2018 23:02:29 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n, x;
	cin >> n >> x;
	cout << min(n - x, x - 1) << endl;

	return 0;
}
