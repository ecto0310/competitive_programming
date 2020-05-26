// URL: https://atcoder.jp/contests/judge-update-202004/submissions/11582460
// Date: Sun, 05 Apr 2020 21:04:08 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N;
  cin >> N;
  vector<i64> X(N);
  vector<char> C(N);
  for (i64 i = 0; i < N; i++)
    cin >> X[i] >> C[i];
  vector<i64> r, b;
  for (i64 i = 0; i < N; i++)
    if (C[i] == 'R')
      r.push_back(X[i]);
    else
      b.push_back(X[i]);
  sort(r.begin(), r.end());
  sort(b.begin(), b.end());
  for (i64 i : r)
    cout << i << endl;
  for (i64 i : b)
    cout << i << endl;
  return 0;
}
