// URL: https://atcoder.jp/contests/abc176/submissions/16176649
// Date: Sun, 23 Aug 2020 17:07:18 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

i64 dh[4] = {-1, 1, 0, 0}, dw[4] = {0, 0, -1, 1};

int main()
{
  i64 H, W, Ch, Cw, Dh, Dw;
  cin >> H >> W >> Ch >> Cw >> Dh >> Dw;
  Ch--;
  Cw--;
  Dh--;
  Dw--;
  vector<string> S(H);
  for (i64 i = 0; i < H; i++)
    cin >> S[i];
  vector<vector<i64>> dis(H, vector<i64>(W, 1e9));
  deque<pair<i64, i64>> que;
  dis[Ch][Cw] = 0;
  que.push_back({Ch, Cw});
  while (que.size())
  {
    pair<i64, i64> p = que.front();
    que.pop_front();
    for (i64 i = 0; i < 4; i++)
    {
      i64 ddh = p.first + dh[i], ddw = p.second + dw[i];
      if (ddh < 0 || H <= ddh || ddw < 0 || W <= ddw || S[ddh][ddw] == '#' || dis[ddh][ddw] <= dis[p.first][p.second])
        continue;
      dis[ddh][ddw] = dis[p.first][p.second];
      que.push_front({ddh, ddw});
    }
    for (i64 i = -2; i < 3; i++)
      for (i64 j = -2; j < 3; j++)
      {
        i64 ddh = p.first + i, ddw = p.second + j;
        if (ddh < 0 || H <= ddh || ddw < 0 || W <= ddw || S[ddh][ddw] == '#' || dis[ddh][ddw] <= dis[p.first][p.second] + 1)
          continue;
        dis[ddh][ddw] = dis[p.first][p.second] + 1;
        que.push_back({ddh, ddw});
      }
  }
  cout << (dis[Dh][Dw] == 1e9 ? -1 : dis[Dh][Dw]) << endl;
  return 0;
}
