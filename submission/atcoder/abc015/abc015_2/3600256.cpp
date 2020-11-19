// URL: https://atcoder.jp/contests/abc015/submissions/3600256
// Date: Wed, 14 Nov 2018 23:10:12 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int cnt = 0, sum = 0;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		if (a != 0)
			cnt++;
		sum += a;
	}
	cout << (sum + cnt - 1) / cnt << endl;

	return 0;
}
