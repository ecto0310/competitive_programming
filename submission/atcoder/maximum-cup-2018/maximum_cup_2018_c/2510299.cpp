// URL: https://atcoder.jp/contests/maximum-cup-2018/submissions/2510299
// Date: Sun, 13 May 2018 23:20:47 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>
#include<assert.h>

using namespace std;

int a[100000];
bool c[100000];

int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		a[i]--;
	}
	bool ok = true;
	for(int i = 0; i < n; i++)
	{
		int now = i, cnt = 0;
		while(!c[now])
		{
			c[now] = true;
			now = a[now];
			cnt++;
		}
		if(cnt % 2 == 1)ok = false;
	}
	if(ok)cout << n / 2 << endl;
	else cout << -1 << endl;

	return 0;
}
