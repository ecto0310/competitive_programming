#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

i64 dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

int main()
{
  string tc;
  cin >> tc;
  ifstream in("inputs/pajel_" + tc + ".in");
  cin.rdbuf(in.rdbuf());
  i64 N, P;
  cin >> N >> P;
  vector<string> U(N), D(N), L(N), R(N);
  for (i64 i = 0; i < N; i++)
    cin >> U[i];
  for (i64 i = 0; i < N; i++)
    cin >> L[i] >> R[i];
  for (i64 i = 0; i < N; i++)
    cin >> D[i];
  ifstream out("outputs/pajel_" + tc + ".out");
  cin.rdbuf(out.rdbuf());
  vector<string> ans(N);
  for (i64 i = 0; i < N; i++)
    cin >> ans[i];
  for (i64 i = 0; i < N; i++)
    for (i64 j = 0; j < N; j++)
      if (ans[j][i] != '-')
      {
        if (to_string(j + 1) + string(1, ans[j][i]) != U[i] && U[i] != "-")
          cerr << "U" << i << " " << to_string(j + 1) << ans[j][i] << " " << U[i] << endl;
        break;
      }
  for (i64 i = 0; i < N; i++)
    for (i64 j = 0; j < N; j++)
      if (ans[N - j - 1][i] != '-')
      {
        if (to_string(j + 1) + string(1, ans[N - j - 1][i]) != D[i] && D[i] != "-")
          cerr << "D" << i << " " << to_string(j + 1) << ans[N - j - 1][i] << " " << D[i] << endl;
        break;
      }
  for (i64 i = 0; i < N; i++)
    for (i64 j = 0; j < N; j++)
      if (ans[i][j] != '-')
      {
        if (to_string(j + 1) + string(1, ans[i][j]) != L[i] && L[i] != "-")
          cerr << "L" << i << " " << to_string(j + 1) << ans[i][j] << " " << L[i] << endl;
        break;
      }
  for (i64 i = 0; i < N; i++)
    for (i64 j = 0; j < N; j++)
      if (ans[i][N - j - 1] != '-')
      {
        if (to_string(j + 1) + string(1, ans[i][N - j - 1]) != R[i] && R[i] != "-")
          cerr << "R" << i << " " << to_string(j + 1) << ans[i][N - j - 1] << " " << R[i] << endl;
        break;
      }
  vector<vector<bool>> ch(N, vector<bool>(N));
  i64 q = 0;
  for (i64 i = 0; i < N; i++)
    for (i64 j = 0; j < N; j++)
      if (ans[i][j] != '-' && !ch[i][j])
      {
        q++;
        ch[i][j] = true;
        char now = tolower(ans[i][j]);
        queue<pair<i64, i64>> que;
        que.push({i, j});
        while (que.size())
        {
          pair<i64, i64> p = que.front();
          que.pop();
          for (i64 k = 0; k < 4; k++)
          {
            i64 ddx = p.first + dx[k], ddy = p.second + dy[k];
            if (ddx < 0 || N <= ddx || ddy < 0 || N <= ddy || ch[ddx][ddy] || tolower(ans[ddx][ddy]) != now)
              continue;
            ch[ddx][ddy] = true;
            que.push({ddx, ddy});
          }
        }
      }
  cerr << "P = " << P << endl;
  cerr << "Q = " << q << endl;
  cerr << "Score = " << (i64)(10 - sqrt(2 * (q - P))) << endl;
  return 0;
}
