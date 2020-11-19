// URL: https://atcoder.jp/contests/abc159/submissions/11103986
// Date: Sun, 22 Mar 2020 21:23:57 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N;
  cin >> N;
  vector<i64> A(N);
  for (i64 i = 0; i < N; i++)
    cin >> A[i];
  map<i64, i64> m;
  for (i64 i = 0; i < N; i++)
  {
    m[A[i]]++;
  }
  i64 ans = 0;
  for (pair<i64, i64> i : m)
    ans += i.second * (i.second - 1) / 2;
  for (i64 i = 0; i < N; i++)
    cout << ans - m[A[i]] * (m[A[i]] - 1) / 2 + (m[A[i]] - 1) * (m[A[i]] - 2) / 2 << endl;
  return 0;
}
