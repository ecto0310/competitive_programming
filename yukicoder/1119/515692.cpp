// URL: https://yukicoder.me/submissions/515692
// Date: Wed, 22 Jul 2020 21:21:02 +0900
// Language: C++17(1z)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 X, Y, Z;
  cin >> X >> Y >> Z;
  if (X * Y % 3 * Z % 3 == 0)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
