// URL: https://atcoder.jp/contests/future-contest-2021-qual/submissions/17922664
// Date: Sat, 07 Nov 2020 17:46:29 +0900
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

string bestAns;
i64 bestScore = 4000;

bool isWant(Pos target, Pos item)
{
  if (target.x <= item.x && item.x < target.x + 10 && target.y <= item.y && item.y < target.y + 10)
    return false;
  return true;
}

string eval(Pos target)
{
  string ret;
  vector<i64> order;
  i64 size = 0;
  vector<bool> comp(N);
  i64 minDistance = 1e9, it;
  for (i64 i = 0; i < N; i++)
    if (isWant(target, pos[i]) && pos[i].x + pos[i].y < minDistance)
    {
      it = i;
      minDistance = pos[i].x + pos[i].y;
    }
  comp[it] = true;
  order.push_back(it);
  size++;
  for (i64 i = 0; i < N; i++)
  {
    if (!comp[i] && isWant(target, pos[i]))
    {
      comp[i] = true;
      if (size == 1)
      {
        order.push_back(i);
        size++;
      }
      else
      {
        i64 minDistance = 1e9, ins;
        for (i64 j = 1; j < size; j++)
        {
          i64 distance = far[order[j]][i] + (j + 1 == size ? 0 : far[order[j + 1]][i]);
          if (distance < minDistance)
          {
            minDistance = distance;
            ins = j;
          }
        }
        order.insert(order.begin() + ins, i);
        size++;
      }
    }
  }
  i64 nowX = 0, nowY = 0;
  for (i64 i = 0; i < size; i++)
  {
    if (nowX < pos[order[i]].x)
      ret += string(abs(nowX - pos[order[i]].x), 'D');
    else
      ret += string(abs(nowX - pos[order[i]].x), 'U');
    if (nowY < pos[order[i]].y)
      ret += string(abs(nowY - pos[order[i]].y), 'R');
    else
      ret += string(abs(nowY - pos[order[i]].y), 'L');
    ret += "I";
    nowX = pos[order[i]].x;
    nowY = pos[order[i]].y;
  }
  if (nowX < target.x)
    ret += string(abs(nowX - target.x), 'D');
  else
    ret += string(abs(nowX - target.x), 'U');
  if (nowY < target.y)
    ret += string(abs(nowY - target.y), 'R');
  else
    ret += string(abs(nowY - target.y), 'L');
  vector<vector<i64>> grid(10, vector<i64>(10, -1));
  for (i64 i = 0; i < N; i++)
    if (!comp[i])
      grid[pos[i].x - target.x][pos[i].y - target.y] = i;
  for (i64 i = 0; i < 10; i++)
  {
    if (i % 2 == 0)
    {
      for (i64 j = 0; j < 10; j++)
      {
        if (grid[i][j] == -1)
        {
          i64 t = order.back();
          order.pop_back();
          grid[i][j] = t;
          ret += "O";
        }
        if (j != 9)
          ret += "R";
      }
    }
    else
    {
      for (i64 j = 9; 0 <= j; j--)
      {
        if (grid[i][j] == -1)
        {
          i64 t = order.back();
          order.pop_back();
          grid[i][j] = t;
          ret += "O";
        }
        if (j != 0)
          ret += "L";
      }
    }
    if (i != 9)
      ret += "D";
  }
  vector<Pos> aftPos = pos;
  for (i64 i = 0; i < 10; i++)
    for (i64 j = 0; j < 10; j++)
      aftPos[grid[i][j]] = {i, j};
  nowX = 9;
  nowY = 0;
  for (i64 i = 0; i < N; i++)
  {
    if (nowX < aftPos[i].x)
      ret += string(abs(nowX - aftPos[i].x), 'D');
    else
      ret += string(abs(nowX - aftPos[i].x), 'U');
    if (nowY < aftPos[i].y)
      ret += string(abs(nowY - aftPos[i].y), 'R');
    else
      ret += string(abs(nowY - aftPos[i].y), 'L');
    ret += "I";
    nowX = aftPos[i].x;
    nowY = aftPos[i].y;
  }
  return ret;
}

void simulate()
{
  baseTime = getCycle();
  Pos target = {};
  double currentTime = (double)(getCycle() - baseTime) / cyclePerSec;
  double C = timeLimit * 100;
  for (i64 _x = 0; _x < 10; _x++)
    for (i64 _y = 0; _y < 10; _y++)
    {
      // i64 move[2] = {mt() % 2, mt() % 2};
      // if (move[0] == 0)
      // {
      //   if (move[1] == 0 && target.x + 1 <= 10)
      //     target.x = target.x + 1;
      //   else if (move[1] == 1 && 0 <= target.x - 1)
      //     target.x = target.x - 1;
      //   else
      //     continue;
      // }
      // else
      // {
      //   if (move[1] == 0 && target.y + 1 <= 10)
      //     target.y = target.y + 1;
      //   else if (move[1] == 1 && 0 <= target.y - 1)
      //     target.y = target.y - 1;
      //   else
      //     continue;
      // }
      target = {_x, _y};
      string evalAns = eval(target);
      i64 evalScore = evalAns.size() - count(evalAns.begin(), evalAns.end(), 'I') - count(evalAns.begin(), evalAns.end(), 'O');
      currentTime = (double)(getCycle() - baseTime) / cyclePerSec;
      double forceLine = (timeLimit - currentTime) / C;
      if (evalScore < bestScore)
      {
        bestScore = evalScore;
        bestAns = evalAns;
      }
      // if (bestScore < evalScore && forceLine < (double)mt() / mt19937::max())
      // {
      //   if (move[0] == 0)
      //   {
      //     if (move[1] == 0)
      //       target.x--;
      //     else
      //       target.x++;
      //   }
      //   else
      //   {
      //     if (move[1] == 0)
      //       target.y--;
      //     else
      //       target.y++;
      //   }
      // }
    }
  cerr << 4000 - bestScore << endl;
  return;
}

void init()
{
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
