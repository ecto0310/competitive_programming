// URL: https://atcoder.jp/contests/abc060/submissions/3696085
// Date: Sat, 01 Dec 2018 21:02:01 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	string a, b, c;
	cin >> a >> b >> c;
	cout << (a[a.size() - 1] == b[0] && b[b.size() - 1] == c[0] ? "YES" : "NO") << endl;

	return 0;
}
