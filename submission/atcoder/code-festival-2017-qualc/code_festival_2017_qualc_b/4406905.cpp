// URL: https://atcoder.jp/contests/code-festival-2017-qualc/submissions/4406905
// Date: Thu, 28 Feb 2019 00:29:38 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++)
    cin >> A[i];
  int tmp = 1;
  for (int t : A)
    if (t % 2 == 0)
      tmp *= 2;
  cout << pow(3, N) - tmp << endl;

  return 0;
}
