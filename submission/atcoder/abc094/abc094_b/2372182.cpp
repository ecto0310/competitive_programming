// URL: https://atcoder.jp/contests/abc094/submissions/2372182
// Date: Tue, 17 Apr 2018 20:00:24 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, x;
	int a[100];
	cin >> n >> m >> x;
	for( int i = 0; i < m; i++ )cin >> a[i];
	for( int i = 0; i < m; i++ )
	{
		if( a[i] > x )
		{
			cout << min(i, m - i) << endl;
			break;
		}
	}

	return 0;
}
