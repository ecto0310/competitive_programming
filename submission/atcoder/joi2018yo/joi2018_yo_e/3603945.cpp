// URL: https://atcoder.jp/contests/joi2018yo/submissions/3603945
// Date: Thu, 15 Nov 2018 20:09:49 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int dh[4] = {-1, 0, 1, 0}, dw[4] = {0, 1, 0, -1};

int main()
{
	int h, w;
	cin >> h >> w;
	vector<vector<int>> a(h, vector<int>(w));
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			cin >> a[i][j];
	vector<vector<int>> time(h, vector<int>(w, 1e9 + 7)), far(h, vector<int>(w, 0));
	queue<pair<int, int>> que;
	que.push(pair<int, int>(pair<int, int>(0, 0)));
	time[0][0] = 0;
	while (que.size())
	{
		pair<int, int> q = que.front();
		que.pop();
		int nh = q.first, nw = q.second;
		for (int i = 0; i < 4; i++)
		{
			int hh = nh + dh[i], ww = nw + dw[i];
			if (-1 < hh && hh < h && -1 < ww && ww < w && time[hh][ww] > time[nh][nw] + far[nh][nw] * 2 * a[hh][ww] + a[hh][ww])
			{
				time[hh][ww] = time[nh][nw] + far[nh][nw] * 2 * a[hh][ww] + a[hh][ww];
				far[hh][ww] = far[nh][nw] + 1;
				que.push(pair<int, int>(pair<int, int>(hh, ww)));
			}
		}
	}
	cout << time[h - 1][w - 1] << endl;

	return 0;
}
