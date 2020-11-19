// URL: https://atcoder.jp/contests/abc165/submissions/12578604
// Date: Sat, 02 May 2020 21:11:01 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{

  i64 K, A, B;
  cin >> K >> A >> B;
  for (i64 i = A; i <= B; i++)
    if (i % K == 0)
    {
      cout << "OK" << endl;
      return 0;
    }
  cout << "NG" << endl;
  return 0;
}
