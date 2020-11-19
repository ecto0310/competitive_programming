// URL: https://atcoder.jp/contests/abc098/submissions/2563762
// Date: Sat, 26 May 2018 21:12:15 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>
#include<assert.h>

using namespace std;

int sum[300000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	string s;
	cin >> n >> s;
	sum[0] = (s[0] == 'E' ? 1 : 0);
	for(int i = 1; i < n; i++)sum[i] = sum[i - 1] + (s[i] == 'E' ? 1 : 0);
	int ans = n;
	for(int i = 0; i < n; i++)
	{
		int tmp = i - (i != 0 ? sum[i - 1] : 0) + sum[n - 1] - sum[i];
		ans = min(ans, tmp);
	}
	cout << ans << endl;

	return 0;
}
