// URL: https://atcoder.jp/contests/agc023/submissions/2429282
// Date: Sat, 28 Apr 2018 21:57:28 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int a[200000];
long long sum[200002];


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	map<long long, unsigned long long> m;
	vector<long long> v;
	for( int i = 0; i < n; i++ )cin >> a[i];
	sum[0] = 0;
	m[0]++;
	unsigned long long ret = 0;
	for( int i = 0; i < n; i++ )
	{
		sum[i + 1] = sum[i] + a[i];
		m[sum[i + 1]]++;
		if( m[sum[i + 1]] == 2 )v.push_back(sum[i + 1]);
	}
	for( int i = 0; i < v.size(); i++ )ret += m[v[i]] * ( m[v[i]] - 1 );
	cout << ret / 2 << endl;

	return 0;
}
