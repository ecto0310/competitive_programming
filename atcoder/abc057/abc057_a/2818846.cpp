// URL: https://atcoder.jp/contests/abc057/submissions/2818846
// Date: Mon, 09 Jul 2018 22:25:43 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	if (a + b < 24)
		cout << a + b << endl;
	else
		cout << a + b - 24 << endl;

	return 0;
}
