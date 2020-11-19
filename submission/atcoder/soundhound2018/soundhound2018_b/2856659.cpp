// URL: https://atcoder.jp/contests/soundhound2018/submissions/2856659
// Date: Mon, 16 Jul 2018 21:29:26 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n, l, r;
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		if (a < l)
			cout << l << " ";
		else if (a > r)
			cout << r << " ";
		else
			cout << a << " ";
	}
	cout << endl;

	return 0;
}
