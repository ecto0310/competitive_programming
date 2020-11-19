#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 N;
  cin >> N;
  vector<i64> A(N), B(N);
  for (i64 i = 0; i < N; i++)
    cin >> A[i] >> B[i];
  map<i64, i64> m;
  for (i64 i = 0; i < N; i++)
    m[A[i]] = max(m[A[i]], B[i]);
  i64 ans = 0;
  for (pair<i64, i64> i : m)
    ans += max(0LL, i.second);
  cout << ans << endl;
  return 0;
}
