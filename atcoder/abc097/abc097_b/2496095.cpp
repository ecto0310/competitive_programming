// URL: https://atcoder.jp/contests/abc097/submissions/2496095
// Date: Sat, 12 May 2018 21:08:25 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int x;
	cin >> x;
	int ret = 1;
	for(int i = 2; i <= sqrt(x); i++)
		for(int j = 2; pow(i, j) <= x; j++)
		{
			if(pow(i, j) <= x)ret = max(ret, (int)pow(i, j));
		}
	cout << ret << endl;

	return 0;
}
