// URL: https://atcoder.jp/contests/abc191/submissions/20001483
// Date: Sat, 06 Feb 2021 22:37:04 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

#include <boost/multiprecision/cpp_dec_float.hpp>
namespace mp = boost::multiprecision;
using Real = mp::cpp_dec_float_100;

int main()
{
  Real X, Y, R;
  cin >> X >> Y >> R;
  Real ans = 0;
  for (Real i = mp::ceil(X - R); i <= mp::floor(X + R); i++)
  {
    Real p = mp::sqrt(pow(R, 2) - mp::pow(X - i, 2));
    Real one("1");
    ans += (mp::floor(Y + p)) - (mp::ceil(Y - p)) + one;
  }
  cout << ans.str() << endl;
  return 0;
}
