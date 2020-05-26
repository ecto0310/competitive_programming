// URL: https://atcoder.jp/contests/arc079/submissions/2452991
// Date: Fri, 04 May 2018 13:42:58 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int a[200000], b[200000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++)cin >> a[i] >> b[i];
	set<int> s;
	for(int i = 0; i < m; i++)
	{
		if(a[i] == 1)s.insert(b[i]);
	}
	for(int i = 0; i < m; i++)
	{
		if(b[i] == n && s.count(a[i]) == 1)
		{
			cout << "POSSIBLE" << endl;
			return 0;
		}
	}
	cout << "IMPOSSIBLE" << endl;

	return 0;
}
