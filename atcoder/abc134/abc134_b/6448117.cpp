// URL: https://atcoder.jp/contests/abc134/submissions/6448117
// Date: Sat, 20 Jul 2019 21:01:54 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, d;
  cin >> n >> d;
  d = d * 2 + 1;
  cout << (n + d - 1) / d << endl;
  return 0;
}
