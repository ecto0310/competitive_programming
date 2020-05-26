// URL: https://atcoder.jp/contests/agc023/submissions/2542056
// Date: Mon, 21 May 2018 01:40:06 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>
#include<assert.h>

using namespace std;

long long sum[200001];

int main()
{
	int n;
	cin >> n;
	map<long long, int> m;
	m[0]++;
	long long ans = 0;
	for(int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		sum[i] = sum[i - 1] + a;
		ans += m[sum[i]];
		m[sum[i]]++;
	}
	cout << ans << endl;

	return 0;
}
