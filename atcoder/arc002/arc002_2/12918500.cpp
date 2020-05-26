// URL: https://atcoder.jp/contests/arc002/submissions/12918500
// Date: Thu, 07 May 2020 15:12:09 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  string S;
  cin >> S;
  i64 Y = stoll(S.substr(0, 4)), M = stoll(S.substr(5, 2)), D = stoll(S.substr(8, 2));
  while (Y % (M * D) != 0)
  {
    D++;
    if ((M == 4 || M == 6 || M == 9 || M == 11) && D == 31)
    {
      M++;
      D = 1;
    }
    if ((M == 1 || M == 3 || M == 5 || M == 7 || M == 8 || M == 10 || M == 12) && D == 32)
    {
      M++;
      D = 1;
    }
    if ((Y % 4 == 0 && Y % 100 != 0 || Y % 400 == 0) && M == 2 && D == 30)
    {
      M++;
      D = 1;
    }
    else if (!(Y % 4 == 0 && Y % 100 != 0 || Y % 400 == 0) && M == 2 && D == 29)
    {
      M++;
      D = 1;
    }
    if (M == 13)
    {
      M = 1;
      Y++;
    }
  }

  cout << setfill('0') << setw(4) << Y << "/" << setw(2) << M << "/" << setw(2) << D << endl;
  return 0;
}
