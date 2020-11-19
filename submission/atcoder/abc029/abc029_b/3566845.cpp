// URL: https://atcoder.jp/contests/abc029/submissions/3566845
// Date: Fri, 09 Nov 2018 11:17:04 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int ans = 0;
	for (int i = 0; i < 12; i++)
	{
		string s;
		cin >> s;
		if (find(s.begin(), s.end(), 'r') != s.end())
			ans++;
	}
	cout << ans << endl;

	return 0;
}
