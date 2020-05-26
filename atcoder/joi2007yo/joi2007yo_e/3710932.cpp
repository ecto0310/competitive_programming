// URL: https://atcoder.jp/contests/joi2007yo/submissions/3710932
// Date: Mon, 03 Dec 2018 15:07:21 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

struct data
{
	int a, b, c;
};

int main()
{
	int a, b, c, n;
	cin >> a >> b >> c >> n;
	vector<data> ok, bad;
	for (int l = 0; l < n; l++)
	{
		int i, j, k, r;
		cin >> i >> j >> k >> r;
		if (r == 1)
			ok.push_back({i, j, k});
		else
			bad.push_back({i, j, k});
	}
	vector<int> ans(a + b + c + 1, 2);
	for (data t : ok)
	{
		ans[t.a] = 1;
		ans[t.b] = 1;
		ans[t.c] = 1;
	}
	for (data t : bad)
	{
		int good = (ans[t.a] == 1) + (ans[t.b] == 1) + (ans[t.c] == 1);
		if (good == 2)
		{
			ans[t.a] = (ans[t.a] == 1 ? ans[t.a] : 0);
			ans[t.b] = (ans[t.b] == 1 ? ans[t.b] : 0);
			ans[t.c] = (ans[t.c] == 1 ? ans[t.c] : 0);
		}
	}
	ans.erase(ans.begin());
	for (int t : ans)
		cout << t << endl;

	return 0;
}
