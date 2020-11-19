// URL: https://atcoder.jp/contests/cf16-final-open/submissions/8564641
// Date: Sat, 23 Nov 2019 11:28:59 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  i64 sum = 0;
  for (i64 i = 1;; i++)
  {
    sum += i;
    if (n <= sum)
    {
      for (i64 j = 1; j <= i; j++)
        if (sum - n != j)
          cout << j << endl;
      break;
    }
  }
  return 0;
}
