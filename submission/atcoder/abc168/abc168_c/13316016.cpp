// URL: https://atcoder.jp/contests/abc168/submissions/13316016
// Date: Sun, 17 May 2020 21:23:16 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

const double PI = 3.141592653589793;

int main()
{
  i64 A, B, H, M;
  cin >> A >> B >> H >> M;
  double Ax = cos(2 * PI / 12 * H + 2 * PI / 12 / 60 * M) * A, Ay = sin(2 * PI / 12 * H + 2 * PI / 12 / 60 * M) * A;
  double Bx = cos(2 * PI / 60 * M) * B, By = sin(2 * PI / 60 * M) * B;
  cout << fixed << setprecision(10) << hypot(Ax - Bx, Ay - By) << endl;
  return 0;
}
