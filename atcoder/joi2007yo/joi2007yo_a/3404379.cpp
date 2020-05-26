// URL: https://atcoder.jp/contests/joi2007yo/submissions/3404379
// Date: Sun, 14 Oct 2018 18:09:40 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int a = 0, b = 0;
	for (int i = 0; i < 4; i++)
	{
		int t;
		cin >> t;
		a += t;
	}
	for (int i = 0; i < 4; i++)
	{
		int t;
		cin >> t;
		b += t;
	}
	cout << max(a, b) << endl;

	return 0;
}
