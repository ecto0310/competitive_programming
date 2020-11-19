// URL: https://atcoder.jp/contests/joi2015yo/submissions/3632625
// Date: Wed, 21 Nov 2018 00:47:24 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int h, w;
	cin >> h >> w;
	vector<string> c(h);
	for (int i = 0; i < h; i++)
		cin >> c[i];
	vector<vector<int>> ans(h, vector<int>(w, -1));
	for (int ph = 0; ph < h; ph++)
		for (int pw = 0; pw < w; pw++)
			if (c[ph][pw] == 'c')
				for (int i = 0; i < w - pw; i++)
					ans[ph][pw + i] = (ans[ph][pw + i] == -1 ? i : min(ans[ph][pw + i], i));
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			cout << ans[i][j] << (j == w - 1 ? "\n" : " ");

	return 0;
}
