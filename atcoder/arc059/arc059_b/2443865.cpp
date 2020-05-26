// URL: https://atcoder.jp/contests/arc059/submissions/2443865
// Date: Tue, 01 May 2018 22:34:18 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	int len = s.length();
	char b1 = s[0], b2 = {};
	for(int i = 1; i < len; i++)
	{
		if(b1 == s[i])
		{
			cout << i << " " << i + 1 << endl;
			return 0;
		}
		else if(b2==s[i])
		{
			cout << i - 1 << " " << i + 1 << endl;
			return 0;
		}
		b2 = b1;
		b1 = s[i];
	}
	cout << -1 << " " << -1 << endl;

	return 0;
}
