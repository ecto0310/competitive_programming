// URL: https://atcoder.jp/contests/arc003/submissions/11551403
// Date: Sat, 04 Apr 2020 23:26:11 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N;
  string r;
  cin >> N >> r;
  i64 sum = 0;
  for (i64 i = 0; i < N; i++)
    if (r[i] == 'A')
      sum += 4;
    else if (r[i] == 'B')
      sum += 3;
    else if (r[i] == 'C')
      sum += 2;
    else if (r[i] == 'D')
      sum += 1;
  cout << fixed << setprecision(10) << (double)sum / N << endl;
  return 0;
}
