// URL: https://atcoder.jp/contests/abc183/submissions/18692231
// Date: Sat, 12 Dec 2020 12:48:41 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N, K;
  cin >> N >> K;
  vector<vector<i64>> T(N, vector<i64>(N));
  for (i64 i = 0; i < N; i++)
    for (i64 j = 0; j < N; j++)
      cin >> T[i][j];
  vector<i64> r;
  for (i64 i = 1; i < N; i++)
    r.push_back(i);
  i64 ans = 0;
  do
  {
    i64 cost = T[0][r[0]] + T[r[N - 2]][0];
    for (i64 i = 0; i < N - 2; i++)
      cost += T[r[i]][r[i + 1]];
    if (cost == K)
      ans++;
  } while (next_permutation(r.begin(), r.end()));
  cout << ans << endl;
  return 0;
}
