// URL: https://atcoder.jp/contests/abc111/submissions/3304166
// Date: Sun, 30 Sep 2018 00:06:39 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int n;
  cin >> n;
  for (int i = n; i < 1000; i++)
    if (i % 111 == 0)
    {
      cout << i << endl;
      return 0;
    }

  return 0;
}
