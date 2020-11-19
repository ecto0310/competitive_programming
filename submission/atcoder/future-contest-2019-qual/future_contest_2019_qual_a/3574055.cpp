// URL: https://atcoder.jp/contests/future-contest-2019-qual/submissions/3574055
// Date: Sat, 10 Nov 2018 15:50:02 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int n, m, l;
vector<string> s, ans, def;

static int limit = 2990;
chrono::system_clock::time_point start;

int eval(vector<string> tmp)
{
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
					if (tmp[posx][posy - 1] != '#')
						posy--;
					break;
				case 1:
					if (tmp[posx + 1][posy] != '#')
						posx++;
					break;
				case 2:
					if (tmp[posx][posy + 1] != '#')
						posy++;
					break;
				case 3:
					if (tmp[posx - 1][posy] != '#')
						posx--;
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
		vector<string> tmp = def;
		int object = rand() % 50;
		for (int i = 0; i < object; i++)
			tmp[1 + rand() % 28][1 + rand() % 28] = '#';
		tmp[14][14] = '.';
		int score = eval(tmp);
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
	def.resize(m);
	for (int i = 0; i < m; i++)
		def[0] += "#";
	def[m - 1] = def[0];
	for (int i = 1; i < m - 1; i++)
	{
		def[i] = "#";
		for (int j = 0; j < m - 2; j++)
			def[i] += ".";
		def[i] += "#";
	}
	ans = def;
	int loop = simulate();
	for (int i = 0; i < m; i++)
		cout << ans[i] << endl;
	cerr << "loop: " << loop << endl;

	return 0;
}
