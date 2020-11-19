// URL: https://atcoder.jp/contests/keyence2019/submissions/4002429
// Date: Sun, 13 Jan 2019 21:20:52 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<long long> A(N), B(N);
  for (int i = 0; i < N; i++)
    cin >> A[i];
  for (int i = 0; i < N; i++)
    cin >> B[i];
  long long sum = 0, minus = 0, cnt = 0;
  vector<long long> dif(N);
  for (int i = 0; i < N; i++)
  {
    dif[i] = A[i] - B[i];
    sum += dif[i];
    if (dif[i] < 0)
    {
      minus -= dif[i];
      cnt++;
    }
  }
  if (sum < 0)
  {
    cout << -1 << endl;
    return 0;
  }
  sort(dif.begin(), dif.end(), greater<long long>());
  long long tmp = 0;
  for (int i = 0; i < N && 0 < dif[i]; i++)
  {
    if (minus <= tmp)
    {
      cout << cnt + i << endl;
      return 0;
    }
    tmp += dif[i];
  }
  cout << N << endl;

  return 0;
}
