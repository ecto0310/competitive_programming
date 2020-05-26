// URL: https://atcoder.jp/contests/abc096/submissions/2460595
// Date: Sat, 05 May 2018 21:07:34 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, c, k;
	cin >> a >> b >> c >> k;
	cout << a + b + c + max({a,b,c})*(pow(2, k)-1) << endl;

	return 0;
}
