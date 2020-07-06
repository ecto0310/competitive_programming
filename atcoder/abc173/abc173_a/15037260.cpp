// URL: https://atcoder.jp/contests/abc173/submissions/15037260
// Date: Mon, 06 Jul 2020 13:14:28 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N;
  cin >> N;
  cout << (N % 1000 == 0 ? 0 : 1000 - N % 1000) << endl;
  return 0;
}
