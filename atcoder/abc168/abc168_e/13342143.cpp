// URL: https://atcoder.jp/contests/abc168/submissions/13342143
// Date: Sun, 17 May 2020 13:33:01 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "
"

const i64 MOD = 1e9 + 7;

i64 mpow(i64 x, i64 n)
{
  i64 ret = 1;
  while (n > 0)
  {
    if (n & 1)
      ret = ret * x % MOD;
    x = x * x % MOD;
    n >>= 1;
  }
  return ret;
}

int main()
{
  i64 N;
  cin >> N;
  vector<i64> A(N), B(N);
  for (i64 i = 0; i < N; i++)
    cin >> A[i] >> B[i];
  map<pair<i64, i64>, i64> m;
  for (i64 i = 0; i < N; i++)
  {
    i64 g = gcd(A[i], B[i]);
    if (B[i] < 0)
    {
      A[i] *= -1;
      B[i] *= -1;
    }
    if (g == 0)
    {
      g = 1;
    }
    if (A[i] / g == -1 && B[i] / g == 0)
      A[i] *= -1;
    m[{A[i] / g, B[i] / g}]++;
  }
  vector<i64> tmp;
  for (pair<pair<i64, i64>, i64> i : m)
    if (0 < i.second && i.first != make_pair(0LL, 0LL))
    {
      tmp.push_back((mpow(2, i.second) - 1 + mpow(2, m[{-i.first.second * (0 < i.first.first ? 1 : -1), abs(i.first.first)}]) - 1) % MOD);
      m[{-i.first.second * (0 < i.first.first ? 1 : -1), abs(i.first.first)}] = -1;
    }
  i64 ans = 1;
  for (i64 i : tmp)
    ans = (ans * i + ans) % MOD;
  cout << (ans - 1 + MOD + m[{0, 0}]) % MOD << endl;
  return 0;
}
