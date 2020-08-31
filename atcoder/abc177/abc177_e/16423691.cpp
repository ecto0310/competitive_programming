// URL: https://atcoder.jp/contests/abc177/submissions/16423691
// Date: Mon, 31 Aug 2020 19:54:30 +0900
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
  auto pri = [&](i64 i) {
    i64 tmp = A[i];
    for (long long a = 2; a * a <= tmp; a++)
    {
      if (tmp % a != 0)
        continue;
      while (tmp % a == 0)
        tmp /= a;
      m[a]++;
    }
    if (tmp != 1)
      m[tmp]++;
    return 0;
  };
  for (i64 i = 0; i < N; i++)
    pri(i);
  bool p = true;
  for (pair<i64, i64> i : m)
    if (i.second != 1)
      p = false;
  if (p)
  {
    cout << "pairwise coprime" << endl;
    return 0;
  }
  i64 g = gcd(A[0], A[1]);
  for (i64 i = 2; i < N; i++)
    g = gcd(g, A[i]);
  if (g == 1)
    cout << "setwise coprime" << endl;
  else
    cout << "not coprime" << endl;
  return 0;
}
