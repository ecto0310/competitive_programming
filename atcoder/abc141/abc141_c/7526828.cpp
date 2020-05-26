// URL: https://atcoder.jp/contests/abc141/submissions/7526828
// Date: Sun, 15 Sep 2019 21:19:46 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, k, q;
  cin >> n >> k >> q;
  vector<i64> p(n);
  for (i64 i = 0; i < q; i++)
  {
    i64 a;
    cin >> a;
    p[a - 1]++;
  }
  for (i64 i = 0; i < n; i++)
    if (0 < p[i] + k - q)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  return 0;
}
