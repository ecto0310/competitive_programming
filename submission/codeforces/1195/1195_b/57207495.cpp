// URL: https://codeforces.com/contest/1195/submission/57207495
// Date: Wed, 17 Jul 2019 23:50:13 +0900
// Language: GNU C++14
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, k;
  cin >> n >> k;
  i64 sum = 0;
  for (i64 i = 1; i <= n; i++)
  {
    sum += i;
    if (sum - n + i == k)
    {
      cout << n - i << endl;
      return 0;
    }
  }
  return 0;
}
