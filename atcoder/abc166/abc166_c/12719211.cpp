// URL: https://atcoder.jp/contests/abc166/submissions/12719211
// Date: Sun, 03 May 2020 21:06:05 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N, M;
  cin >> N >> M;
  vector<i64> H(N);
  for (i64 i = 0; i < N; i++)
    cin >> H[i];
  vector<i64> edge[N];
  for (i64 i = 0; i < M; i++)
  {
    i64 A, B;
    cin >> A >> B;
    A--;
    B--;
    edge[A].push_back(B);
    edge[B].push_back(A);
  }
  i64 ans = 0;
  for (i64 i = 0; i < N; i++)
  {
    bool ok = true;
    for (i64 j : edge[i])
      if (H[i] <= H[j])
        ok = false;
    if (ok)
      ans++;
  }
  cout << ans << endl;
  return 0;
}
