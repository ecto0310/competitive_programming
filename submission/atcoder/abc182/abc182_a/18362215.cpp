// URL: https://atcoder.jp/contests/abc182/submissions/18362215
// Date: Mon, 23 Nov 2020 13:57:43 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 A, B;
  cin >> A >> B;
  cout << max(0LL, 2 * A + 100 - B) << endl;
  return 0;
}
