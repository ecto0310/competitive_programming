// URL: https://atcoder.jp/contests/joi2012yo/submissions/3632601
// Date: Wed, 21 Nov 2018 00:39:16 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> p(n + 1);
	for (int i = 0; i < n * (n - 1) / 2; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (c > d)
			p[a] += 3;
		else if (c < d)
			p[b] += 3;
		else
		{
			p[a]++;
			p[b]++;
		}
	}
	vector<int> cnt(n * 3);
	for (int i = 0; i < n; i++)
		cnt[p[i + 1]]++;
	for (int i = 0; i < n * 3 - 1; i++)
		cnt[i + 1] += cnt[i];
	for (int i = 0; i < n; i++)
		cout << n - cnt[p[i + 1]] + 1 << endl;

	return 0;
}
