// URL: https://atcoder.jp/contests/abc050/submissions/2818908
// Date: Mon, 09 Jul 2018 22:37:00 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int a, b;
	string op;
	cin >> a >> op >> b;
	if (op == "+")
		cout << a + b << endl;
	else
		cout << a - b << endl;

	return 0;
}
