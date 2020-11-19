// URL: https://atcoder.jp/contests/arc100/submissions/2920719
// Date: Sun, 29 Jul 2018 23:22:08 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n;
	vector<int> v;
	cin >> n;
	for (int i = 1; i <= n;i++)
	{
		int a;
		cin >> a;
		v.push_back(a - i);
	}
	sort(v.begin(), v.end());
	long long ans = 0;
	for (int i = 0; i < n;i++)
		ans += abs(v[i] - v[n / 2]);
	cout << ans << endl;

	return 0;
}
