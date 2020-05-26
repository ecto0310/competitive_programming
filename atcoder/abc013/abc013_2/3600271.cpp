// URL: https://atcoder.jp/contests/abc013/submissions/3600271
// Date: Wed, 14 Nov 2018 23:14:39 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	cout << min(abs(a - b), abs(10 - abs(a - b))) << endl;

	return 0;
}
