// URL: https://atcoder.jp/contests/joi2018yo/submissions/3687728
// Date: Fri, 30 Nov 2018 10:36:26 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

long long n, k, l;
vector<int> a;

long long count(int x)
{
	int j = 0, cnt = 0;
	long long ans = 0;
	for (int i = 0; i < n; i++)
	{
		while (j < n && cnt < k)
		{
			if (a[j] < x)
				cnt++;
			j++;
		}
		if (cnt == k)
			ans += n - j + 1;
		if (a[i] < x)
			cnt--;
	}
	return ans;
}

int main()
{
	cin >> n >> k >> l;
	l--;
	a.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int ng = n + 1, ok = -1;
	while (1 < ng - ok)
	{
		int md = (ok + ng) / 2;
		if (l < count(md))
			ng = md;
		else
			ok = md;
	}
	cout << ok << endl;

	return 0;
}
