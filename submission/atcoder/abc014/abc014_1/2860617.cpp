// URL: https://atcoder.jp/contests/abc014/submissions/2860617
// Date: Tue, 17 Jul 2018 22:09:14 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	cout << (a % b == 0 ? 0 : b - a % b) << endl;

	return 0;
}
