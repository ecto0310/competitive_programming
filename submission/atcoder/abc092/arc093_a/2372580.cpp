// URL: https://atcoder.jp/contests/abc092/submissions/2372580
// Date: Tue, 17 Apr 2018 21:34:47 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int a[100000];
int sum[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for( int i = 0; i < n; i++ )cin >> a[i];
	sum[0] = abs(a[0]);
	for( int i = 1; i < n; i++ )sum[i] = sum[i - 1] + abs(a[i] - a[i - 1]);
	sum[n] = sum[n - 1] + abs(a[n - 1]);
	for( int i = 0; i < n; i++ )
	{
		int ret = sum[n] - sum[i + 1];
		if( i == 0 )ret += abs(a[i + 1]);
		else ret += sum[i - 1] + abs(a[i + 1] - a[i - 1]);
		cout << ret << endl;
	}

	return 0;
}
