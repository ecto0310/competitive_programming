// URL: https://atcoder.jp/contests/dwacon2017-prelims/submissions/12865697
// Date: Tue, 05 May 2020 23:05:01 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  string T;
  cin >> T;
  i64 ans = 0;
  for (i64 p = 0; p < 2; p++)
  {
    i64 cnt = 0;
    for (i64 i = 0; i < T.size(); i++)
    {
      if (i % 2 == p)
      {
        if (T[i] == '?' || T[i] == '2')
          cnt++;
        else
          cnt = 0;
      }
      else if (cnt != 0)
      {

        if (T[i] == '?' || T[i] == '5')
          cnt++;
        else
          cnt = 0;
      }
      ans = max(ans, cnt);
    }
  }
  cout << (ans / 2) * 2 << endl;
  return 0;
}
