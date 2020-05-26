// URL: https://atcoder.jp/contests/abc009/submissions/3600402
// Date: Wed, 14 Nov 2018 23:40:02 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end(), greater<int>());
	for (int i = 1; i < n; i++)
		if (a[i - 1] != a[i])
		{
			cout << a[i] << endl;
			break;
		}

	return 0;
}
