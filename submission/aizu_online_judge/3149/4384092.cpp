// URL: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=4384092
// Date: Tue, 21 Apr 2020 23:08:53 +0900
// Language: C++14
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N;
  cin >> N;
  if (N == 1)
    cout << 1 << endl
         << 1 << endl;
  else if (N == 2)
    cout << 2 << endl
         << 0 << endl
         << 11 << endl;
  else
  {
    cout << N - 1 << endl;
    string ans = "1";
    for (i64 i = 0; i < N - 1; i++)
    {
      cout << ans << "1" << endl;
      ans += "0";
    }
  }
  return 0;
}
