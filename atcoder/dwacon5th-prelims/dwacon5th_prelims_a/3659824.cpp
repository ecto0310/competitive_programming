// URL: https://atcoder.jp/contests/dwacon5th-prelims/submissions/3659824
// Date: Sat, 24 Nov 2018 22:13:11 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	double ave = (double)sum / (double)n, def = 100;
	int ans = -1;
	for (int i = 0; i < n; i++)
		if (abs(ave - a[i]) < def)
		{
			ans = i;
			def = abs(ave - a[i]);
		}
	cout << ans << endl;

	return 0;
}
