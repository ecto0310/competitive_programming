// URL: https://atcoder.jp/contests/dwacon5th-prelims/submissions/3660320
// Date: Sat, 24 Nov 2018 22:55:10 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector<long long> now;
	for (int i = 0; i < n; i++)
	{
		long long sum = 0;
		for (int j = i; j < n; j++)
		{
			sum += a[j];
			now.push_back(sum);
		}
	}
	sort(now.begin(), now.end(), greater<long long>());
	for (int b = 50; 0 <= b; b--)
	{
		vector<long long> next;
		for (long long tmp : now)
			if (tmp & ((long long)1 << b))
				next.push_back(tmp);
		if (k <= next.size())
			now = next;
	}
	long long ans = now[0];
	for (int i = 1; i < k; i++)
		ans &= now[i];
	cout << ans << endl;

	return 0;
}
