// URL: https://atcoder.jp/contests/tenka1-2019-beginner/submissions/5065243
// Date: Sat, 20 Apr 2019 23:38:39 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 a, b, c;
  cin >> a >> b >> c;
  if ((a < c && c < b) || (b < c && c < a))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}
