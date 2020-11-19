// URL: https://atcoder.jp/contests/abc174/submissions/15605241
// Date: Sun, 02 Aug 2020 21:09:57 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 K;
  cin >> K;
  set<i64> s;
  i64 t = 7;
  for (i64 i = 1;; i++)
  {
    if (t % K == 0)
    {
      cout << i << endl;
      return 0;
    }
    if (s.count(t % K) == 1)
    {
      cout << -1 << endl;
      return 0;
    }
    s.insert(t % K);
    (t = t * 10 + 7)%=K;
  }
  return 0;
}
