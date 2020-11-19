// URL: https://atcoder.jp/contests/abc061/submissions/2814540
// Date: Sun, 08 Jul 2018 20:04:27 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	if (a <= c && c <= b)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}
