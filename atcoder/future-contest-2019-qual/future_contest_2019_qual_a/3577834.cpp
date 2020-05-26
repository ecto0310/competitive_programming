// URL: https://atcoder.jp/contests/future-contest-2019-qual/submissions/3577834
// Date: Sat, 10 Nov 2018 19:46:26 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int n, m, l;
vector<string> s, ans;

static int limit = 2980;
chrono::system_clock::time_point start;

vector<map<pair<int, int>, bool>> use;
vector<pair<int, int>> lastpos;

int eval(vector<string> tmp, int x = -1, int y = -1)
{
	vector<vector<int>> cnt(m, vector<int>(m, 0));
	for (int i = 0; i < n; i++)
	{
		int d = 0, posx = 14, posy = 14;
		if (x == -1 || use[i][pair<int, int>(x, y)])
		{
			use[i].clear();
			for (int j = 0; j < l; j++)
			{
				switch (s[i][j])
				{
				case 'S':
					switch (d)
					{
					case 0:
						if (tmp[posx - 1][posy] != '#')
							posx--;
						break;
					case 1:
						if (tmp[posx][posy + 1] != '#')
							posy++;
						break;
					case 2:
						if (tmp[posx + 1][posy] != '#')
							posx++;
						break;
					case 3:
						if (tmp[posx][posy - 1] != '#')
							posy--;
						break;
					}
					break;
				case 'L':
					d--;
					if (d == -1)
						d = 3;
					break;
				case 'R':
					d++;
					if (d == 4)
						d = 0;
					break;
				}
				use[i][pair<int, int>(posx, posy)] = true;
			}
			lastpos[i].first = posx;
			lastpos[i].second = posy;
		}
		else
		{
			posx = lastpos[i].first;
			posy = lastpos[i].second;
		}

		cnt[posx][posy]++;
	}
	int score = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			switch (cnt[i][j])
			{
			case 1:
				score += 10;
				break;
			case 2:
				score += 3;
				break;
			case 3:
				score += 1;
				break;
			}
	return score;
}

int simulate()
{
	int cnt = 0, best = eval(ans);
	while (static_cast<double>(chrono::duration_cast<chrono::microseconds>(chrono::system_clock::now() - start).count() / 1000.0) < limit)
	{
		vector<string> tmp = ans;
		int x = 1 + rand() % 27, y = 1 + rand() % 27;
		if (x == 14 && y == 14)
		{
			x = 1 + rand() % 27;
			y = 1 + rand() % 27;
		}
		tmp[x][y] = (tmp[x][y] == '#' ? '.' : '#');
		int score = eval(tmp, x, y);
		if (best < score)
		{
			best = score;
			ans = tmp;
		}

		cnt++;
	}
	cerr << "score: " << best << endl;
	return cnt;
}

int main()
{
	cin >> n >> m >> l;
	s.resize(n);
	for (int i = 0; i < n; i++)
		cin >> s[i];
	start = chrono::system_clock::now();
	ans.resize(m);
	for (int i = 0; i < m; i++)
		ans[0] += "#";
	ans[m - 1] = ans[0];
	for (int i = 1; i < m - 1; i++)
	{
		ans[i] = "#";
		for (int j = 0; j < m - 2; j++)
			ans[i] += ".";
		ans[i] += "#";
	}
	use.resize(n + 1);
	lastpos.resize(n);
	int loop = simulate();
	for (int i = 0; i < m; i++)
		cout << ans[i] << endl;
	cerr << "loop: " << loop << endl;

	return 0;
}
