// URL: https://atcoder.jp/contests/abc093/submissions/2372458
// Date: Tue, 17 Apr 2018 21:09:16 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, k;
	cin >> a >> b >> k;
	for( int i = a; i <= min(a + k - 1, b - k); i++ )cout << i << endl;
	for( int i = max(b - k + 1, a); i <= b; i++ )cout << i << endl;

	return 0;
}
