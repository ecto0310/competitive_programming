#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

i64 N;
i64 R;
i64 T;
vector<pair<i64, i64>> starts;
vector<vector<pair<i64, i64>>> targets;
vector<string> grid;

void solve()
{
  return;
}

void init()
{
  grid.resize(N, string(N, '.'));
  for (i64 i = 0; i < N; i++)
    for (i64 j = (i % 3); j < N; j += 3)
      grid[i][j] = '#';
  for (pair<i64, i64> i : starts)
    grid[i.first][i.second] = '*';
  for (vector<pair<i64, i64>> i : targets)
    for (pair<i64, i64> j : i)
      grid[j.first][j.second] = '*';
  bool rem = true;
  for (i64 i = N - 1; 0 <= i; i--)
    if (grid[0][i] != '.')
    {
      i64 x = i, y = 0;
      bool open = (grid[y][x] != '#');
      while (x + 1 < N && y + 1 < N)
      {
        x++;
        y++;
        if (grid[y][x] != '#')
          open = true;
      }
      if (!open)
      {
        if (rem)
          grid[0][i] = '*';
        else
          grid[y][x] = '*';
      }
      rem = !rem;
    }
  for (i64 i = 0; i < N; i++)
    if (grid[i][0] != '.')
    {
      i64 x = 0, y = i;
      bool open = (grid[y][x] != '#');
      while (x + 1 < N && y + 1 < N)
      {
        x++;
        y++;
        if (grid[y][x] != '#')
          open = true;
      }
      if (!open)
      {
        if (rem)
          grid[i][0] = '*';
        else
          grid[y][x] = '*';
      }
      rem = !rem;
    }
  return;
}

void input()
{
  cin >> N >> R >> T;
  for (i64 i = 0; i < R; i++)
  {
    i64 row, col;
    cin >> row >> col;
    starts.push_back({row, col});
    vector<pair<i64, i64>> target;
    for (int j = 0; j < T; j++)
    {
      cin >> row >> col;
      target.push_back({row, col});
    }
    targets.push_back(target);
  }
  return;
}

void output()
{
  cout << N * N << endl;
  for (i64 i = 0; i < N; i++)
    for (i64 j = 0; j < N; j++)
      cout << (grid[i][j] == '#' ? "#" : ".") << endl;
  return;
}

int main()
{
  input();
  init();
  solve();
  output();
  return 0;
}
