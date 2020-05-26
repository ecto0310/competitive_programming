// URL: https://atcoder.jp/contests/agc030/submissions/3892221
// Date: Sat, 29 Dec 2018 21:04:03 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int a, b, c;
  cin >> a >> b >> c;
  cout << min(a + b + 1, c) + b << endl;

  return 0;
}
