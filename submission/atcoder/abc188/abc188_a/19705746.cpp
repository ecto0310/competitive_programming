// URL: https://atcoder.jp/contests/abc188/submissions/19705746
// Date: Tue, 26 Jan 2021 18:43:03 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 X, Y;
  cin >> X >> Y;
  if (abs(X - Y) < 3)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
