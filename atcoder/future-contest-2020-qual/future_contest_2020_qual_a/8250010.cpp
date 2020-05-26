// URL: https://atcoder.jp/contests/future-contest-2020-qual/submissions/8250010
// Date: Sat, 02 Nov 2019 16:21:01 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

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
char math[60][60];

i64 dy[4] = {1, -1, 0, 0}, dx[4] = {0, 0, 1, -1};
char dm[4] = {'U', 'D', 'L', 'R'};

int main()
{
  cin >> n >> m >> b;
  cin >> gy >> gx;
  for (i64 i = 0; i < n; i++)
    for (i64 j = 0; j < n; j++)
      math[i][j] = '-';
  math[gy][gx] = 'g';
  for (i64 i = 0; i < m; i++)
  {
    cin >> robot[i].y >> robot[i].x >> robot[i].c;
    robot[i].far = (robot[i].y - gy) * (robot[i].y - gy) + (robot[i].x - gx) * (robot[i].x - gx);
  }
  for (i64 i = 0; i < b; i++)
  {
    i64 by, bx;
    cin >> by >> bx;
    math[by][bx] = 'b';
  }
  sort(robot, robot + m);
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
  for (i64 i = 0; i < n; i++)
    for (i64 j = 0; j < n; j++)
      if (math[i][j] != 'b' && math[i][j] != '-' && math[i][j] != 'g')
      {
        char now = math[i][j];
        math[i][j] = '-';
        i64 cnt = 0;
        for (i64 k = 0; k < m; k++)
        {
          Robot tmp = robot[k];
          for (i64 l = 0; l < 2000; l++)
          {
            if (math[tmp.y][tmp.x] == 'g')
            {
              cnt++;
              break;
            }
            else if (math[tmp.y][tmp.x] == 'b')
              break;
            else if (math[tmp.y][tmp.x] != '-')
              tmp.c = math[tmp.y][tmp.x];
            if (tmp.c == 'U')
              tmp.y = (tmp.y - 1 + n) % n;
            else if (tmp.c == 'D')
              tmp.y = (tmp.y + 1 + n) % n;
            else if (tmp.c == 'L')
              tmp.x = (tmp.x - 1 + n) % n;
            else if (tmp.c == 'R')
              tmp.x = (tmp.x + 1 + n) % n;
          }
        }
        if (cnt != m)
          math[i][j] = now;
      }
  i64 cnt = 0;
  for (i64 i = 0; i < n; i++)
    for (i64 j = 0; j < n; j++)
      if (math[i][j] != 'b' && math[i][j] != '-' && math[i][j] != 'g')
        cnt++;
  cout << cnt << endl;
  for (i64 i = 0; i < n; i++)
    for (i64 j = 0; j < n; j++)
      if (math[i][j] != 'b' && math[i][j] != '-' && math[i][j] != 'g')
        cout << i << " " << j << " " << math[i][j] << endl;
  return 0;
}
