// URL: https://atcoder.jp/contests/abc096/submissions/2468578
// Date: Sat, 05 May 2018 22:44:47 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

bool pri[55556];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	for(int i = 1; i < 55556; i++)pri[i] = true;
	for(int i = 2; i < sqrt(55556); i++)
	{
		if(pri[i])
		{
			for(int j = 0; i * (j + 2) < 55556; j++)
			{
				pri[i *(j + 2)] = false;
			}
		}
	}
	int n;
	cin >> n;
	int now = 2;
	while(n)
	{
		if(pri[now] && now % 5 == 1)
		{
			cout << now << (n > 1 ? " " : "");
			n--;
			if(n == 0)break;
		}
		now++;
	}


	return 0;
}
