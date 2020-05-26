// URL: https://atcoder.jp/contests/agc002/submissions/2935715
// Date: Thu, 02 Aug 2018 23:59:19 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int a[100000];

int main()
{
	int n, l;
	cin >> n >> l;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int tmp = 0, cnt;
	for (int i = 1; i < n; i++)
		if (tmp < a[i] + a[i - 1])
		{
			tmp = a[i] + a[i - 1];
			cnt = i;
		}
	if (tmp < l)
		cout << "Impossible" << endl;
	else
	{
		cout << "Possible" << endl;
		for (int i = 1; i < cnt; i++)
			cout << i << endl;
		for (int i = n - 1; i > cnt; i--)
			cout << i << endl;
		cout << cnt << endl;
	}

	return 0;
}
