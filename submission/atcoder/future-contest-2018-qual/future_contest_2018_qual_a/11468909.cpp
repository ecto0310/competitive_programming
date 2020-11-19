// URL: https://atcoder.jp/contests/future-contest-2018-qual/submissions/11468909
// Date: Sat, 04 Apr 2020 00:54:35 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

const int timeLimit = 5980;

const int N = 100, Q = 1000;
int A[N][N];
int ans[Q][3];
int diff[N][N];

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

void makeDiff(int data[Q][3])
{
  int map[N][N] = {};
  for (int i = 0; i < Q; i++)
  {
    int x = data[i][0];
    int y = data[i][1];
    int h = data[i][2];
    map[x][y] += h;
    for (int p = 1; p < h; p++)
    {
      int d = h - p;
      x = data[i][0];
      y = data[i][1] - d;
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

void updateDiff(int before[3], int after[3])
{
  int x = before[0];
  int y = before[1];
  int h = before[2];
  diff[x][y] += h;
  for (int p = 1; p < h; p++)
  {
    int d = h - p;
    x = before[0];
    y = before[1] - d;
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

  x = after[0];
  y = after[1];
  h = after[2];
  diff[x][y] -= h;
  for (int p = 1; p < h; p++)
  {
    int d = h - p;
    x = after[0];
    y = after[1] - d;
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
  makeDiff(ans);
  i64 bestScore = 0;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      bestScore += abs(diff[i][j]);
    }
  }

  int loop = 0;

  chrono::system_clock::time_point currentTime = chrono::system_clock::now();
  while (currentTime < end)
  {
    loop++;
    int tmpAns[3], beforeAns[3];
    int n = rand() % Q;
    beforeAns[0] = ans[n][0];
    beforeAns[1] = ans[n][1];
    beforeAns[2] = ans[n][2];
    tmpAns[0] = min(N - 1, max(0, beforeAns[0] + (rand() % 3 - 1)));
    tmpAns[1] = min(N - 1, max(0, beforeAns[1] + (rand() % 3 - 1)));
    tmpAns[2] = min(N, max(1, beforeAns[2] + (rand() % 3 - 1)));

    updateDiff(beforeAns, tmpAns);
    i64 tmpScore = 0;
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {
        tmpScore += abs(diff[i][j]);
      }
    }
    currentTime = chrono::system_clock::now();
    if (tmpScore < bestScore)
    {
      bestScore = tmpScore;
      ans[n][0] = tmpAns[0];
      ans[n][1] = tmpAns[1];
      ans[n][2] = tmpAns[2];
    }
    else
    {
      updateDiff(tmpAns, beforeAns);
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
