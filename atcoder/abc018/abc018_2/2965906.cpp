// URL: https://atcoder.jp/contests/abc018/submissions/2965906
// Date: Tue, 07 Aug 2018 00:28:41 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	string s;
	int n;
	cin >> s >> n;
	for (int i = 0; i < n; i++)
	{
		int l, r;
		cin >> l >> r;
		reverse(s.begin() + l - 1, s.begin() + r);
	}
	cout << s << endl;

	return 0;
}
