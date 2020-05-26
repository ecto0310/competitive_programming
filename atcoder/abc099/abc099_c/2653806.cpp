// URL: https://atcoder.jp/contests/abc099/submissions/2653806
// Date: Mon, 11 Jun 2018 06:53:32 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>
#include<assert.h>

using namespace std;

int ok[100001];

int main()
{
	int n;
	cin >> n;
	int money[12] = {1,6,9,36,81,216,729,1296,6561,7776,46656,59049};
	queue<pair<long long, int>> que;
	for(int i = 0; i < 12; i++)
	{
		que.push(pair<long long, int>(money[i], 1));
		ok[money[i]] = 1;

	}
	while(que.size())
	{
		pair<long long, int> p = que.front(); que.pop();
		for(int i = 0; i < 12; i++)
		{
			if(p.first + money[i] <= n && ok[p.first + money[i]] == 0)
			{
				ok[p.first + money[i]] = p.second + 1;
				que.push(pair<long long, int>(p.first + money[i], p.second + 1));
			}
		}
	}
	cout << ok[n] << endl;

	return 0;
}
