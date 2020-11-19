// URL: https://atcoder.jp/contests/abc026/submissions/3593717
// Date: Tue, 13 Nov 2018 16:36:37 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> r(n);
	for (int i = 0; i < n; i++)
		cin >> r[i];
	sort(r.begin(), r.end(), greater<int>());
	int sum = 0;
	for (int i = 0; i < n; i++)
		if (i % 2 == 0)
			sum += r[i] * r[i];
		else
			sum -= r[i] * r[i];
	cout << fixed << setprecision(7) << M_PI * sum << endl;

	return 0;
}
