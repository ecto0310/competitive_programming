// URL: https://atcoder.jp/contests/abc091/submissions/2376584
// Date: Wed, 18 Apr 2018 23:13:01 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	string s[100], t[100];
	cin >> n;
	for(int i = 0; i < n; i++)cin >> s[i];
	cin >> m;
	for(int i = 0; i < m; i++)cin >> t[i];
	int ret = 0;
	for(int i = 0; i < n; i++)
	{
		int tmp = 0;
		for(int j = i; j < n; j++)
		{
			if(s[j] == s[i])tmp++;
		}
		for(int j = 0; j < m; j++)
		{
			if(t[j] == s[i])tmp--;
		}
		ret = max(ret, tmp);
	}
	cout << ret << endl;

return 0;
}
