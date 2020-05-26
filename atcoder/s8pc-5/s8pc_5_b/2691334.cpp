// URL: https://atcoder.jp/contests/s8pc-5/submissions/2691334
// Date: Sun, 17 Jun 2018 02:46:02 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>
#include<assert.h>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int xn[100], yn[100], rn[100];
	int xm[100], ym[100];
	for(int i = 0; i < n; i++)cin >> xn[i] >> yn[i] >> rn[i];
	for(int i = 0; i < m; i++)cin >> xm[i] >> ym[i];
	float ans = 200.0;
	for(int i = 0; i < n; i++)ans = min(ans, (float)rn[i]);
	for(int i = 0; i < m; i++)
	{
		for(int j = i + 1; j < m; j++)ans = min(ans, (float)sqrt(pow(xm[i] - xm[j], 2) + pow(ym[i] - ym[j], 2)) / 2);
		for(int j = 0; j < n; j++)ans = min(ans, (float)sqrt(pow(xm[i] - xn[j], 2) + pow(ym[i] - yn[j], 2)) - rn[j]);
	}
	cout << fixed << setprecision(7) << ans << endl;

	return 0;
}
