// URL: https://atcoder.jp/contests/abc037/submissions/3415023
// Date: Mon, 15 Oct 2018 23:56:07 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n, q, l[100], r[100], t[100];
	cin >> n >> q;
	for (int i = 0; i < q; i++)
		cin >> l[i] >> r[i] >> t[i];
	vector<int> ans(n + 1);
	for (int i = 0; i < q; i++)
		for (int j = l[i]; j <= r[i]; j++)
			ans[j] = t[i];
	for (int i = 1; i <= n; i++)
		cout << ans[i] << endl;

	return 0;
}
