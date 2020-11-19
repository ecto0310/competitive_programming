#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

i64 dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

int main()
{
  i64 N, P;
  cin >> N >> P;
  vector<string> U(N), D(N), L(N), R(N);
  for (i64 i = 0; i < N; i++)
    cin >> U[i];
  for (i64 i = 0; i < N; i++)
    cin >> L[i] >> R[i];
  for (i64 i = 0; i < N; i++)
    cin >> D[i];
  vector<string> ans(N, string(N, '-'));
  for (i64 i = 0; i < N; i++)
    if (U[i] == "0")
      for (i64 j = 0; j < N; j++)
        ans[j][i] = 'x';
    else if (2 <= U[i].size())
    {
      ans[stoi(U[i].substr(0, U[i].size() - 1)) - 1][i] = U[i][U[i].size() - 1];
      for (i64 j = 0; ans[j][i] != U[i][U[i].size() - 1]; j++)
        ans[j][i] = 'x';
    }
  for (i64 i = 0; i < N; i++)
    if (L[i] == "0")
      for (i64 j = 0; j < N; j++)
        ans[i][j] = 'x';
    else if (2 <= L[i].size())
    {
      ans[i][stoi(L[i].substr(0, L[i].size() - 1)) - 1] = L[i][L[i].size() - 1];
      for (i64 j = 0; ans[i][j] != L[i][L[i].size() - 1]; j++)
        ans[i][j] = 'x';
    }
  for (i64 i = 0; i < N; i++)
    if (D[i] == "0")
      for (i64 j = 0; j < N; j++)
        ans[j][i] = 'x';
    else if (2 <= D[i].size())
    {
      ans[N - stoi(D[i].substr(0, D[i].size() - 1))][i] = D[i][D[i].size() - 1];
      for (i64 j = N - 1; ans[j][i] != D[i][D[i].size() - 1]; j--)
        ans[j][i] = 'x';
    }
  for (i64 i = 0; i < N; i++)
    if (R[i] == "0")
      for (i64 j = 0; j < N; j++)
        ans[i][j] = 'x';
    else if (2 <= R[i].size())
    {
      ans[i][N - stoi(R[i].substr(0, R[i].size() - 1))] = R[i][R[i].size() - 1];
      for (i64 j = N - 1; ans[i][j] != R[i][R[i].size() - 1]; j--)
        ans[i][j] = 'x';
    }
  for (i64 i = 0; i < N; i++)
    for (i64 j = 0; j < N; j++)
      if (ans[i][j] == 'M' || ans[i][j] == 'B')
      {
        queue<pair<i64, i64>> que;
        que.push({i, j});
        while (que.size())
        {
          pair<i64, i64> p = que.front();
          que.pop();
          for (i64 k = 0; k < 4; k++)
          {
            i64 ddx = p.first + dx[k], ddy = p.second + dy[k];
            if (ddx < 0 || N <= ddx || ddy < 0 || N <= ddy || ans[ddx][ddy] != '-')
              continue;
            ans[ddx][ddy] = tolower(ans[p.first][p.second]);
            que.push({ddx, ddy});
          }
        }
      }
  for (i64 i = 0; i < N; i++)
    for (i64 j = 0; j < N; j++)
    {
      if (ans[i][j] == 'x')
        ans[i][j] = '-';
    }
  for (i64 i = 0; i < N; i++)
    cout << ans[i] << endl;
}
