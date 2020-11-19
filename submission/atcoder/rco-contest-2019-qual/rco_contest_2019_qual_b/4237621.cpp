// URL: https://atcoder.jp/contests/rco-contest-2019-qual/submissions/4237621
// Date: Mon, 11 Feb 2019 22:45:35 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

struct Data
{
  int quality, r, c;
  bool operator<(const Data &other) const
  {
    return quality < other.quality;
  };
};

struct Output
{
  int r, c, op;
};

int dr[4] = {-1, 0, 1, 0}, dc[4] = {0, 1, 0, -1};

int N, M;
vector<vector<int>> A;

vector<Output> ans;
int startR, startC;

void input()
{
  cin >> N >> M;
  A = vector<vector<int>>(N, vector<int>(N));
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      cin >> A[i][j];
}

pair<int, vector<Output>> eval(int posR, int posC)
{
  vector<vector<int>> board = A;
  int score = 0, retSize = 0;
  vector<Output> ret;
  priority_queue<Data> pq;
  vector<vector<bool>> use(N, vector<bool>(N, false));
  pq.push({board[posR][posC], posR, posC});
  use[posR][posC] = true;
  board[posR][posC] = 9;
  while (pq.size())
  {
    Data d = pq.top();
    pq.pop();
    if (M - 1 < retSize + 9 - d.quality)
      break;
    for (int i = 0; i < 9 - d.quality; i++)
    {
      ret.push_back({d.r, d.c, 1});
      retSize++;
    }
    board[d.r][d.c] = -1;
    for (int i = 0; i < 4; i++)
    {
      int r = d.r + dr[i], c = d.c + dc[i];
      if (-1 < r && r < N && -1 < c && c < N && board[r][c] && !use[r][c])
      {
        use[r][c] = true;
        pq.push({board[r][c], r, c});
      }
    }
    score += 9;
  }
  ret.push_back({posR, posC, 2});
  pq = priority_queue<Data>();
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      if (!use[i][j])
      {
        int cnt = 1;
        queue<pair<int, int>> que;
        que.push({i, j});
        while (que.size())
        {
          pair<int, int> p = que.front();
          que.pop();
          for (int k = 0; k < 4; k++)
          {
            int r = p.first + dr[k], c = p.second + dc[k];
            if (-1 < r && r < N && -1 < c && c < N && board[r][c] == board[posR][posC] && !use[r][c])
            {
              cnt++;
              use[r][c] = true;
              que.push({r, c});
            }
          }
        }
        if (board[i][j] <= cnt)
        {
          pq.push({board[i][j] * cnt, i, j});
        }
      }
  for (int i = 0; retSize + i + 1 < M && pq.size(); i++)
  {
    Data d = pq.top();
    ret.push_back({d.r, d.c, 2});
    score += d.quality;
    pq.pop();
  }
  return {score, ret};
}

void simulate()
{
  int bestScore = 0;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
    {
      pair<int, vector<Output>> tmpScore = eval(i, j);
      if (bestScore < tmpScore.first)
      {
        bestScore = tmpScore.first;
        ans = tmpScore.second;
        startR = i;
        startC = j;
      }
    }
  cerr << bestScore << endl;
}

void output()
{
  for (Output t : ans)
    cout << t.op << " " << t.r << " " << t.c << endl;
}

int main()
{
  input();
  simulate();
  output();

  return 0;
}
