// URL: https://atcoder.jp/contests/abc188/submissions/19848645
// Date: Mon, 01 Feb 2021 00:47:13 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N;
  cin >> N;
  vector<i64> A(1 << N);
  for (i64 i = 0; i < (1 << N); i++)
    cin >> A[i];
  i64 m = std::max_element(A.begin(), A.end()) - A.begin();
  if (m < (1 << (N - 1)))
    cout << max_element(A.begin() + (1 << (N - 1)), A.end()) - A.begin() + 1 << endl;
  else
    cout << max_element(A.begin(), A.begin() + (1 << (N - 1))) - A.begin() + 1 << endl;
  return 0;
}
