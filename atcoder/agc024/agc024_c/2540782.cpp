// URL: https://atcoder.jp/contests/agc024/submissions/2540782
// Date: Sun, 20 May 2018 23:08:27 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>
#include<assert.h>

using namespace std;

long long a[200000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for(int i = 0; i < n; i++)cin >> a[i];
	long long ret = a[n - 1];
	bool ok = true;
	if(a[0] != 0)ok = false;
	for(int i = 1; i < n; i++)
	{
		if(a[i] - a[i - 1] > 1)ok = false;
		if(a[i] <= a[i - 1])ret += a[i - 1];
	}
	if(ok)cout << ret << endl;
	else cout << -1 << endl;

	return 0;
}
