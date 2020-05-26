// URL: https://atcoder.jp/contests/abc092/submissions/2372527
// Date: Tue, 17 Apr 2018 21:23:54 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, d, x;
	int a[100];
	cin >> n >> d >> x;
	for( int i = 0; i < n; i++ )cin >> a[i];
	for( int i = 0; i < n; i++ )x += 1 + ( d - 1 ) / a[i];
	cout << x << endl;

	return 0;
}
