// URL: https://atcoder.jp/contests/abc158/submissions/10592530
// Date: Sat, 07 Mar 2020 21:04:22 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 N, A, B;
  cin >> N >> A >> B;
  cout << N / (A + B) * A + min(A, N - N / (A + B) * (A + B)) << endl;
  return 0;
}
