// URL: https://atcoder.jp/contests/arc067/submissions/3728044
// Date: Thu, 06 Dec 2018 21:26:22 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

const int mod = 1e9 + 7;

vector<int> cnt(1e3 + 1, 1);

int calc(int t)
{
	int i = 2;
	while (1 < t)
		if (t % i == 0)
		{
			cnt[i]++;
			t /= i;
		}
		else
			i++;
	return 0;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		calc(i);
	long long ans = 1;
	for (int i = 1; i <= n; i++)
		ans = ans * cnt[i] % mod;
	cout << ans << endl;

	return 0;
}
