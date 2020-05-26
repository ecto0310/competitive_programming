// URL: https://atcoder.jp/contests/future-contest-2019-qual/submissions/3579282
// Date: Sat, 10 Nov 2018 21:10:56 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int n, m, l;
vector<string> s, ans, tmp;

static int limit = 2990;
chrono::system_clock::time_point start;

int eval()
{
	int score = 0;
	vector<vector<int>> cnt(m, vector<int>(m, 0));
	for (int i = 0; i < n; i++)
	{
		int d = 0, posx = 14, posy = 14;
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
		}
		cnt[posx][posy]++;
		switch (cnt[posx][posy])
		{
		case 1:
			score += 10;
			break;
		case 2:
			score -= 7;
			break;
		case 3:
			score -= 2;
			break;
		case 4:
			score -= 1;
			break;
		}
	}
	return score;
}

int simulate()
{
	tmp = ans;
	int cnt = 0, best = eval();
	while (static_cast<double>(chrono::duration_cast<chrono::microseconds>(chrono::system_clock::now() - start).count() / 1000.0) < limit)
	{
		int x = 1 + rand() % 27, y = 1 + rand() % 27;
		if (x != 14 || y != 14)
		{
			tmp[x][y] = (tmp[x][y] == '#' ? '.' : '#');
			int score = eval();
			if (best < score)
			{
				best = score;
				ans[x][y] = (ans[x][y] == '#' ? '.' : '#');
			}
			else
				tmp[x][y] = (tmp[x][y] == '#' ? '.' : '#');
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
	int loop = simulate();
	for (int i = 0; i < m; i++)
		cout << ans[i] << endl;
	cerr << "loop: " << loop << endl;

	return 0;
}
