// URL: https://atcoder.jp/contests/abc055/submissions/4632725
// Date: Tue, 19 Mar 2019 20:39:36 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

const int MOD = 1e9 + 7;

int main()
{
  long long n, m;
	cin >> n >> m;
	cout << min(n, m / 2) + (n < m / 2 ? (m - 2 * n) / 4 : 0) << endl;

  return 0;
}
