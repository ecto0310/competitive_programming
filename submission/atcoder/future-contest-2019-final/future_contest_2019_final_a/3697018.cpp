// URL: https://atcoder.jp/contests/future-contest-2019-final/submissions/3697018
// Date: Sat, 01 Dec 2018 23:31:01 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

struct work
{
	int a, b;
	long long c;
	vector<int> s;
	void set(int ia, int ib, long long ic, vector<int> is)
	{
		a = ia;
		b = ib;
		c = ic;
		s = is;
	}
	double get_prize(int turn, vector<int> skill)
	{
		if (turn != b)
			return 0;
		double ret = c * (turn == b ? 10 : 1);
		ret *= 1 + 9 * (turn - a) / (b - a);
		int cnt = 0;
		for (int i = 0; i < skill.size(); i++)
			if (skill[i] <= s[i])
				cnt++;
		if (cnt == 0)
			ret *= 10;
		else
			ret *= pow(1 / 2, cnt);
		return ret;
	}
	void use()
	{
		c = 0;
	}
};

struct cmd
{
	int type = 3, num = -1;
};

int t, n, m;
vector<work> data;
vector<cmd> ans;

void input()
{
	cin >> t >> n >> m;
	data.resize(m);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		long long c;
		vector<int> s(n);
		cin >> a >> b >> c;
		for (int j = 0; j < n; j++)
			cin >> s[j];
		data[i].set(a, b, c, s);
	}
	ans.resize(t);
}

void solve()
{
	long long now = 1000;
	vector<int> skill(n, 0);
	for (int i = 0; i < t; i++)
	{
		vector<int> up;
		for (int j = 0; j < n; j++)
			if (skill[j] < 10 && 10000 * (1 << skill[j] + 1) <= now)
			{
				up.push_back(j);
			}
		if (up.size() != 0)
		{
			int tmp = up[rand() % up.size()];
			ans[i].type = 1;
			ans[i].num = tmp;
			now -= 10000 * (1 << skill[tmp] + 1);
			skill[tmp]++;
			continue;
		}
		int mw = -1, mg = 1000;
		for (int j = 0; j < n; j++)
			if (mg < data[j].get_prize(i + 1, skill))
			{
				mw = j;
				mg = data[j].get_prize(i + 1, skill);
			}
		if (mw != -1)
		{
			ans[i].type = 2;
			ans[i].num = mw;
			data[mw].use();
			now += mg;
			continue;
		}
		now += 1000;
	}
}

void output()
{
	for (int i = 0; i < t; i++)
		switch (ans[i].type)
		{
		case 1:
			cout << "1 " << ans[i].num + 1 << endl;
			break;
		case 2:
			cout << "2 " << ans[i].num + 1 << endl;
			break;
		case 3:
			cout << "3" << endl;
			break;
		}
}

int main()
{
	input();
	solve();
	output();

	return 0;
}
