// URL: https://atcoder.jp/contests/abc162/submissions/11787648
// Date: Sun, 12 Apr 2020 21:00:48 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  string N;
  cin >> N;
  for (i64 i = 0; i < 3; i++)
    if (N[i] == '7')
    {
      cout << "Yes" << endl;
      return 0;
    }
  cout << "No" << endl;
  return 0;
}
