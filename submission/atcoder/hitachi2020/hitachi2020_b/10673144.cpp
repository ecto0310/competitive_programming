// URL: https://atcoder.jp/contests/hitachi2020/submissions/10673144
// Date: Sun, 08 Mar 2020 21:06:32 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 A, B, M;
  cin >> A >> B >> M;
  vector<i64> a(A);
  for (i64 i = 0; i < A; i++)
    cin >> a[i];
  vector<i64> b(B);
  for (i64 i = 0; i < B; i++)
    cin >> b[i];
  vector<i64> x(M), y(M), c(M);
  for (i64 i = 0; i < M; i++)
    cin >> x[i] >> y[i] >> c[i];
  i64 ans = *min_element(a.begin(), a.end()) + *min_element(b.begin(), b.end());
  for (i64 i = 0; i < M; i++)
    ans = min(ans, a[x[i] - 1] + b[y[i] - 1] - c[i]);
  cout << ans << endl;
  return 0;
}
