// URL: https://atcoder.jp/contests/tkppc4-1/submissions/6556588
// Date: Sat, 27 Jul 2019 16:56:02 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  string x;
  cin >> n >> x;
  for (i64 i = 2; i <= 10; i++)
  {
    string s;
    i64 tmp = n;
    while (tmp)
    {
      s = (char)(tmp % i + '0') + s;
      tmp /= i;
    }
    if (s == x)
    {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}
