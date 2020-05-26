// URL: https://atcoder.jp/contests/agc017/submissions/3410647
// Date: Mon, 15 Oct 2018 01:05:44 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

long long _pow(int n, int m)
{
	long long ret = 1;
	for (int i = 0; i < m; i++)
		ret *= n;
	return ret;
}

using namespace std;
int main()
{
	int n, p;
	cin >> n >> p;
	map<int, int> m;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		m[a % 2]++;
	}
	if (m[1] == 0 && p == 1)
		cout << 0 << endl;
	else if (m[1] == 0)
		cout << _pow(2, n) << endl;
	else
		cout << _pow(2, n - 1) << endl;

	return 0;
}
