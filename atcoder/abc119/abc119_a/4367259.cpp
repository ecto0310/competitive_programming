// URL: https://atcoder.jp/contests/abc119/submissions/4367259
// Date: Sun, 24 Feb 2019 21:02:05 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>

using namespace std;

int main()
{
  string S;
  cin >> S;
  if (4 < stoi(S.substr(5, 2)))
    cout << "TBD" << endl;
  else
    cout << "Heisei" << endl;

  return 0;
}
