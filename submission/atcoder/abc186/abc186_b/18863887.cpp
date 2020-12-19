// URL: https://atcoder.jp/contests/abc186/submissions/18863887
// Date: Sat, 19 Dec 2020 21:02:49 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 H, W;
  cin >> H >> W;
  vector<vector<i64>> A(H, vector<i64>(W));
  for (i64 i = 0; i < H; i++)
    for (i64 j = 0; j < W; j++)
      cin >> A[i][j];
  i64 m = 1e9;
  for (i64 i = 0; i < H; i++)
    for (i64 j = 0; j < W; j++)
      m = min(m, A[i][j]);
  i64 ans = 0;
  for (i64 i = 0; i < H; i++)
    for (i64 j = 0; j < W; j++)
      ans += A[i][j] - m;
  cout << ans << endl;
  return 0;
}
