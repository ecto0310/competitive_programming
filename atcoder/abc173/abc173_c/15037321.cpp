// URL: https://atcoder.jp/contests/abc173/submissions/15037321
// Date: Mon, 06 Jul 2020 13:19:59 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 H, W, K;
  cin >> H >> W >> K;
  vector<string> c(H);
  for (i64 i = 0; i < H; i++)
    cin >> c[i];
  i64 ans = 0;
  for (i64 i = 0; i < (1 << H); i++)
    for (i64 j = 0; j < (1 << W); j++)
    {
      i64 cnt = 0;
      for (i64 k = 0; k < H; k++)
        for (i64 l = 0; l < W; l++)
          if (c[k][l] == '#' && !((i >> k) & 1) && !((j >> l) & 1))
            cnt++;
      if (cnt == K)
        ans++;
    }
  cout << ans << endl;
  return 0;
}
