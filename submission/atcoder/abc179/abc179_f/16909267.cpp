// URL: https://atcoder.jp/contests/abc179/submissions/16909267
// Date: Sun, 20 Sep 2020 18:05:01 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N, Q;
  cin >> N >> Q;
  i64 ans = (N - 2) * (N - 2);
  vector<i64> a(N + 1, N), b(N + 1, N);
  i64 H = N, W = N;
  for (i64 _ = 0; _ < Q; _++)
  {
    i64 t, x;
    cin >> t >> x;
    if (t == 1)
    {
      if (x < W)
      {
        for (i64 i = x; i < W; i++)
          b[i] = H;
        W = x;
      }
      ans -= b[x] - 2;
    }
    else
    {
      if (x < H)
      {
        for (i64 i = x; i < H; i++)
          a[i] = W;
        H = x;
      }
      ans -= a[x] - 2;
    }
  }
  cout << ans << endl;
  return 0;
}
