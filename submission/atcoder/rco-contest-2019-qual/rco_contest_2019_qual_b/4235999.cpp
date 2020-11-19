// URL: https://atcoder.jp/contests/rco-contest-2019-qual/submissions/4235999
// Date: Mon, 11 Feb 2019 21:51:37 +0900
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

int main()
{
  int N, M;
  cin >> N >> M;
  vector<vector<int>> A(N, vector<int>(N));
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      cin >> A[i][j];
  vector<pair<int, int>> ans(M);
  vector<vector<bool>> use(N, vector<bool>(N, false));
  int ansSize = 0;
  priority_queue<Data> pq;
  pq.push({A[N / 2][N / 2], N / 2, N / 2});
  use[N / 2][N / 2] = true;
  A[N / 2][N / 2] = 9;
  while (pq.size())
  {
    Data d = pq.top();
    pq.pop();
    if (M - 1 < ansSize + 9 - d.quality)
      continue;
    for (int i = 0; i < 9 - d.quality; i++)
    {
      ans[ansSize] = {d.r, d.c};
      ansSize++;
    }
    A[d.r][d.c] = -1;
    for (int i = 0; i < 4; i++)
    {
      int r = d.r + dr[i], c = d.c + dc[i];
      if (-1 < r && r < N && -1 < c && c < N && A[r][c] != -1 && !use[r][c])
      {
        use[r][c] = true;
        pq.push({A[r][c], r, c});
      }
    }
  }
  for (int i = 0; i < ansSize; i++)
    cout << "1 " << ans[i].first << " " << ans[i].second << endl;
  cout << "2 " << N / 2 << " " << N / 2 << endl;
  pq = priority_queue<Data>();
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      if (A[i][j] != -1 && !use[i][j])
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
            if (-1 < r && r < N && -1 < c && c < N && A[r][c] == A[i][j] && !use[r][c])
            {
              cnt++;
              use[r][c] = true;
              que.push({r, c});
            }
          }
        }
        if (A[i][j] <= cnt)
        {
          cerr << A[i][j] << " " << cnt << endl;
          pq.push({A[i][j] * cnt, i, j});
        }
      }
  for (int i = 0; ansSize + i + 1 < M && pq.size(); i++)
  {
    Data d = pq.top();
    cout << "2 " << d.r << " " << d.c << endl;
    pq.pop();
  }

  return 0;
}
