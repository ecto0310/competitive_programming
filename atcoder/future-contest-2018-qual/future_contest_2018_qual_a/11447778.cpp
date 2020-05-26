// URL: https://atcoder.jp/contests/future-contest-2018-qual/submissions/11447778
// Date: Fri, 03 Apr 2020 02:26:47 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N = 100, Q = 1000;
  cout << Q << endl;
  for (int i = 0; i < Q; i++)
    cout << rand() % N << " " << rand() % N << " " << rand() % N + 1 << endl;
  return 0;
}
