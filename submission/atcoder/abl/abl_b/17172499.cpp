// URL: https://atcoder.jp/contests/abl/submissions/17172499
// Date: Sat, 03 Oct 2020 22:30:43 +0900
// Language: C++ (GCC 9.2.1 with AC Library v1.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 A, B, C, D;
  cin >> A >> B >> C >> D;
  if (B < C || D < A)
    cout << "No" << endl;
  else
    cout << "Yes" << endl;
  return 0;
}
