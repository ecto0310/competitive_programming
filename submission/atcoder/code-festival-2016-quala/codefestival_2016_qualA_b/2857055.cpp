// URL: https://atcoder.jp/contests/code-festival-2016-quala/submissions/2857055
// Date: Mon, 16 Jul 2018 22:51:07 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int a[100000];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		a[i]--;
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[a[i]] == i)
			ans++;
	}
	cout << ans / 2 << endl;

	return 0;
}
