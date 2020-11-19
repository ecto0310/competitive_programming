// URL: https://atcoder.jp/contests/abc108/submissions/3112552
// Date: Sat, 01 Sep 2018 21:02:16 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int k;
	cin >> k;
	int tmp = 0;
	for (int i = 1; i <= k; i++)
		if (i % 2 == 0)
			tmp++;
	cout << tmp * (k - tmp) << endl;

	return 0;
}
