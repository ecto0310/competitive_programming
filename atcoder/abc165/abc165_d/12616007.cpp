// URL: https://atcoder.jp/contests/abc165/submissions/12616007
// Date: Sat, 02 May 2020 21:54:28 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 A, B, N;
  cin >> A >> B >> N;
  N = min(N, B - 1);
  cout << A * N / B - A * (N / B) << endl;
  return 0;
}
