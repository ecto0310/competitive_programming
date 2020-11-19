// URL: https://atcoder.jp/contests/joi2010yo/submissions/3713853
// Date: Tue, 04 Dec 2018 01:25:44 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int n, k;

set<string> se;
vector<string> s;

int dfs(string now, int cnt, vector<bool> use = vector<bool>(n, false))
{
	if (cnt == k)
	{
		se.insert(now);
		return 0;
	}
	for (int i = 0; i < s.size(); i++)
		if (!use[i])
		{
			use[i] = true;
			dfs(now + s[i], cnt + 1, use);
			use[i] = false;
		}
	return 0;
}

int main()
{
	cin >> n >> k;
	s.resize(n);
	for (int i = 0; i < n; i++)
		cin >> s[i];
	dfs("", 0);
	cout << se.size() << endl;

	return 0;
}
