// URL: https://atcoder.jp/contests/joisc2007/submissions/3632494
// Date: Wed, 21 Nov 2018 00:09:44 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> s(n), cnt(101);
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
		cnt[s[i]]++;
	}
	for (int i = 0; i < 100; i++)
		cnt[i + 1] += cnt[i];
	for (int i = 0; i < n; i++)
		cout << n - cnt[s[i]] + 1 << endl;

	return 0;
}
