// URL: https://atcoder.jp/contests/abc065/submissions/2814576
// Date: Sun, 08 Jul 2018 20:14:45 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int a[100001];

int main()
{
	int n;
	cin>>n;
	for (int i = 0; i < n;i++)
		cin >> a[i+1];
	queue<pair<int,int>> que;
	que.push(pair<int, int>(1, 0));
	while(que.size())
	{
		pair<int, int> q = que.front();
		que.pop();
		if(q.first==2)
		{
			cout<< q.second<< endl;
			return 0;
		}
		if(a[q.first]!=-1)
		{
			que.push(pair<int, int>(a[q.first],q.second + 1));
			a[q.first] = -1;
		}
	}
	cout << "-1" << endl;

	return 0;
}
