// URL: https://atcoder.jp/contests/abc117/submissions/4154726
// Date: Sun, 03 Feb 2019 21:04:22 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> L(N);
  for (int i = 0; i < N; i++)
    cin >> L[i];
  sort(L.begin(), L.end());
  int sum = 0;
  for (int i = 0; i < N - 1; i++)
    sum += L[i];
  if (L[N - 1] < sum)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}
