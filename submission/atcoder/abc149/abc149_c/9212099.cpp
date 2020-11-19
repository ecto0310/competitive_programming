// URL: https://atcoder.jp/contests/abc149/submissions/9212099
// Date: Sun, 29 Dec 2019 20:09:50 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

bool prime(i64 n)
{
  if (n < 2)
    return false;
  else if (n == 2)
    return true;
  else if (n % 2 == 0)
    return false;
  i64 l = sqrt(n);
  for (int i = 3; i <= l; i += 2)
    if (n % i == 0)
      return false;
  return true;
}

int main()
{
  i64 x;
  cin >> x;
  for (i64 i = x;; i++)
    if (prime(i))
    {
      cout << i << endl;
      return 0;
    }
  return 0;
}
