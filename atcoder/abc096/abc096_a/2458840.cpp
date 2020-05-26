// URL: https://atcoder.jp/contests/abc096/submissions/2458840
// Date: Sat, 05 May 2018 21:01:49 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b;
	cin >> a >> b;
	cout << a - 1 + (a <= b ? 1 : 0) << endl;

	return 0;
}
