// URL: https://atcoder.jp/contests/abc160/submissions/11305819
// Date: Sat, 28 Mar 2020 22:11:54 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 X, Y, A, B, C;
  cin >> X >> Y >> A >> B >> C;
  vector<pair<i64, i64>> ap(A + B + C);
  for (i64 i = 0; i < A; i++)
  {
    cin >> ap[i].first;
    ap[i].second = 0;
  }
  for (i64 i = A; i < A + B; i++)
  {
    cin >> ap[i].first;
    ap[i].second = 1;
  }
  for (i64 i = A + B; i < A + B + C; i++)
  {
    cin >> ap[i].first;
    ap[i].second = 2;
  }
  sort(ap.rbegin(), ap.rend());
  i64 ans = 0;
  i64 e[3] = {};
  for (i64 i = 0; i < A + B + C; i++)
  {
    if (ap[i].second == 0 && e[0] < X)
    {
      ans += ap[i].first;
      e[0]++;
    }
    if (ap[i].second == 1 && e[1] < Y)
    {
      ans += ap[i].first;
      e[1]++;
    }
    if (ap[i].second == 2)
    {
      ans += ap[i].first;
      e[2]++;
    }
    if (e[0] + e[1] + e[2] == X + Y)
      break;
  }
  cout << ans << endl;
  return 0;
}
