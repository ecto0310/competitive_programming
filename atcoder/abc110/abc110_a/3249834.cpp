// URL: https://atcoder.jp/contests/abc110/submissions/3249834
// Date: Sun, 23 Sep 2018 21:02:14 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int a, b, c;
  cin >> a >> b >> c;
  cout << max({a, b, c}) * 10 + a + b + c - max({a, b, c}) << endl;

  return 0;
}
