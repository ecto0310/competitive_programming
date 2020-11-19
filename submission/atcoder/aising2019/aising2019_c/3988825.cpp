// URL: https://atcoder.jp/contests/aising2019/submissions/3988825
// Date: Sat, 12 Jan 2019 21:55:55 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int dh[4] = {-1, 1, 0, 0}, dw[4] = {0, 0, -1, 1};

int main()
{
  int H, W;
  cin >> H >> W;
  vector<string> S(H);
  for (int i = 0; i < H; i++)
    cin >> S[i];
  long long ans = 0;
  int type = 0;
  vector<long long> cnt;
  vector<vector<long long>> t(H, vector<long long>(W, -1));
  for (int i = 0; i < H; i++)
    for (int j = 0; j < W; j++)
      if (S[i][j] == '#')
      {
        if (t[i][j] != -1)
        {
          ans += cnt[t[i][j]];
          continue;
        }
        int tmp = 0;
        queue<pair<int, int>> que;
        que.push({i, j});
        t[i][j] = type;
        while (que.size())
        {
          pair<int, int> p = que.front();
          que.pop();
          for (int k = 0; k < 4; k++)
            if (-1 < p.first + dh[k] && p.first + dh[k] < H && -1 < p.second + dw[k] && p.second + dw[k] < W && S[p.first][p.second] != S[p.first + dh[k]][p.second + dw[k]] && t[p.first + dh[k]][p.second + dw[k]] == -1)
            {
              if (S[p.first + dh[k]][p.second + dw[k]] == '.')
                tmp++;
              que.push({p.first + dh[k], p.second + dw[k]});
              t[p.first + dh[k]][p.second + dw[k]] = type;
            }
        }
        ans += tmp;
        cnt.push_back(tmp);
        type++;
      }
  cout << ans << endl;

  return 0;
}
