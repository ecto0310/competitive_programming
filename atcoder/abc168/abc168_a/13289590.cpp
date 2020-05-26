// URL: https://atcoder.jp/contests/abc168/submissions/13289590
// Date: Sun, 17 May 2020 21:01:16 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N;
  cin >> N;
  N %= 10;
  if (N == 3)
    cout << "bon" << endl;
  else if (N == 0 || N == 1 || N == 6 || N == 8)
    cout << "pon" << endl;
  else
    cout << "hon" << endl;
  return 0;
}
