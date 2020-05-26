// URL: https://atcoder.jp/contests/joi2011yo/submissions/3715494
// Date: Tue, 04 Dec 2018 15:27:04 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int h, w;

int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

vector<string> s;
vector<int> x, y;

int dijkstra(int next)
{
	queue<pair<int, int>> que;
	que.push({x[next - 1], y[next - 1]});
	vector<vector<int>> cost(h, vector<int>(w, 1e9));
	cost[x[next - 1]][y[next - 1]] = 0;
	while (que.size())
	{
		pair<int, int> p = que.front();
		que.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = p.first + dx[i], ny = p.second + dy[i];
			if (-1 < nx && nx < h && -1 < ny && ny < w && s[nx][ny] == '.' && cost[p.first][p.second] + 1 < cost[nx][ny])
			{
				cost[nx][ny] = cost[p.first][p.second] + 1;
				que.push({nx, ny});
				if (nx == x[next] && ny == y[next])
					return cost[x[next]][y[next]];
			}
		}
	}
}

int main()
{
	int n;
	cin >> h >> w >> n;
	s.resize(h);
	x.resize(n + 1);
	y.resize(n + 1);
	for (int i = 0; i < h; i++)
	{
		cin >> s[i];
		for (int j = 0; j < w; j++)
			if (s[i][j] == 'S')
			{
				x[0] = i;
				y[0] = j;
				s[i][j] = '.';
			}
			else if ('1' <= s[i][j] && s[i][j] <= '9')
			{
				int now = s[i][j] - '0';
				x[now] = i;
				y[now] = j;
				s[i][j] = '.';
			}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans += dijkstra(i);
	cout << ans << endl;

	return 0;
}
