// URL: https://atcoder.jp/contests/agc013/submissions/4037452
// Date: Fri, 18 Jan 2019 22:46:57 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> A;
  for (int i = 0; i < N; i++)
  {
    int tmp;
    cin >> tmp;
    if (i == 0 || tmp != A.back())
      A.push_back(tmp);
  }
  int size = A.size(), ans = 1, t = 0;
  for (int i = 1; i < size; i++)
    if (t != i - 1 && (A[i - 2] < A[i - 1]) != (A[i - 1] < A[i]))
    {
      ans++;
      t = i;
    }
  cout << ans << endl;

  return 0;
}
