// URL: https://atcoder.jp/contests/abc106/submissions/3623021
// Date: Sun, 18 Nov 2018 21:15:39 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n, m, q;
	cin >> n >> m >> q;
	vector<vector<int>> in(501, vector<int>(501, 0));
	for (int i = 0; i < m; i++)
	{
		int l, r;
		cin >> l >> r;
		in[l][r]++;
	}
	vector<vector<int>> data(501, vector<int>(501, 0));
	for (int i = 1; i < 501; i++)
		for (int j = 1; j < 501; j++)
			data[i][j] = data[i][j - 1] + in[i][j];
	for (int qu = 0; qu < q; qu++)
	{
		int l, r;
		cin >> l >> r;
		int ans = 0;
		for (int i = l; i <= r; i++)
			ans += data[i][r] - data[i][l - 1];
		cout << ans << endl;
	}

	return 0;
}
