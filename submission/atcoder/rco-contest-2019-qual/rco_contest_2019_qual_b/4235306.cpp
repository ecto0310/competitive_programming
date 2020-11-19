// URL: https://atcoder.jp/contests/rco-contest-2019-qual/submissions/4235306
// Date: Mon, 11 Feb 2019 21:24:21 +0900
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
  int cnt = 0;
  priority_queue<Data> pq;
  pq.push({A[N / 2][N / 2], N / 2, N / 2});
  use[N / 2][N / 2] = true;
  while (pq.size())
  {
    Data d = pq.top();
    pq.pop();
    if (M - 1 < cnt + 9 - d.quality)
      break;
    for (int i = 0; i < 9 - d.quality; i++)
    {
      ans[cnt] = {d.r, d.c};
      cnt++;
    }
    A[d.r][d.c] = 9;
    for (int i = 0; i < 4; i++)
    {
      int r = d.r + dr[i], c = d.c + dc[i];
      if (-1 < r && r < N && -1 < c && c < N && A[r][c] != -1 && !use[r][c])
      {
        pq.push({A[r][c], r, c});
        use[r][c] = true;
      }
    }
  }
  for (int i = 0; i < cnt; i++)
    cout << "1 " << ans[i].first << " " << ans[i].second << endl;
  cout << "2 " << N / 2 << " " << N / 2 << endl;

  return 0;
}
