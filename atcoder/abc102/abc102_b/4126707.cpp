// URL: https://atcoder.jp/contests/abc102/submissions/4126707
// Date: Wed, 30 Jan 2019 16:49:19 +0900
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
  cout << *max_element(A.begin(), A.end()) - *min_element(A.begin(), A.end()) << endl;

  return 0;
}
