// URL: https://atcoder.jp/contests/abc064/submissions/2811536
// Date: Sun, 08 Jul 2018 01:03:31 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int r, g, b;
	cin >> r >> g >> b;
	if ((100 * r + 10 * g + b) % 4 == 0)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}
