// URL: https://atcoder.jp/contests/abc038/submissions/2861264
// Date: Wed, 18 Jul 2018 00:56:41 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int h1, w1, h2, w2;
	cin >> h1 >> w1 >> h2 >> w2;
	if (h1 == h2 || h1 == w2 || w1 == h2 || w1 == w2)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}
