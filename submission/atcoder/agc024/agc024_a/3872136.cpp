// URL: https://atcoder.jp/contests/agc024/submissions/3872136
// Date: Tue, 25 Dec 2018 21:03:50 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  long long a, b, c, k;
  cin >> a >> b >> c >> k;
  if (k % 2 == 0)
    cout << a - b << endl;
  else
    cout << b - a << endl;

  return 0;
}
