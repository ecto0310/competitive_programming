// URL: https://atcoder.jp/contests/yahoo-procon2017-qual/submissions/2823033
// Date: Tue, 10 Jul 2018 22:55:21 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	long long ans = 0;
	for (int i = 0; i < k; i++)
		ans += v[i] + i;
	cout << ans << endl;

	return 0;
}
