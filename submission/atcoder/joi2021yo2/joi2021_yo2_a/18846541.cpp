// URL: https://atcoder.jp/contests/joi2021yo2/submissions/18846541
// Date: Fri, 18 Dec 2020 23:57:57 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N, A;
  string S;
  cin >> N >> A >> S;
  vector<i64> b{0};
  for (i64 i = 0; i < N; i++)
    if (S[i] == '#')
      b.push_back(i + 1);
  b.push_back(N + 1);
  i64 ans = 0, now = A;
  i64 l = b[upper_bound(b.begin(), b.end(), A) - b.begin() - 1];
  i64 r = b[lower_bound(b.begin(), b.end(), A) - b.begin()];
  for (i64 i = 0; l != 0 || r != N + 1; i++)
    if (i % 2 == 0)
    {
      i64 it = lower_bound(b.begin(), b.end(), r) - b.begin();
      if (it == b.size() - 1)
      {
        ans += N + 1 - now;
        now = N + 1;
        r = N + 1;
      }
      else
      {
        ans += b[it] - now;
        now = b[it];
        r = b[it + 1];
      }
    }
    else
    {
      i64 it = upper_bound(b.begin(), b.end(), l) - b.begin() - 1;
      if (it <= 0)
      {
        ans += now;
        now = 0;
        l = 0;
      }
      else
      {
        ans += now - b[it];
        now = b[it];
        l = b[it - 1];
      }
    }
  cout << ans << endl;
  return 0;
}
