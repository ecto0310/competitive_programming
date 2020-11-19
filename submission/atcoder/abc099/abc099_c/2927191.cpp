// URL: https://atcoder.jp/contests/abc099/submissions/2927191
// Date: Tue, 31 Jul 2018 23:07:45 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int add[12] = {1, 6, 9, 36, 81, 216, 729, 1296, 6561, 7776, 46656, 59049};
	queue<int> que;
	map<int, int> m;
	for (int i = 0; i < 12; i++)
	{
		m[add[i]] = 1;
		que.push(add[i]);
	}
	while (que.size() && m[n] == 0)
	{
		int q = que.front();
		que.pop();
		for (int i = 0; i < 12; i++)
			if (m[q + add[i]] == 0)
			{
				m[q + add[i]] = m[q] + 1;
				que.push(q + add[i]);
			}
	}
	cout << m[n] << endl;

	return 0;
}
