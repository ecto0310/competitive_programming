// URL: https://atcoder.jp/contests/agc004/submissions/3410427
// Date: Mon, 15 Oct 2018 00:22:27 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	long long a, b, c;
	cin >> a >> b >> c;
	if (a % 2 == 0 || b % 2 == 0 || c % 2 == 0)
		cout << 0 << endl;
	else
		cout << min({a * b, b * c, c * a}) << endl;

	return 0;
}
