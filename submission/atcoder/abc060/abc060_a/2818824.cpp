// URL: https://atcoder.jp/contests/abc060/submissions/2818824
// Date: Mon, 09 Jul 2018 22:20:56 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	string a, b, c;
	cin >> a >> b >> c;
	if (a[a.size() - 1] == b[0] && b[b.size() - 1] == c[0])
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}
