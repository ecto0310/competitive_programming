// URL: https://atcoder.jp/contests/abc158/submissions/10587999
// Date: Sat, 07 Mar 2020 21:01:05 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  string S;
  cin >> S;
  if (S[0] != S[1] || S[1] != S[2])
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
