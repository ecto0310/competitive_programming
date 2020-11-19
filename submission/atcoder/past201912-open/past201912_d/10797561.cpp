// URL: https://atcoder.jp/contests/past201912-open/submissions/10797561
// Date: Fri, 13 Mar 2020 18:59:46 +0900
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
    m[A[i]]++;
  if (m.size() == N)
  {
    cout << "Correct" << endl;
    return 0;
  }
  for (i64 i = 1; i <= N; i++)
    if (m[i] == 2)
      cout << i << " ";
  for (i64 i = 1; i <= N; i++)
    if (m[i] == 0)
      cout << i << endl;
  return 0;
}
