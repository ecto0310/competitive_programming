// URL: https://atcoder.jp/contests/chokudai004/submissions/7229776
// Date: Sat, 31 Aug 2019 21:58:29 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

const int timeLimit = 2990;

int n, b[3];
int l[30][30], r[30][30];
int cnt[3];

i64 xsum[31], ysum[31];

vector<vector<i64>> ans;

void input()
{
  cin >> n >> b[0] >> b[1] >> b[2];
  for (i64 i = 0; i < n; i++)
    for (i64 j = 0; j < n; j++)
      cin >> l[i][j];
  for (i64 i = 0; i < n; i++)
    for (i64 j = 0; j < n; j++)
      cin >> r[i][j];
  ans.resize(n, vector<i64>(n));
}

void output()
{
  for (i64 i = 0; i < n; i++)
    for (i64 j = 0; j < n; j++)
      cout << ans[i][j] << (j + 1 == n ? "\n" : " ");
}

i64 calc(vector<vector<i64>> tmp, i64 x, i64 y, i64 next = -1)
{
  // if (next == -1)
  // {
  //   for (i64 i = 0; i <= n; i++)
  //   {
  //     xsum[i] = 0;
  //     ysum[i] = 0;
  //   }
  //   for (i64 i = 0; i < n; i++)
  //   {
  //     xsum[i + 1] = xsum[i] + tmp[i][y];
  //     ysum[i + 1] = ysum[i] + tmp[x][i];
  //   }
  //   for (i64 i = 0; i <= n; i++)
  //     for (i64 j = i; j <= n; j++)
  //     {
  //       i64 xtmp = xsum[j] - xsum[i], ytmp = ysum[j] - ysum[i];
  //       for (i64 k = 0; k < 3; k++)
  //       {
  //         if (xtmp == b[k])
  //           cnt[k]--;
  //         if (ytmp == b[k])
  //           cnt[k]--;
  //       }
  //     }
  //   tmp[x][y] = next;
  // }
  // for (i64 i = 0; i <= n; i++)
  // {
  //   xsum[i] = 0;
  //   ysum[i] = 0;
  // }
  // for (i64 i = 0; i < n; i++)
  // {
  //   xsum[i + 1] = xsum[i] + tmp[i][y];
  //   ysum[i + 1] = ysum[i] + tmp[x][i];
  // }
  // for (i64 i = 0; i <= n; i++)
  //   for (i64 j = i; j <= n; j++)
  //   {
  //     i64 xtmp = xsum[j] - xsum[i], ytmp = ysum[j] - ysum[i];
  //     for (i64 k = 0; k < 3; k++)
  //     {
  //       if (xtmp == b[k])
  //         cnt[k]++;
  //       if (ytmp == b[k])
  //         cnt[k]++;
  //     }
  //   }
  i64 point = 0;

  //tate
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      int now = 0;
      for (int k = i; k < n; k++)
      {
        now += ans[k][j];
        if (now == b[0])
          point += b[0];
        if (now == b[1])
          point += b[1];
        if (now == b[2])
          point += b[2];
        if (now > b[2])
          break;
      }
    }
  }

  //yoko
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      int now = 0;
      for (int k = j; k < n; k++)
      {
        now += ans[i][k];
        if (now == b[0])
          point += b[0];
        if (now == b[1])
          point += b[1];
        if (now == b[2])
          point += b[2];
        if (now > b[2])
          break;
      }
    }
  }
  return point;
  return cnt[0] * b[0] + cnt[1] * b[1] + cnt[2] * b[2];
}

void init()
{
  for (i64 i = 0; i < n; i++)
    for (i64 j = 0; j < n; j++)
      ans[i][j] = l[i][j] + rand() % (r[i][j] - l[i][j] + 1);
  // for (int i = 0; i < n; i++)
  //   calc(ans, i, i);
}

void solve()
{
  chrono::system_clock::time_point start = chrono::system_clock::now();

  i64 bestscore = 0;

  while (chrono::duration_cast<chrono::microseconds>(chrono::system_clock::now() - start).count() / 1000 < timeLimit)
  {
    //i64 x = rand() % n, y = rand() % n, next = l[x][y] + rand() % (r[x][y] - l[x][y] + 1);
    //i64 score = calc(ans, x, y, next);
    init();
    i64 score = calc(ans,0,0);
    if (bestscore < score)
    {
      bestscore = score;
      //ans[x][y] = next;
    }
  }
  cerr << "best" << bestscore << endl;
}

int main()
{
  input();
  init();
  solve();
  cerr << endl;
  output();
  return 0;
}
