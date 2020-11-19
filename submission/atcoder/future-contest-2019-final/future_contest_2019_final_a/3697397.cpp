// URL: https://atcoder.jp/contests/future-contest-2019-final/submissions/3697397
// Date: Sun, 02 Dec 2018 01:13:33 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

struct Work
{
	int a, b;
	long long c;
	int s[10];
	bool ok = true;
};

struct Player
{
	int turn = 0;
	long long money = 1000;
	int skill[10] = {};
	vector<Work> data = vector<Work>(30000);

	long long calcTraining(int i)
	{
		return ((i + 1) * 10000 * (1 << skill[i] + 1));
	}

	bool isTraining(int i)
	{
		return calcTraining(i) <= money;
	}

	void training(int i)
	{
		skill[i]++;
		turn += skill[i];
		money -= calcTraining(i);
		for (int j = 0; j < skill[i]; j++)
			cout << "1 " << i + 1 << endl;
	}

	long long calcProfit(int i)
	{
		double get = data[i].c;
		get *= (1 + 9 * (double)(turn - data[i].a) / (data[i].b - data[i].a));
		int lack = 0;
		for (int j = 0; j < 10; j++)
			lack += max(0, data[i].s[j] - skill[j]);
		if (lack == 0)
			get *= 10;
		else
			get += pow(0.5, lack);
		return (long long)get;
	}

	bool isProfit(int i)
	{
		return data[i].a <= turn && turn <= data[i].b && data[i].ok;
	}

	void profit(int i)
	{
		turn++;
		money += calcProfit(i);
		data[i].ok = false;
		cout << "2 " << i + 1 << endl;
	}

	void work()
	{
		turn++;
		money += 1000;
		cout << "3" << endl;
	}
};

int t, n, m;
Player player;

void input()
{
	cin >> t >> n >> m;
	for (int i = 0; i < m; i++)
	{
		Work tmp;
		cin >> tmp.a >> tmp.b >> tmp.c;
		for (int j = 0; j < n; j++)
			cin >> tmp.s[j];
		player.data[i] = tmp;
	}
}

void solve()
{
	for (int i = 0; i < 200; i++)
		player.work();
	for (int i = 0; i < 10; i++)
		player.training(i);
	while (player.turn < t)
	{
		long long max = 0, task = -1;
		for (int i = 0; i < m; i++)
		{
			if (!player.isProfit(i))
				continue;
			long long tmp = player.calcProfit(i);
			if (tmp < max || tmp < 1000)
				continue;
			max = tmp;
			task = i;
		}
		if (task == -1)
			player.work();
		else
			player.profit(task);
	}
}

int main()
{
	input();
	solve();

	return 0;
}
