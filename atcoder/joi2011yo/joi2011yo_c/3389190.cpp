// URL: https://atcoder.jp/contests/joi2011yo/submissions/3389190
// Date: Sat, 13 Oct 2018 00:45:48 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < k; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << (min({a, b, n - a + 1, n - b + 1}) - 1) % 3 + 1 << endl;
	}

	return 0;
}
