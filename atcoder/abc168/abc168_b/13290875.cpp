// URL: https://atcoder.jp/contests/abc168/submissions/13290875
// Date: Sun, 17 May 2020 12:02:10 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "
"

int main()
{
  i64 K;
  string S;
  cin >> K >> S;
  if (S.size() <= K)
    cout << S << endl;
  else
    cout << S.substr(0, K) << "..." << endl;
  return 0;
}
