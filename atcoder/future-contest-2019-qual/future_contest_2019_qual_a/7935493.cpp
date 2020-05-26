// URL: https://atcoder.jp/contests/future-contest-2019-qual/submissions/7935493
// Date: Fri, 11 Oct 2019 16:06:10 +0900
// Language: C++14 (Clang 3.8.0)
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;

const int timeLimit = 2990;

struct sTurn
{
	bool map[29][29] = {};
	int x, y;

	void clear()
	{
		for (int i = 0; i < 29; i++)
			for (int j = 0; j < 29; j++)
				map[i][j] = false;
	}
};

int n, m, l;
vector<string> s, ans, tmpAns;
vector<sTurn> useTurn, bestUseTurn;

void input()
{
	cin >> n >> m >> l;
	s.resize(n);
	for (int i = 0; i < n; i++)
		cin >> s[i];
}

void init()
{
	ans.resize(m);
	ans[0].resize(m, '#');
	for (int i = 1; i < m - 1; i++)
	{
		ans[i].resize(m, 'L');
		ans[i][0] = '#';
		ans[i][m - 1] = '#';
	}
	ans[m - 1].resize(m, '#');
	useTurn.resize(n);
}

int eval(vector<string> &map, int cx = -1, int cy = -1)
{
	int score = 0;
	vector<vector<int>> counter(m, vector<int>(m, 0));
	for (int i = 0; i < n; i++)
	{
		if ((cx == -1 && cy == -1) || useTurn[i].map[cx][cy])
		{
			int direct = 0, pos[2] = {14, 14};
			useTurn[i].clear();
			for (int j = 0; j < l; j++)
				switch (s[i][j])
				{
				case 'S':
					switch (direct)
					{
					case 0:
						if (map[pos[0] - 1][pos[1]] != '#')
							pos[0]--;
						break;
					case 1:
						if (map[pos[0]][pos[1] + 1] != '#')
							pos[1]++;
						break;
					case 2:
						if (map[pos[0] + 1][pos[1]] != '#')
							pos[0]++;
						break;
					case 3:
						if (map[pos[0]][pos[1] - 1] != '#')
							pos[1]--;
						break;
					}
					break;
				case 'L':
					useTurn[i].map[pos[0]][pos[1]] = true;
					if (map[pos[0]][pos[1]] == 'R')
						direct = (direct + 5) % 4;
					else
						direct = (direct + 3) % 4;
					break;
				case 'R':
					useTurn[i].map[pos[0]][pos[1]] = true;
					if (map[pos[0]][pos[1]] == 'L')
						direct = (direct + 3) % 4;
					else
						direct = (direct + 5) % 4;
					break;
				}
			useTurn[i].x = pos[0];
			useTurn[i].y = pos[1];
		}
		switch (++counter[useTurn[i].x][useTurn[i].y])
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

void simulate()
{
	chrono::system_clock::time_point start = chrono::system_clock::now();
	int bestScore = eval(ans);
	bestUseTurn = useTurn;
	while (chrono::duration_cast<chrono::microseconds>(chrono::system_clock::now() - start).count() / 1000 < timeLimit)
	{
		tmpAns = ans;
		int x = 1 + rand() % 27, y = 1 + rand() % 27;
		tmpAns[x][y] = (rand()%2==0?'R':'.');
		int tmpScore = eval(tmpAns, x, y);
		if (bestScore < tmpScore)
		{
			ans = tmpAns;
			bestScore = tmpScore;
			bestUseTurn = useTurn;
		}
		else
			useTurn = bestUseTurn;
	}
}

void output()
{
	for (int i = 0; i < m; i++)
		cout << ans[i] << endl;
}

int main()
{
	srand(100);
	input();
	init();
	simulate();
	output();

	return 0;
}
