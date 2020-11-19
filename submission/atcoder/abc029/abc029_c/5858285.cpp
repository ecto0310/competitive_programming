// URL: https://atcoder.jp/contests/abc029/submissions/5858285
// Date: Sun, 09 Jun 2019 23:12:10 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

void f(i64 n, string s)
{
      if (n == 0)
            cout << s << endl;
      else
            for (i64 i = 0; i < 3; i++)
                  f(n - 1, s + (char)('a' + i));
}

int main()
{
      i64 n;
      cin >> n;
      f(n, "");
      return 0;
}
