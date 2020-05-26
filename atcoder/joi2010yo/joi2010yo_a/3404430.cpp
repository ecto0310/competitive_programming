// URL: https://atcoder.jp/contests/joi2010yo/submissions/3404430
// Date: Sun, 14 Oct 2018 18:21:49 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < 9; i++)
	{
		int b;
		cin >> b;
		n -= b;
	}
	cout << n << endl;

	return 0;
}
