// URL: https://atcoder.jp/contests/arc031/submissions/2976664
// Date: Thu, 09 Aug 2018 22:52:06 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

int main()
{
	string a[10];
	for (int i = 0; i < 10; i++)
		cin >> a[i];
	bool ok = false;
	int sx, sy;
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			if (a[i][j] == 'o')
			{
				sx = i;
				sy = j;
			}
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
		{
			if (a[i][j] == 'o')
				continue;
			a[i][j] = 'o';
			queue<pair<int, int>> que;
			bool use[10][10] = {};
			que.push(pair<int, int>(sx, sy));
			use[sx][sy] = true;
			while (que.size())
			{
				pair<int, int> q = que.front();
				que.pop();
				for (int k = 0; k < 4; k++)
					if (-1 < q.first + dx[k] && q.first + dx[k] < 10 && -1 < q.second + dy[k] && q.second + dy[k] < 10 && a[q.first + dx[k]][q.second + dy[k]] == 'o' && !use[q.first + dx[k]][q.second + dy[k]])
					{
						use[q.first + dx[k]][q.second + dy[k]] = true;
						que.push(pair<int, int>(q.first + dx[k], q.second + dy[k]));
					}
			}
			bool tmp = true;
			for (int k = 0; k < 10; k++)
				for (int l = 0; l < 10; l++)
					if (a[k][l] == 'o' && !use[k][l])
						tmp = false;
			if (tmp == true)
				ok = true;
			a[i][j] = 'x';
		}
	if (ok)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}
