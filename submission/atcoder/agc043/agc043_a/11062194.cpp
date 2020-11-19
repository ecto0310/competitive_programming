// URL: https://atcoder.jp/contests/agc043/submissions/11062194
// Date: Sat, 21 Mar 2020 23:47:40 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 H, W;
  cin >> H >> W;
  vector<string> s(H);
  for (i64 i = 0; i < H; i++)
    cin >> s[i];
  vector<vector<i64>> far(H, vector<i64>(W));
  far[0][0] = (s[0][0] == '#');
  for (i64 i = 1; i < W; i++)
    far[0][i] = far[0][i - 1] + (s[0][i - 1] == '.' && s[0][i] == '#');
  for (i64 i = 1; i < H; i++)
  {
    far[i][0] = far[i - 1][0] + (s[i - 1][0] == '.' && s[i][0] == '#');
    for (i64 j = 1; j < W; j++)
      far[i][j] = min(far[i - 1][j] + (s[i - 1][j] == '.' && s[i][j] == '#'), far[i][j - 1] + (s[i][j - 1] == '.' && s[i][j] == '#'));
  }
  cout << far[H - 1][W - 1] << endl;
  return 0;
}
