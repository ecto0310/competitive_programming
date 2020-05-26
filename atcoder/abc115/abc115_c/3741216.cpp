// URL: https://atcoder.jp/contests/abc115/submissions/3741216
// Date: Sat, 08 Dec 2018 21:16:42 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> h(n);
	for (int i = 0; i < n; i++)
		cin >> h[i];
	sort(h.begin(), h.end());
	int ans = 1e9;
	for (int i = 0; i < n - k + 1; i++)
		ans = min(ans, h[i + k - 1] - h[i]);
	cout << ans << endl;

	return 0;
}
