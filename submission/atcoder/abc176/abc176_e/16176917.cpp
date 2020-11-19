// URL: https://atcoder.jp/contests/abc176/submissions/16176917
// Date: Sun, 23 Aug 2020 17:17:03 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 H, W, M;
  cin >> H >> W >> M;
  vector<i64> h(M), w(M);
  for (i64 i = 0; i < M; i++)
    cin >> h[i] >> w[i];
  map<i64, i64> hCnt, wCnt;
  set<pair<i64, i64>> bom;
  for (i64 i = 0; i < M; i++)
  {
    hCnt[h[i]]++;
    wCnt[w[i]]++;
    bom.insert({h[i], w[i]});
  }
  i64 hMax = 0, wMax = 0;
  for (pair<i64, i64> i : hCnt)
    hMax = max(hMax, i.second);
  for (pair<i64, i64> i : wCnt)
    wMax = max(wMax, i.second);
  set<i64> hSet, wSet;
  for (pair<i64, i64> i : hCnt)
    if (hMax == i.second)
      hSet.insert(i.first);
  for (pair<i64, i64> i : wCnt)
    if (wMax == i.second)
      wSet.insert(i.first);
  for (i64 i : hSet)
    for (i64 j : wSet)
      if (bom.count({i, j}) == 0)
      {
        cout << hMax + wMax << endl;
        return 0;
      }
  cout << hMax + wMax - 1 << endl;
  return 0;
}
