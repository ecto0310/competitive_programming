// URL: https://atcoder.jp/contests/abc119/submissions/4375091
// Date: Sun, 24 Feb 2019 22:05:40 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>

using namespace std;

struct Data
{
  int cost;
  vector<int> l;

  bool operator<(const Data &other) const
  {
    return cost > other.cost;
  }
};

int main()
{
  int N, A, B, C;
  cin >> N >> A >> B >> C;
  vector<int> l(N);
  for (int i = 0; i < N; i++)
    cin >> l[i];
  int ans = 1e9;
  for (int a = 0; a < (1 << N); a++)
    for (int b = 0; a + b < (1 << N); b++)
    {
      int tmp = 0;
      vector<int> stick[3], cost(3, (int)1e5);
      vector<pair<int, int>> change[3];
      for (int i = 0; i < N; i++)
        if (a & (1 << i))
          stick[0].push_back(l[i]);
        else if (b & (1 << i))
          stick[1].push_back(l[i]);
        else
          stick[2].push_back(l[i]);
      for (int i = 0; i < 3; i++)
        for (int j = 0; j < (1 << stick[i].size()); j++)
          if (j != 0)
          {
            int tmp = 0, cost = -1;
            for (int k = 0; k < stick[i].size(); k++)
              if (j & (1 << k))
              {
                cost++;
                tmp += stick[i][k];
              }
            change[i].push_back({cost * 10, tmp});
          }
      if (change[0].size() == 0 || change[1].size() == 0 || change[2].size() == 0)
        continue;
      for (pair<int, int> t : change[0])
        cost[0] = min(cost[0], abs(t.second - A) + t.first);
      for (pair<int, int> t : change[1])
        cost[1] = min(cost[1], abs(t.second - B) + t.first);
      for (pair<int, int> t : change[2])
        cost[2] = min(cost[2], abs(t.second - C) + t.first);
      ans = min(ans, cost[0] + cost[1] + cost[2]);
    }
  cout << ans << endl;

  return 0;
}
