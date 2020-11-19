// URL: https://atcoder.jp/contests/otemae2019/submissions/11399828
// Date: Wed, 01 Apr 2020 00:33:33 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N;
  cin >> N;
  vector<i64> a(N), b(N);
  for (i64 i = 0; i < N; i++)
    cin >> a[i];
  for (i64 i = 0; i < N; i++)
    cin >> b[i];
  vector<i64> cntb(100001);
  for (i64 i = 0; i < N; i++)
    cntb[b[i]]++;
  i64 ans = 1e9;
  vector<i64> cnta(100001);
  for (i64 i = 0; i < N; i++)
  {
    cnta[a[i]]++;
    ans = min(ans, cntb[a[i]] / cnta[a[i]]);
    cout << ans << endl;
  }
  return 0;
}
