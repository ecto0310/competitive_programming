// URL: https://atcoder.jp/contests/abc102/submissions/2783822
// Date: Mon, 02 Jul 2018 23:41:55 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> a;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		a.push_back(tmp - i - 1);
	}
	sort(a.begin(), a.end());
	long long ans = 0, d = (n % 2 == 0 ? (a[n / 2 - 1] + a[n / 2]) / 2 : a[n / 2]);
	for (int i = 0; i < n; i++)
		ans += abs(a[i] - d);
	cout << ans << endl;

	return 0;
}
