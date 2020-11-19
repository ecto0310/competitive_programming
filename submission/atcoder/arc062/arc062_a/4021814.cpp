// URL: https://atcoder.jp/contests/arc062/submissions/4021814
// Date: Wed, 16 Jan 2019 02:09:07 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int N;
  cin >> N;
  long long T = 1, A = 1;
  while (N--)
  {
    long long t, a;
    cin >> t >> a;
    long long n = max((T + t - 1) / t, (A + a - 1) / a);
    T = t * n;
    A = a * n;
  }
  cout << T + A << endl;

  return 0;
}
