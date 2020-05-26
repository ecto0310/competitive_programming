// URL: https://atcoder.jp/contests/abc018/submissions/2860552
// Date: Tue, 17 Jul 2018 21:57:11 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	if (max({a, b, c}) == a)
		cout << 1 << endl;
	else if (min({a, b, c}) == a)
		cout << 3 << endl;
	else
		cout << 2 << endl;
	if (max({a, b, c}) == b)
		cout << 1 << endl;
	else if (min({a, b, c}) == b)
		cout << 3 << endl;
	else
		cout << 2 << endl;
	if (max({a, b, c}) == c)
		cout << 1 << endl;
	else if (min({a, b, c}) == c)
		cout << 3 << endl;
	else
		cout << 2 << endl;
	return 0;
}
