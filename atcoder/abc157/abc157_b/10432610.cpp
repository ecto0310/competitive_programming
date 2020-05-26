// URL: https://atcoder.jp/contests/abc157/submissions/10432610
// Date: Sun, 01 Mar 2020 21:06:29 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 A[3][3];
  for (i64 i = 0; i < 3; i++)
    for (i64 j = 0; j < 3; j++)
      cin >> A[i][j];
  i64 N;
  cin >> N;
  vector<i64> b(N);
  for (i64 i = 0; i < N; i++)
    cin >> b[i];
  bool ok[3][3] = {};
  for (i64 i = 0; i < 3; i++)
    for (i64 j = 0; j < 3; j++)
      for (i64 k = 0; k < N; k++)
        if (A[i][j] == b[k])
          ok[i][j] = true;
  bool ans = false;
  for (i64 i = 0; i < 3; i++)
    if (ok[i][0] && ok[i][1] && ok[i][2])
      ans = true;
  for (i64 i = 0; i < 3; i++)
    if (ok[0][i] && ok[1][i] && ok[2][i])
      ans = true;
  if (ok[0][0] && ok[1][1] && ok[2][2])
    ans = true;
  if (ok[0][2] && ok[1][1] && ok[2][0])
    ans = true;
  if (ans)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
