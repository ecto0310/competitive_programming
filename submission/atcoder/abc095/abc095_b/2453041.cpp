// URL: https://atcoder.jp/contests/abc095/submissions/2453041
// Date: Fri, 04 May 2018 13:51:29 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, x;
	int m[100];
	cin >> n >> x;
	for(int i = 0; i < n; i++)cin >> m[i];
	int ret = n, mi = 1000;
	for(int i = 0; i < n; i++)
	{
		x -= m[i];
		mi = min(mi, m[i]);
	}
	ret += x / mi;
	cout << ret << endl;

	return 0;
}
