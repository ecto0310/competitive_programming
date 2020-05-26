// URL: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=4007696
// Date: Mon, 25 Nov 2019 23:22:06 +0900
// Language: C++14
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 pow(i64 a, i64 n)
{
  i64 ret = 1;
  for (; 0 < n; n >>= 1, a = a * a)
    if (n % 2 == 1)
      ret *= a;
  return ret;
}

int main()
{
  i64 l, n;
  string snake;
  cin >> l >> n >> snake;
  i64 ans = l, t = (1 - pow(2, n)) / -1;
  for (i64 i = 0; i < l - 1; i++)
    if (snake[i] == 'o' && snake[i + 1] == 'o')
      ans += t * 3;
  cout << ans << endl;
  return 0;
}
