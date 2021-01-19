// URL: https://codeforces.com/contest/1474/submission/104816234
// Date: Wed, 20 Jan 2021 00:46:28 +0900
// Language: GNU C++17
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 t;
  cin >> t;
  for (i64 _ = 0; _ < t; _++)
  {
    i64 d;
    cin >> d;
    i64 t[3] = {1, -1, -1};
    for (i64 i = 1; i < 3; i++)
    {
      for (i64 j = t[i - 1] + d;; j++)
      {
        bool pri = true;
        for (i64 k = 2; k <= sqrt(j); k++)
          if (j % k == 0)
            pri = false;
        if (pri)
        {
          t[i] = j;
          break;
        }
      }
    }
    cout << t[1] * t[2] << endl;
  }
  return 0;
}
