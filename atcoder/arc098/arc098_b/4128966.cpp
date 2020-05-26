// URL: https://atcoder.jp/contests/arc098/submissions/4128966
// Date: Wed, 30 Jan 2019 23:05:42 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++)
    cin >> A[i];
  long long ans = 0, sum = 0;
  int right = 0, bit = 0;
  for (int i = 0; i < N; i++)
  {
    while ((sum + A[right]) == (bit ^ A[right]) && right < N)
    {
      sum += A[right];
      bit ^= A[right];
      right++;
    }
    ans += right - i;
    sum -= A[i];
    bit ^= A[i];
  }
  cout << ans << endl;

  return 0;
}
