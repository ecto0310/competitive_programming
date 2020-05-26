// URL: https://atcoder.jp/contests/yahoo-procon2019-qual/submissions/4220459
// Date: Sun, 10 Feb 2019 05:05:06 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  vector<int> cnt(5);
  for (int i = 0; i < 6; i++)
  {
    int t;
    cin >> t;
    cnt[t]++;
  }
  if (cnt[1] < 3 && cnt[2] < 3 && cnt[3] < 3 && cnt[4] < 3)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}
