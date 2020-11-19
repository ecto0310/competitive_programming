// URL: https://atcoder.jp/contests/abc077/submissions/2814657
// Date: Sun, 08 Jul 2018 20:35:18 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> a, b, c;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		b.push_back(tmp);
	}
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		c.push_back(tmp);
	}
	sort(a.begin(), a.end());
	sort(c.begin(), c.end());
	long long ans = 0;
	for (int i = 0; i < n; i++)
		ans += (lower_bound(a.begin(), a.end(), b[i])-a.begin())*(c.end()-upper_bound(c.begin(),c.end(),b[i]));
	cout << ans << endl;

	return 0;
}
