// URL: https://atcoder.jp/contests/abc166/submissions/12749165
// Date: Sun, 03 May 2020 21:49:11 +0900
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

  map<i64, i64> sum;
  for (i64 i = 0; i < N; i++)
    sum[(i + 1) - A[i]]++;
  i64 ans = 0;
  for (i64 i = 0; i < N; i++)
    ans += sum[A[i] + (i + 1)];
  cout << ans << endl;
  return 0;
}
