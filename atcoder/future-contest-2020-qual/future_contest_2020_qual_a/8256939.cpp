// URL: https://atcoder.jp/contests/future-contest-2020-qual/submissions/8256939
// Date: Sat, 02 Nov 2019 20:47:30 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int timeLimit = 2940;

struct Robot
{
  i64 y, x;
  char c;
  i64 far;

  bool operator<(const Robot &right) const
  {
    return far < right.far;
  }
};

i64 n, m, b;
i64 gy, gx;
Robot robot[100];
vector<vector<char>> def(40, vector<char>(40, '-')), ans(40, vector<char>(40, '-'));
vector<vector<vector<char>>> r(40, vector<vector<char>>(40));

i64 dy[4] = {1, -1, 0, 0},
    dx[4] = {0, 0, 1, -1};
char dm[4] = {'U', 'D', 'L', 'R'};

int main()
{
  chrono::system_clock::time_point start = chrono::system_clock::now();
  cin >> n >> m >> b;
  cin >> gy >> gx;
  def[gy][gx] = 'g';
  for (i64 i = 0; i < m; i++)
  {
    cin >> robot[i].y >> robot[i].x >> robot[i].c;
    robot[i].far = (robot[i].y - gy) * (robot[i].y - gy) + (robot[i].x - gx) * (robot[i].x - gx);
    r[robot[i].y][robot[i].x].push_back(robot[i].c);
  }
  for (i64 i = 0; i < b; i++)
  {
    i64 by, bx;
    cin >> by >> bx;
    def[by][bx] = 'b';
  }
  sort(robot, robot + m);
  i64 s = 1e9;

  while (chrono::duration_cast<chrono::microseconds>(chrono::system_clock::now() - start).count() / 1000 < timeLimit)
  {
    vector<vector<char>> math = def;
    for (i64 i = 0; i < m; i++)
    {
      queue<pair<i64, i64>> que;
      vector<vector<i64>> tmp(n, vector<i64>(n, 1e9));
      que.push({robot[i].y, robot[i].x});
      tmp[robot[i].y][robot[i].x] = 0;
      while (que.size())
      {
        pair<i64, i64> p = que.front();
        que.pop();
        for (i64 j = 0; j < 4; j++)
          if (math[(p.first + dy[j] + n) % n][(p.second + dx[j] + n) % n] != 'b' && tmp[p.first][p.second] + 1 < tmp[(p.first + dy[j] + n) % n][(p.second + dx[j] + n) % n])
          {
            tmp[(p.first + dy[j] + n) % n][(p.second + dx[j] + n) % n] = tmp[p.first][p.second] + 1;
            que.push({(p.first + dy[j] + n) % n, (p.second + dx[j] + n) % n});
          }
      }
      i64 f = 1e9, fy, fx;
      for (i64 j = 0; j < n; j++)
        for (i64 k = 0; k < n; k++)
          if (math[j][k] != 'b' && math[j][k] != '-' && tmp[j][k] < f)
          {
            f = tmp[j][k];
            fy = j;
            fx = k;
          }
      if (f != 1e9)
        for (i64 j = 0; j < f; j++)
        {
          for (i64 k = 0; k < 4; k++)
            if (tmp[(fy + dy[k] + n) % n][(fx + dx[k] + n) % n] < tmp[fy][fx])
            {
              math[(fy + dy[k] + n) % n][(fx + dx[k] + n) % n] = dm[k];
              fy = (fy + dy[k] + n) % n;
              fx = (fx + dx[k] + n) % n;
              break;
            }
        }
    }
    //
    queue<pair<i64, i64>> que;
    vector<vector<i64>> tmp(n, vector<i64>(n, 1e9));
    que.push({gy, gx});
    tmp[gy][gx] = 0;
    while (que.size())
    {
      pair<i64, i64> p = que.front();
      que.pop();
      bool ok = true;
      if (math[p.first][p.second] == 'U' || math[p.first][p.second] == 'D')
      {
        if (math[p.first][(p.second + 1 + n) % n] == 'L')
          ok = false;
        if (math[p.first][(p.second - 1 + n) % n] == 'R')
          ok = false;
      }
      if (math[p.first][p.second] == 'L' || math[p.first][p.second] == 'R')
      {
        if (math[(p.first + 1 + n) % n][p.second] == 'U')
          ok = false;
        if (math[(p.first - 1 + n) % n][p.second] == 'D')
          ok = false;
      }
      for (char i : r[p.first][p.second])
        if (math[p.first][p.second] != i)
          ok = false;
      for (i64 i = 0; i < 4; i++)
        if (math[(p.first + dy[i] + n) % n][(p.second + dx[i] + n) % n] == dm[i])
        {
          tmp[(p.first + dy[i] + n) % n][(p.second + dx[i] + n) % n] = tmp[p.first][p.second] + 1;
          que.push({(p.first + dy[i] + n) % n, (p.second + dx[i] + n) % n});
        }
      if (ok)
        math[p.first][p.second] = '-';
    }
    i64 cnt = 0;
    for (i64 i = 0; i < n; i++)
      for (i64 j = 0; j < n; j++)
        if (math[i][j] != 'b' && math[i][j] != '-' && math[i][j] != 'g')
          cnt++;
    if (cnt < s)
    {
      s = cnt;
      ans = math;
    }
    swap(robot[rand() % m], robot[rand() % m]);
  }
  cout << s << endl;
  for (i64 i = 0; i < n; i++)
    for (i64 j = 0; j < n; j++)
      if (ans[i][j] != 'b' && ans[i][j] != '-' && ans[i][j] != 'g')
        cout << i << " " << j << " " << ans[i][j] << endl;
  return 0;
}
