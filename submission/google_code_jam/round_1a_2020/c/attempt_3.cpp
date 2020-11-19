#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

struct People
{
  i64 L, R, U, D;
  i64 val;
  bool vis = true;
};

i64 H, W;
vector<vector<People>> people;
vector<pair<i64, i64>> rem, rem2;

bool ng(i64 x, i64 y)
{
  i64 cnt = 1, sum = people[x][y].val;
  if (0 <= people[x][y].L)
  {
    cnt++;
    sum += people[x][people[x][y].L].val;
  }
  if (people[x][y].R < W)
  {
    cnt++;
    sum += people[x][people[x][y].R].val;
  }
  if (0 <= people[x][y].U)
  {
    cnt++;
    sum += people[people[x][y].U][y].val;
  }
  if (people[x][y].D < H)
  {
    cnt++;
    sum += people[people[x][y].D][y].val;
  }
  return people[x][y].val * cnt < sum;
}

int main()
{
  i64 T;
  cin >> T;
  for (i64 _ = 1; _ <= T; _++)
  {
    cin >> H >> W;
    people.resize(H);
    i64 sum = 0;
    for (i64 i = 0; i < H; i++)
    {
      people[i].resize(W);
      for (i64 j = 0; j < W; j++)
      {
        i64 S;
        cin >> S;
        people[i][j] = {j - 1, j + 1, i - 1, i + 1, S};
        sum += S;
      }
    }
    for (i64 i = 0; i < H; i++)
      for (i64 j = 0; j < W; j++)
        if (ng(i, j))
          rem.push_back({i, j});
    i64 ans = sum;
    while (rem.size())
    {
      rem2.clear();
      for (pair<i64, i64> i : rem)
      {
        i64 x = i.first, y = i.second;
        sum -= people[x][y].val;
        people[x][y].vis = false;
        if (0 <= people[x][y].L)
        {
          rem2.push_back({x, people[x][y].L});
          people[x][people[x][y].L].R = people[x][y].R;
        }
        if (people[x][y].R < W)
        {
          rem2.push_back({x, people[x][y].R});
          people[x][people[x][y].R].L = people[x][y].L;
        }
        if (0 <= people[x][y].U)
        {
          rem2.push_back({people[x][y].U, y});
          people[people[x][y].U][y].D = people[x][y].D;
        }
        if (people[x][y].D < H)
        {
          rem2.push_back({people[x][y].D, y});
          people[people[x][y].D][y].U = people[x][y].U;
        }
      }
      rem.clear();
      sort(rem2.begin(), rem2.end());
      rem2.erase(unique(rem2.begin(), rem2.end()), rem2.end());
      for (pair<i64, i64> i : rem2)
        if (people[i.first][i.second].vis && ng(i.first, i.second))
          rem.push_back(i);
      ans += sum;
    }
    cout << "Case #" << _ << ": " << ans << endl;
  }
  return 0;
}
