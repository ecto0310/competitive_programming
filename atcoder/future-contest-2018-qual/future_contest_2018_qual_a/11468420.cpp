// URL: https://atcoder.jp/contests/future-contest-2018-qual/submissions/11468420
// Date: Sat, 04 Apr 2020 00:23:00 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

const int timeLimit = 5800;

const int N = 100, Q = 1000;
int A[N][N];
int ans[Q][3];
int diff[N][N];
int tmpAns[3], beforeAns[3];

const int dx[4] = {1, -1, -1, 1}, dy[] = {1, 1, -1, -1};

void init()
{
  for (int i = 0; i < Q; i++)
  {
    ans[i][0] = rand() % N;
    ans[i][1] = rand() % N;
    ans[i][2] = rand() % N + 1;
  }
}

bool outMap(int x, int y)
{
  return !(0 <= x && x < N && 0 <= y && y < N);
}

void makeDiff()
{
  int map[N][N] = {};
  for (int i = 0; i < Q; i++)
  {
    int x = ans[i][0];
    int y = ans[i][1];
    int h = ans[i][2];
    map[x][y] += h;
    for (int p = 1; p < h; p++)
    {
      int d = h - p;
      x = ans[i][0];
      y = ans[i][1] - d;
      for (int j = 0; j < 4; j++)
      {
        for (int k = 0; k < d; k++)
        {
          x = x + dx[j];
          y = y + dy[j];
          if (outMap(x, y))
          {
            continue;
          }
          map[x][y] += p;
        }
      }
    }
  }

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      diff[i][j] = A[i][j] - map[i][j];
    }
  }
  return;
}

void reverseDiff()
{
  int x = tmpAns[0];
  int y = tmpAns[1];
  int h = tmpAns[2];
  diff[x][y] += h;
  for (int p = 1; p < h; p++)
  {
    int d = h - p;
    x = tmpAns[0];
    y = tmpAns[1] - d;
    for (int j = 0; j < 4; j++)
    {
      for (int k = 0; k < d; k++)
      {
        x = x + dx[j];
        y = y + dy[j];
        if (outMap(x, y))
        {
          continue;
        }
        diff[x][y] += p;
      }
    }
  }

  x = beforeAns[0];
  y = beforeAns[1];
  h = beforeAns[2];
  diff[x][y] -= h;
  for (int p = 1; p < h; p++)
  {
    int d = h - p;
    x = beforeAns[0];
    y = beforeAns[1] - d;
    for (int j = 0; j < 4; j++)
    {
      for (int k = 0; k < d; k++)
      {
        x = x + dx[j];
        y = y + dy[j];
        if (outMap(x, y))
        {
          continue;
        }
        diff[x][y] -= p;
      }
    }
  }
}

void updateDiff()
{
  int x = beforeAns[0];
  int y = beforeAns[1];
  int h = beforeAns[2];
  diff[x][y] += h;
  for (int p = 1; p < h; p++)
  {
    int d = h - p;
    x = beforeAns[0];
    y = beforeAns[1] - d;
    for (int j = 0; j < 4; j++)
    {
      for (int k = 0; k < d; k++)
      {
        x = x + dx[j];
        y = y + dy[j];
        if (outMap(x, y))
        {
          continue;
        }
        diff[x][y] += p;
      }
    }
  }

  x = tmpAns[0];
  y = tmpAns[1];
  h = tmpAns[2];
  diff[x][y] -= h;
  for (int p = 1; p < h; p++)
  {
    int d = h - p;
    x = tmpAns[0];
    y = tmpAns[1] - d;
    for (int j = 0; j < 4; j++)
    {
      for (int k = 0; k < d; k++)
      {
        x = x + dx[j];
        y = y + dy[j];
        if (outMap(x, y))
        {
          continue;
        }
        diff[x][y] -= p;
      }
    }
  }
}

void simulate()
{
  chrono::system_clock::time_point start = chrono::system_clock::now();
  chrono::system_clock::time_point end = start + chrono::milliseconds(timeLimit);
  makeDiff();
  i64 bestScore = 0;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      bestScore += diff[i][j] * diff[i][j];
    }
  }

  int loop = 0;

  chrono::system_clock::time_point currentTime = chrono::system_clock::now();
  double C = timeLimit * 100;
  double force;
  while (currentTime < end)
  {
    loop++;
    int n = rand() % Q;
    beforeAns[0] = ans[n][0];
    beforeAns[1] = ans[n][1];
    beforeAns[2] = ans[n][2];
    tmpAns[0] = min(N - 1, max(0, beforeAns[0] + (rand() % 3 - 1)));
    tmpAns[1] = min(N - 1, max(0, beforeAns[1] + (rand() % 3 - 1)));
    tmpAns[2] = min(N, max(1, beforeAns[2] + (rand() % 3 - 1)));

    updateDiff();
    i64 tmpScore = 0;
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {
        tmpScore += diff[i][j] * diff[i][j];
      }
    }
    currentTime = chrono::system_clock::now();
    force = (end - currentTime).count() / C;
    if (tmpScore < bestScore || (double)rand() / 32767.0 < force)
    {
      bestScore = tmpScore;
      ans[n][0] = tmpAns[0];
      ans[n][1] = tmpAns[1];
      ans[n][2] = tmpAns[2];
    }
    else
    {
      reverseDiff();
    }
  }
  bestScore = 0;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      bestScore += abs(diff[i][j]);
    }
  }
  cerr << "score:" << bestScore << " loop:" << loop << endl;
}

void input()
{
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      cin >> A[i][j];
  return;
}

void output()
{
  cout << Q << endl;
  for (int i = 0; i < Q; i++)
    cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << endl;
}

int main()
{
  input();
  init();
  simulate();
  output();
  return 0;
}
