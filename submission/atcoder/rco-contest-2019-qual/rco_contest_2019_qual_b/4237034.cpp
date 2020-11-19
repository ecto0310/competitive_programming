// URL: https://atcoder.jp/contests/rco-contest-2019-qual/submissions/4237034
// Date: Mon, 11 Feb 2019 22:28:24 +0900
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

int dr[4] = {-1, 0, 1, 0}, dc[4] = {0, 1, 0, -1};

int N, M;
vector<vector<int>> A;

vector<pair<int, int>> ans;
int startR, startC;

void input()
{
  cin >> N >> M;
  A = vector<vector<int>>(N, vector<int>(N));
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      cin >> A[i][j];
}

pair<int, vector<pair<int, int>>> eval(int posR, int posC)
{
  vector<vector<int>> board = A;
  int score = 0, retSize = 0;
  vector<pair<int, int>> ret;
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
      ret.push_back({d.r, d.c});
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
  return {score, ret};
}

void simulate()
{
  int bestScore = 0;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
    {
      pair<int, vector<pair<int, int>>> tmpScore = eval(i, j);
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
  for (pair<int, int> t : ans)
    cout << "1 " << t.first << " " << t.second << endl;
  cout << "2 " << startR << " " << startC << endl;
}

int main()
{
  input();
  simulate();
  output();

  return 0;
}
