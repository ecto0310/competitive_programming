// URL: https://atcoder.jp/contests/abc027/submissions/3593667
// Date: Tue, 13 Nov 2018 16:27:20 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n), s(n + 1);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		s[i + 1] = s[i] + a[i];
	}
	if (s[n] % n != 0)
	{
		cout << -1 << endl;
		return 0;
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		if (s[i + 1] != s[n] / n * (i + 1))
			ans++;
	cout << ans << endl;

	return 0;
}
