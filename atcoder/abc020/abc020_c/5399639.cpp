// URL: https://atcoder.jp/contests/abc020/submissions/5399639
// Date: Tue, 14 May 2019 21:25:02 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

i64 h, w, t;
vector<string> s;

i64 sh, sw, gh, gw;
i64 dh[4] = {1, -1, 0, 0}, dw[4] = {0, 0, 1, -1};

bool calc(i64 x)
{
  priority_queue<pair<i64, pair<i64, i64>>, vector<pair<i64, pair<i64, i64>>>, greater<pair<i64, pair<i64, i64>>>> que;
  vector<vector<i64>> far(h, vector<i64>(w, 1e18));
  far[sh][sw] = 0;
  que.push({0, {sh, sw}});
  while (que.size())
  {
    pair<i64, pair<i64, i64>> p = que.top();
    que.pop();
    for (i64 i = 0; i < 4; i++)
    {
      i64 hh = p.second.first + dh[i], ww = p.second.second + dw[i];
      if (0 <= hh && hh < h && 0 <= ww && ww < w)
      {
        if (s[hh][ww] == '#' && far[p.second.first][p.second.second] + x < far[hh][ww])
        {
          far[hh][ww] = far[p.second.first][p.second.second] + x;
          que.push({far[hh][ww], {hh, ww}});
        }
        else if (s[hh][ww] != '#' && far[p.second.first][p.second.second] + 1 < far[hh][ww])
        {
          far[hh][ww] = far[p.second.first][p.second.second] + 1;
          que.push({far[hh][ww], {hh, ww}});
        }
      }
    }
  }
  return (far[gh][gw] <= t);
}

int main()
{
  cin >> h >> w >> t;
  s.resize(h);
  for (i64 i = 0; i < h; i++)
    cin >> s[i];
  for (i64 i = 0; i < h; i++)
    for (i64 j = 0; j < w; j++)
      if (s[i][j] == 'S')
      {
        sh = i;
        sw = j;
      }
      else if (s[i][j] == 'G')
      {
        gh = i;
        gw = j;
      }
  i64 ng = t, ok = 1;
  while (1 < ng - ok)
  {
    i64 mid = (ng + ok) / 2;
    if (calc(mid))
      ok = mid;
    else
      ng = mid;
  }
  cout << ok << endl;
  return 0;
}
