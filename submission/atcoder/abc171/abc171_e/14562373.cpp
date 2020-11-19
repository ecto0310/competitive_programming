// URL: https://atcoder.jp/contests/abc171/submissions/14562373
// Date: Sun, 21 Jun 2020 21:37:53 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N;
  cin >> N;
  vector<i64> a(N);
  for (i64 i = 0; i < N; i++)
    cin >> a[i];
  i64 sum = 0;
  for (i64 i = 0; i < N; i++)
    sum ^= a[i];
  for (i64 i = 0; i < N; i++)
    cout << (sum ^ a[i]) << " \n"[i + 1 == N];
  return 0;
}
