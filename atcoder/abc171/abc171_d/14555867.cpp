// URL: https://atcoder.jp/contests/abc171/submissions/14555867
// Date: Sun, 21 Jun 2020 21:25:47 +0900
// Language: C++ (GCC 9.2.1)
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
  i64 ans = 0;
  for (i64 i = 0; i < N; i++)
  {
    m[A[i]]++;
    ans += A[i];
  }
  i64 Q;
  cin >> Q;
  for (i64 i = 0; i < Q; i++)
  {
    i64 B, C;
    cin >> B >> C;
    ans -= B * m[B];
    ans += C * m[B];
    m[C] += m[B];
    m[B] = 0;
    cout << ans << endl;
  }
  return 0;
}
