#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 timeLimit = 95000;

struct Game
{
  const i64 BOMB = -1e9;
  const i64 UNKNOWN = -1;

  i64 N, M, D;
  vector<vector<i64>> grid;

  i64 checkBomb = 0;
  i64 runTime = 0;
  bool update = false;
  bool finsh = false;

  void init(i64 N, i64 M, i64 D, i64 row, i64 col)
  {
    this->N = N;
    this->M = M;
    this->D = D;
    grid.resize(N, vector<i64>(N, UNKNOWN));
    grid[row][col] = 0;
  }

  bool isGrid(i64 row, i64 col)
  {
    return (0 <= row && row < N && 0 <= col && col < N);
  }

  bool validFar(i64 baseRow, i64 baseCol, i64 row, i64 col)
  {
    return (baseRow - row) * (baseRow - row) + (baseCol - col) * (baseCol - col) <= D;
  }

  void check(i64 row, i64 col)
  {
    finsh = false;
    cout << "G " << row << " " << col << endl;
    string res;
    getline(cin, res);
    if (res.find("BOOM!") == string::npos)
    {
      i64 value;
      stringstream ss(res);
      ss >> value >> runTime;
      grid[row][col] = value;
    }
    else
    {
      grid[row][col] = BOMB;
      checkBomb++;
    }
  }

  void flag(i64 row, i64 col)
  {
    finsh = false;
    cout << "F " << row << " " << col << endl;
    string res;
    getline(cin, res);
    grid[row][col] = BOMB;
    checkBomb++;
  }
};

Game game;

void search(i64 &size, i64 n, vector<pair<i64, i64>> &range, vector<bool> select, vector<vector<bool>> &danger, vector<vector<i64>> &tmpBomb)
{
  if (n == size)
  {
    bool ok = true;
    for (i64 i = 0; i < size; i++)
      for (i64 dr = -3; dr < 4; dr++)
        for (i64 dc = -3; dc < 4; dc++)
          if (game.isGrid(range[i].first + dr, range[i].second + dc) && game.validFar(range[i].first, range[i].second, range[i].first + dr, range[i].second + dc) && 0 <= game.grid[range[i].first + dr][range[i].second + dc] && game.grid[range[i].first + dr][range[i].second + dc] != tmpBomb[range[i].first + dr][range[i].second + dc])
          {
            ok = false;
          }
    if (!ok)
      return;
    for (i64 i = 0; i < size; i++)
      if (select[i])
        danger[range[i].first][range[i].second] = true;
    return;
  }
  search(size, n + 1, range, select, danger, tmpBomb);
  bool ok = true;
  for (i64 dr = -3; dr < 4; dr++)
    for (i64 dc = -3; dc < 4; dc++)
      if (game.isGrid(range[n].first + dr, range[n].second + dc) && game.validFar(range[n].first, range[n].second, range[n].first + dr, range[n].second + dc) && 0 <= game.grid[range[n].first + dr][range[n].second + dc])
      {
        tmpBomb[range[n].first + dr][range[n].second + dc]++;
        if (game.grid[range[n].first + dr][range[n].second + dc] < tmpBomb[range[n].first + dr][range[n].second + dc])
          ok = false;
      }
  select[n] = true;
  if (ok)
    search(size, n + 1, range, select, danger, tmpBomb);
  select[n] = false;
  for (i64 dr = -3; dr < 4; dr++)
    for (i64 dc = -3; dc < 4; dc++)
      if (game.isGrid(range[n].first + dr, range[n].second + dc) && game.validFar(range[n].first, range[n].second, range[n].first + dr, range[n].second + dc))
      {
        tmpBomb[range[n].first + dr][range[n].second + dc]--;
      }
  return;
}

void solve()
{
  game.finsh = true;
  // Step 1: Discovering non-trivial cells
  for (i64 r = 0; r < game.N; r++)
    for (i64 c = 0; c < game.N; c++)
      if (0 <= game.grid[r][c])
      {
        i64 cntUnknown = 0, cntBomb = 0;
        for (i64 dr = -3; dr < 4; dr++)
          for (i64 dc = -3; dc < 4; dc++)
            if (game.isGrid(r + dr, c + dc) && game.validFar(r, c, r + dr, c + dc))
            {
              if (game.grid[r + dr][c + dc] == game.UNKNOWN)
                cntUnknown++;
              if (game.grid[r + dr][c + dc] == game.BOMB)
                cntBomb++;
            }
        if (game.grid[r][c] == 0 || game.grid[r][c] == cntBomb)
        {
          for (i64 dr = -3; dr < 4; dr++)
            for (i64 dc = -3; dc < 4; dc++)
              if (game.isGrid(r + dr, c + dc) && game.validFar(r, c, r + dr, c + dc) && game.grid[r + dr][c + dc] == game.UNKNOWN)
                game.check(r + dr, c + dc);
        }
        if (game.grid[r][c] == cntUnknown + cntBomb)
        {
          for (i64 dr = -3; dr < 4; dr++)
            for (i64 dc = -3; dc < 4; dc++)
              if (game.isGrid(r + dr, c + dc) && game.validFar(r, c, r + dr, c + dc) && game.grid[r + dr][c + dc] == game.UNKNOWN)
                game.flag(r + dr, c + dc);
        }
      }
  if (!game.finsh)
    return;
  // Step 2: Discovery of non-trivial cells
  vector<vector<bool>> checked(game.N, vector<bool>(game.N));
  vector<vector<bool>> danger(game.N, vector<bool>(game.N));
  for (i64 r = 0; r < game.N; r++)
    for (i64 c = 0; c < game.N; c++)
      if (!checked[r][c] && game.grid[r][c] == game.UNKNOWN && !checked[r][c])
      {
        vector<pair<i64, i64>> range;
        queue<pair<i64, i64>> que;
        range.push_back({r, c});
        que.push({r, c});
        checked[r][c] = true;
        while (que.size())
        {
          pair<i64, i64> p = que.front();
          que.pop();
          i64 nr = p.first, nc = p.second;
          for (i64 dr = -3; dr < 4; dr++)
            for (i64 dc = -3; dc < 4; dc++)
              if (game.isGrid(nr + dr, nc + dc) && game.validFar(nr, nc, nr + dr, nc + dc) && !checked[nr + dr][nc + dc])
              {
                if (game.grid[nr][nc] == game.UNKNOWN && 0 <= game.grid[nr + dr][nc + dc])
                {
                  que.push({nr + dr, nc + dc});
                  checked[nr + dr][nc + dc] = true;
                }
                if (0 <= game.grid[nr][nc] && game.grid[nr + dr][nc + dc] == game.UNKNOWN)
                {
                  range.push_back({nr + dr, nc + dc});
                  que.push({nr + dr, nc + dc});
                  checked[nr + dr][nc + dc] = true;
                }
              }
        }
        i64 size = range.size();
        vector<bool> select(size);
        vector<vector<i64>> tmpBomb(game.N, vector<i64>(game.N));
        for (i64 r = 0; r < game.N; r++)
          for (i64 c = 0; c < game.N; c++)
            if (game.grid[r][c] == game.BOMB)
            {
              for (i64 dr = -3; dr < 4; dr++)
                for (i64 dc = -3; dc < 4; dc++)
                  if (game.isGrid(r + dr, c + dc) && game.validFar(r, c, r + dr, c + dc))
                    tmpBomb[r + dr][c + dc]++;
            }
        if (size <= 25)
        {
          search(size, 0, range, select, danger, tmpBomb);
        }
        else
        {
          for (i64 i = 0; i < size; i++)
            danger[range[i].first][range[i].second] = true;
        }
      }
  for (i64 r = 0; r < game.N; r++)
    for (i64 c = 0; c < game.N; c++)
      if (!danger[r][c] && game.grid[r][c] == game.UNKNOWN)
        game.check(r, c);
  // Step 3: Discovered all the bombs
  if (game.checkBomb == game.M)
  {
    for (i64 r = 0; r < game.N; r++)
      for (i64 c = 0; c < game.N; c++)
        if (game.grid[r][c] == game.UNKNOWN)
          game.check(r, c);
  }
  return;
}

void init()
{
  i64 N, M, D, row, col;
  cin >> N >> M >> D >> row >> col;
  game.init(N, M, D, row, col);
  string tmp;
  getline(cin, tmp);
  return;
}

int main()
{
  init();
  while (!game.finsh && game.runTime <= timeLimit)
  {
    solve();
  }
  cout << "STOP" << endl;
  return 0;
}
