// URL: https://atcoder.jp/contests/abc126/submissions/5483862
// Date: Mon, 20 May 2019 01:41:37 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 m, k;
  cin >> m >> k;
  if (m == 1)
  {
    if (k == 0)
      cout << "0 0 1 1" << endl;
    else
      cout << -1 << endl;
    return 0;
  }
  if ((1 << m) <= k)
  {
    cout << -1 << endl;
    return 0;
  }
  cerr << (1 << m) << endl;
  for (i64 i = 0; i < (1 << m); i++)
    if (i != k)
      cout << i << " ";
  cout << k << " ";
  for (i64 i = (1 << m) - 1; 0 <= i; i--)
    if (i != k)
      cout << i << " ";
  cout << k << endl;
  return 0;
}
