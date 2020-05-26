// URL: https://atcoder.jp/contests/agc025/submissions/2607676
// Date: Sun, 03 Jun 2018 21:08:08 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>
#include<assert.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int ans = 100;
	for(int i = 1; i < n; i++)
	{
		int tmp = 0, a = i, b = n - i;
		while(a)
		{
			tmp += a % 10;
			a /= 10;
		}
		while(b)
		{
			tmp += b % 10;
			b /= 10;
		}
		ans = min(ans, tmp);
	}
	cout << ans << endl;

	return 0;
}
