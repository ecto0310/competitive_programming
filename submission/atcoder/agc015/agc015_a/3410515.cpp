// URL: https://atcoder.jp/contests/agc015/submissions/3410515
// Date: Mon, 15 Oct 2018 00:37:42 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	long long n, a, b;
	cin >> n >> a >> b;
	cout << max((long long)0, (n - 2) * b - (n - 2) * a + 1) << endl;

	return 0;
}
