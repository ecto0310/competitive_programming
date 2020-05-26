// URL: https://atcoder.jp/contests/agc036/submissions/6491849
// Date: Sun, 21 Jul 2019 21:39:26 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 s;
  cin >> s;
  i64 ng = -1, ok = 1e9 + 1;
  while (1 < ok - ng)
  {
    i64 mid = (ok + ng) / 2;
    if (mid * mid < s)
      ng = mid;
    else
      ok = mid;
  }
  i64 n = ok * ok - s;
  for (i64 i = 1;; i++)
    if (n % i == 0)
    {
      cout << 0 << " " << 0 << " " << ok << " " << i << " " << n / i << " " << ok << endl;
      return 0;
    }
  return 0;
}
