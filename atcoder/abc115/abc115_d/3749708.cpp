// URL: https://atcoder.jp/contests/abc115/submissions/3749708
// Date: Sun, 09 Dec 2018 00:21:20 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

long long n, x;

vector<long long> p(1, 1), a(1, 1);

long long cnt(long long n, long long x)
{
	if (n == 0)
		return 1;
	else if (x == 1)
		return 0;
	else if (x <= a[n - 1] + 1)
		return cnt(n - 1, x - 1);
	else if (x == a[n - 1] + 2)
		return p[n - 1] + 1;
	else if (x <= 2 * a[n - 1] + 2)
		return p[n - 1] + 1 + cnt(n - 1, x - a[n - 1] - 2);
	return 2 * p[n - 1] + 1;
}

int main()
{
	cin >> n >> x;
	for (int i = 0; i <= 50; i++)
	{
		p.push_back(p[i] * 2 + 1);
		a.push_back(a[i] * 2 + 3);
	}
	cout << cnt(n, x) << endl;

	return 0;
}
