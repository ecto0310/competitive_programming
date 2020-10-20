// URL: https://atcoder.jp/contests/joi2021yo1a/submissions/17539613
// Date: Tue, 20 Oct 2020 16:27:16 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 A, B, C;
  cin >> A >> B >> C;
  cout << A + B + C - max({A, B, C}) - min({A, B, C}) << endl;
  return 0;
}
