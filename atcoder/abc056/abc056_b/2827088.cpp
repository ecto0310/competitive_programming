// URL: https://atcoder.jp/contests/abc056/submissions/2827088
// Date: Thu, 12 Jul 2018 00:06:49 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int w, a, b;
	cin >> w >> a >> b;
	if (abs(a - b) <= w)
		cout << 0 << endl;
	else
		cout << abs(a - b) - w << endl;

	return 0;
}
