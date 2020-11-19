// URL: https://atcoder.jp/contests/arc059/submissions/2670514
// Date: Fri, 15 Jun 2018 21:04:05 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>
#include<assert.h>

using namespace std;

int main()
{
	int n;
	int a[100];
	cin >> n;
	for(int i = 0; i < n; i++)cin >> a[i];
	int ans = 10000000;
	for(int i = -100; i <= 100; i++)
	{
		int tmp = 0;
		for(int j = 0; j < n; j++)tmp += (i - a[j] == 0 ? 0 : (int)pow(i - a[j], 2));
		ans = min(ans, tmp);
	}
	cout << ans << endl;

	return 0;
}
