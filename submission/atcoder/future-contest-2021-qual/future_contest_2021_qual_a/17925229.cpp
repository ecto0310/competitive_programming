// URL: https://atcoder.jp/contests/future-contest-2021-qual/submissions/17925229
// Date: Sat, 07 Nov 2020 19:17:40 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

std::mt19937 mt(0);

i64 getCycle()
{
  unsigned int low, high;
  __asm__ volatile("rdtsc"
                   : "=a"(low), "=d"(high));
  return ((i64)low) | ((i64)high << 32);
}

const double timeLimit = 2.8;
const i64 cyclePerSec = 2800000000;
i64 baseTime;

const i64 N = 100;

struct Pos
{
  i64 x, y;
  i64 operator-(const Pos &other)
  {
    return abs(x - other.x) + abs(y - other.y);
  }
};

vector<Pos> pos(N);
vector<vector<i64>> far(N, vector<i64>(N));
vector<vector<i64>> grid(20, vector<i64>(20, -1));

string bestAns;
i64 bestScore = 4000;

void simulate()
{
  vector<i64> mou;
  for (i64 i = 0; i < 20; i++)
  {
    if (i % 2 == 0)
    {
      for (i64 j = 0; j < 20; j++)
      {
        if (grid[i][j] != -1)
        {
          bestAns += "I";
          mou.push_back(grid[i][j]);
          grid[i][j] = -1;
        }
        if (j + 1 != 20)
          bestAns += "R";
      }
      bestAns += "D";
    }
    else
    {
      for (i64 j = 19; 0 <= j; j--)
      {
        if (grid[i][j] != -1)
        {
          bestAns += "I";
          mou.push_back(grid[i][j]);
          grid[i][j] = -1;
        }
        if (j != 0)
          bestAns += "L";
      }
      if (i + 1 != 20)
        bestAns += "D";
    }
  }
  for (i64 i = 0; i < 10; i++)
    if (i % 2 == 0)
    {
      for (i64 j = 19; 10 <= j; j--)
      {
        bestAns += "O";
        if (j != 10)
          bestAns += "U";
        grid[j][i] = mou.back();
        pos[mou.back()] = {j, i};
        mou.pop_back();
      }
      if (i + 1 != 10)
        bestAns += "R";
    }
    else
    {
      for (i64 j = 10; j < 20; j++)
      {
        bestAns += "O";
        if (j != 19)
          bestAns += "D";
        grid[j][i] = mou.back();
        pos[mou.back()] = {j, i};
        mou.pop_back();
      }
      if (i + 1 != 10)
        bestAns += "R";
    }
  i64 nowX = 19, nowY = 9;
  for (i64 i = 0; i < N; i++)
  {
    if (nowX < pos[i].x)
      bestAns += string(abs(nowX - pos[i].x), 'D');
    else
      bestAns += string(abs(nowX - pos[i].x), 'U');
    if (nowY < pos[i].y)
      bestAns += string(abs(nowY - pos[i].y), 'R');
    else
      bestAns += string(abs(nowY - pos[i].y), 'L');
    bestAns += "I";
    nowX = pos[i].x;
    nowY = pos[i].y;
  }
  return;
}

void init()
{
  for (i64 i = 0; i < N; i++)
    grid[pos[i].x][pos[i].y] = i;
  for (i64 i = 0; i < N; i++)
    for (i64 j = 0; j < N; j++)
      far[i][j] = abs(pos[i].x - pos[j].x) + abs(pos[i].y - pos[j].y);
  return;
}

void input()
{
  for (i64 i = 0; i < N; i++)
    cin >> pos[i].x >> pos[i].y;
  return;
}

void output()
{
  cout << bestAns << endl;
  return;
}

int main()
{
  input();
  init();
  simulate();
  output();
  return 0;
}
