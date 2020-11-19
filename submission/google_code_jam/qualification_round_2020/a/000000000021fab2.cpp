#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 T;
  cin >> T;
  for (i64 _ = 1; _ <= T; _++)
  {
    i64 N;
    cin >> N;
    vector<vector<i64>> M(N, vector<i64>(N));
    for (i64 i = 0; i < N; i++)
      for (i64 j = 0; j < N; j++)
        cin >> M[i][j];
    i64 k = 0;
    for (i64 i = 0; i < N; i++)
      k += M[i][i];
    i64 r = 0;
    for (i64 i = 0; i < N; i++)
    {
      vector<bool> use(N);
      for (i64 j = 0; j < N; j++)
      {
        if (use[M[i][j]])
        {
          r++;
          break;
        }
        use[M[i][j]] = true;
      }
    }
    i64 c = 0;
    for (i64 i = 0; i < N; i++)
    {
      vector<bool> use(N);
      for (i64 j = 0; j < N; j++)
      {
        if (use[M[j][i]])
        {
          c++;
          break;
        }
        use[M[j][i]] = true;
      }
    }
    cout << "Case #" << _ << ": " << k << " " << r << " " << c << endl;
  }
  return 0;
}
