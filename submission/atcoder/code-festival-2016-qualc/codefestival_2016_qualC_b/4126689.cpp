// URL: https://atcoder.jp/contests/code-festival-2016-qualc/submissions/4126689
// Date: Wed, 30 Jan 2019 16:45:54 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int K, T;
  cin >> K >> T;
  vector<int> a(T);
  for (int i = 0; i < T; i++)
    cin >> a[i];
  cout << max(0, *max_element(a.begin(), a.end()) * 2 - K - 1) << endl;

  return 0;
}
