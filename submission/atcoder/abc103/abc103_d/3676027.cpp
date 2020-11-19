// URL: https://atcoder.jp/contests/abc103/submissions/3676027
// Date: Tue, 27 Nov 2018 17:44:35 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> b(m);
	for (int i = 0; i < m; i++)
		cin >> b[i].second >> b[i].first;
	sort(b.begin(), b.end());
	int ans = 0, c = 0;
	for (pair<int, int> t : b)
		if (c <= t.second)
		{
			c = t.first;
			ans++;
		}
	cout << ans << endl;

	return 0;
}
