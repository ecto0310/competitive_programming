// URL: https://atcoder.jp/contests/agc023/submissions/2432028
// Date: Sat, 28 Apr 2018 23:27:30 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	string s[300];
	cin >> n;
	for( int i = 0; i < n; i++ )cin >> s[i];
	int ret = 0;
	for( int mx = 0; mx < n; mx++ )
	{
		bool ok = true;
		for( int x = 0; x < n; x++ )
			for( int y = 0; y < n; y++ )
			{
				if( s[( x + mx ) % n][y] != s[( y + mx ) % n][x] )ok = false;
			}
		if( ok )ret++;
	}
	cout << ret * n << endl;

	return 0;
}
