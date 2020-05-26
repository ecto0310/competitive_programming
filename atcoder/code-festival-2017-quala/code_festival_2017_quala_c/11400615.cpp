// URL: https://atcoder.jp/contests/code-festival-2017-quala/submissions/11400615
// Date: Wed, 01 Apr 2020 01:17:57 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 H, W;
  cin >> H >> W;
  vector<string> a(H);
  for (i64 i = 0; i < H; i++)
    cin >> a[i];
  vector<i64> cnt(26);
  for (i64 i = 0; i < H; i++)
    for (i64 j = 0; j < W; j++)
      cnt[a[i][j] - 'a']++;
  i64 t = 0;
  for (i64 i = 0; i < 26; i++)
    if (cnt[i] % 2 == 1)
      t++;
  if (1 < t)
  {
    cout << "No" << endl;
    return 0;
  }
  i64 tc = 0;
  for (i64 i = 0; i < 26; i++)
  {
    if (cnt[i] % 2 == 1)
      cnt[i]--;
    tc += cnt[i] / 4;
  }
  if ((H / 2) * (W / 2) <= tc)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
