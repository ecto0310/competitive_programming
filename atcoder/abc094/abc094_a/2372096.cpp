// URL: https://atcoder.jp/contests/abc094/submissions/2372096
// Date: Tue, 17 Apr 2018 19:39:51 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, x;
	cin >> a >> b >> x;
	if( a <= x && a + b >= x )cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}
