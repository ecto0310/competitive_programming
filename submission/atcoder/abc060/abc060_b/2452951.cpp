// URL: https://atcoder.jp/contests/abc060/submissions/2452951
// Date: Fri, 04 May 2018 13:37:20 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, c;
	cin >> a >> b >> c;
	set<int> s;
	int now = a;
	while(s.count(now%b) == 0)
	{
		if(now%b == c)
		{
			cout << "YES" << endl;
			return 0;
		}
		s.insert(now%b);
		now += a;
	}
	cout << "NO" << endl;

	return 0;
}
