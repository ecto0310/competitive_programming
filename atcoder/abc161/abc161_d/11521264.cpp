// URL: https://atcoder.jp/contests/abc161/submissions/11521264
// Date: Sat, 04 Apr 2020 21:30:17 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

i64 pow(i64 x, i64 n)
{
  i64 ret = 1;
  while (n > 0)
  {
    if ((n & 1) == 1)
    {
      ret = ret * x;
    }
    x = x * x;
    n >>= 1;
  }
  return ret;
}

int main()
{
  i64 K;
  cin >> K;
  priority_queue<i64, vector<i64>, greater<i64>> que;
  for (i64 i = 1; i < 10; i++)
    que.push(i);
  for (i64 i = 0; i < K - 1; i++)
  {
    i64 p = que.top();
    que.pop();
    if (p % 10 != 0)
      que.push(p * 10 + p % 10 - 1);
    que.push(p * 10 + p % 10);
    if (p % 10 != 9)
      que.push(p * 10 + p % 10 + 1);
  }
  cout << que.top() << endl;
  return 0;
}
