// URL: https://atcoder.jp/contests/arc080/submissions/4248226
// Date: Wed, 13 Feb 2019 03:14:43 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int N;
  cin >> N;
  int cnt1 = 0, cnt2 = 0, cnt4 = 0;
  for (int i = 0; i < N; i++)
  {
    int a;
    cin >> a;
    if (a % 4 == 0)
      cnt4++;
    else if (a % 2 == 0)
      cnt2++;
    else
      cnt1++;
  }
  if ((cnt2 > 0 && cnt1 <= cnt4) || (cnt2 == 0 && cnt1 <= cnt4 + 1))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}
