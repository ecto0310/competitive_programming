// URL: https://atcoder.jp/contests/abc171/submissions/14531224
// Date: Sun, 21 Jun 2020 21:02:18 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N, K;
  cin >> N >> K;
  vector<i64> p(N);
  for (i64 i = 0; i < N; i++)
    cin >> p[i];
  sort(p.begin(), p.end());
  i64 ans = 0;
  for (i64 i = 0; i < K; i++)
    ans += p[i];
  cout << ans << endl;
  return 0;
}
