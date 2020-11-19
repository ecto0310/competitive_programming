// URL: https://atcoder.jp/contests/abc173/submissions/15037274
// Date: Mon, 06 Jul 2020 13:16:10 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N;
  cin >> N;
  map<string, i64> c;
  for (i64 i = 0; i < N; i++)
  {
    string S;
    cin >> S;
    c[S]++;
  }
  cout << "AC x " << c["AC"] << endl
       << "WA x " << c["WA"] << endl
       << "TLE x " << c["TLE"] << endl
       << "RE x " << c["RE"] << endl;
  return 0;
}
