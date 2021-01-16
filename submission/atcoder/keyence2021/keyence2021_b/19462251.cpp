// URL: https://atcoder.jp/contests/keyence2021/submissions/19462251
// Date: Sat, 16 Jan 2021 21:07:54 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N, K;
  cin >> N >> K;
  vector<i64> m(N);
  for (i64 i = 0; i < N; i++)
  {
    i64 a;
    cin >> a;
    m[a]++;
  }
  i64 ans = 0;
  for (i64 i = 0; i < N; i++)
  {
    ans += max(0LL, K - m[i]) * i;
    K = min(K, m[i]);
  }
  cout << ans + N * K << endl;
  return 0;
}
