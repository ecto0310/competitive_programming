// URL: https://atcoder.jp/contests/panasonic2020/submissions/10827528
// Date: Sat, 14 Mar 2020 21:01:59 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

i64 N[] = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};

int main()
{
  i64 K;
  cin >> K;
  cout << N[K - 1] << endl;

  return 0;
}
