// URL: https://atcoder.jp/contests/nikkei2019-qual/submissions/4096699
// Date: Sun, 27 Jan 2019 21:01:26 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int N, A, B;
  cin >> N >> A >> B;
  cout << min(A, B) << " " << max(0, A + B - N) << endl;

  return 0;
}
