// URL: https://atcoder.jp/contests/abc008/submissions/3600440
// Date: Wed, 14 Nov 2018 23:48:39 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	map<string, int> m;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		m[s]++;
	}
	int ma = 0;
	string ans;
	for (pair<string, int> t : m)
		if (ma < t.second)
		{
			ma = t.second;
			ans = t.first;
		}
	cout << ans << endl;

	return 0;
}
