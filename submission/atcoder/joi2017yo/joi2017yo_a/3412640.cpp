// URL: https://atcoder.jp/contests/joi2017yo/submissions/3412640
// Date: Mon, 15 Oct 2018 16:59:29 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	if (a < 0)
		cout << abs(a) * c + d + b * e << endl;
	else
		cout << (b - a) * e << endl;

	return 0;
}
