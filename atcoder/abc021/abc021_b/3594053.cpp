// URL: https://atcoder.jp/contests/abc021/submissions/3594053
// Date: Tue, 13 Nov 2018 17:27:21 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n, a, b, k;
	cin >> n >> a >> b >> k;
	bool ans = true, use[101] = {};
	use[a] = true;
	use[b] = true;
	for (int i = 0; i < k; i++)
	{
		int p;
		cin >> p;
		if (use[p])
			ans = false;
		use[p] = true;
	}
	cout << (ans ? "YES" : "NO") << endl;

	return 0;
}
