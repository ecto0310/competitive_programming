// URL: https://atcoder.jp/contests/arc079/submissions/2920983
// Date: Mon, 30 Jul 2018 00:38:13 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	long long a[50];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	long long ans = 0;
	while (true)
	{
		long long tmp = 0;
		bool ok = true;
		for (int i = 0; i < n; i++)
		{
			tmp += a[i] / n;
			if (a[i] >= n)
				ok = false;
		}
		if (ok)
			break;
		ans += tmp;
		for (int i = 0; i < n; i++)
			a[i] = a[i] % n + tmp - a[i] / n;
	}
	cout << ans << endl;

	return 0;
}
