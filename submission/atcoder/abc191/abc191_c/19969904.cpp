// URL: https://atcoder.jp/contests/abc191/submissions/19969904
// Date: Sat, 06 Feb 2021 21:17:25 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

string tmp[8][2] = {
    {"..",
     ".#"},
    {".#",
     "##"},
    {"..",
     "#."},
    {"#.",
     "##"},
    {"#.",
     ".."},
    {"##",
     "#."},
    {".#",
     ".."},
    {"##",
     ".#"},
};

int main()
{
  i64 H, W;
  cin >> H >> W;
  vector<string> S(H);
  for (i64 i = 0; i < H; i++)
    cin >> S[i];
  i64 ans = 0;
  for (i64 i = 0; i < H - 1; i++)
    for (i64 j = 0; j < W - 1; j++)
    {
      for (i64 k = 0; k < 8; k++)
      {
        bool ok = true;
        for (i64 l = 0; l < 2; l++)
          for (i64 m = 0; m < 2; m++)
            if (S[i + l][j + m] != tmp[k][l][m])
              ok = false;
        if (ok)
          ans++;
      }
    }
  cout << ans << endl;
  return 0;
}
