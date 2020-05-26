// URL: https://atcoder.jp/contests/s8pc-5/submissions/2362633
// Date: Sun, 15 Apr 2018 20:19:31 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
	int N, T;
	int a[100];
	cin >> N >> T;
	for( int i = 0; i < N; i++ )cin >> a[i];

	int ret = a[0];
	for( int i = 1; i < N; i++ )
	{
		ret = ( ret <= ret / T * T + a[i] ? ret / T * T + a[i] : ( ret / T + 1 )* T + a[i] );
	}
	cout << ret << endl;

	return 0;
}
