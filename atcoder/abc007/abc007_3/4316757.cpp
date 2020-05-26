// URL: https://atcoder.jp/contests/abc007/submissions/4316757
// Date: Tue, 19 Feb 2019 01:26:42 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>

using namespace std;

int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};

int main()
{
  int R, C, sy, sx, gy, gx;
  cin >> R >> C >> sy >> sx >> gy >> gx;
  vector<string> c(R);
  for (int i = 0; i < R; i++)
    cin >> c[i];
  queue<pair<int, int>> que;
  vector<vector<int>> far(R, vector<int>(C, 1e9));
  que.push({sy - 1, sx - 1});
  far[sy - 1][sx - 1] = 0;
  while (que.size())
  {
    pair<int, int> p = que.front();
    que.pop();
    for (int i = 0; i < 4; i++)
    {
      int nr = p.first + dr[i], nc = p.second + dc[i];
      if (-1 < nr && nr < R && -1 < nc && nc < C && c[nr][nc] == '.' && far[p.first][p.second] + 1 < far[nr][nc])
      {
        far[nr][nc] = far[p.first][p.second] + 1;
        que.push({nr, nc});
      }
    }
  }
  cout << far[gy - 1][gx - 1] << endl;

  return 0;
}
