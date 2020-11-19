// URL: https://atcoder.jp/contests/abc099/submissions/2656475
// Date: Mon, 11 Jun 2018 21:06:12 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>
#include<assert.h>

using namespace std;

int main()
{
	int n, c;
	cin >> n >> c;
	int d[30][30];
	for(int i = 0; i < c; i++)
		for(int j = 0; j < c; j++)
		{
			cin >> d[i][j];
		}
	int g[3][30] = {};
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		{
			int tmp;
			cin >> tmp;
			g[(i + j) % 3][tmp - 1]++;
		}
	int ans = 1000000000;
	for(int i = 0; i < c; i++)
		for(int j=0;j<c;j++)
		{
			if(i == j)continue;
			for(int k = 0; k < c; k++)
			{
				if(i == k || j == k)continue;
				int tmp = 0;
				for(int l = 0; l < c; l++)tmp += d[l][i] * g[0][l];
				for(int l = 0; l < c; l++)tmp += d[l][j] * g[1][l];
				for(int l = 0; l < c; l++)tmp += d[l][k] * g[2][l];
				ans = min(ans, tmp);
			}
		}
	cout << ans << endl;

	return 0;
}
