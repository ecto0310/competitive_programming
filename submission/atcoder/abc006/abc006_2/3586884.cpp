// URL: https://atcoder.jp/contests/abc006/submissions/3586884
// Date: Mon, 12 Nov 2018 01:15:55 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> tri = {0, 0, 1};
	tri.resize(n);
	for (int i = 3; i < n; i++)
		tri[i] = (tri[i - 1] + tri[i - 2] + tri[i - 3]) % 10007;
	cout << tri[n - 1] << endl;

	return 0;
}
