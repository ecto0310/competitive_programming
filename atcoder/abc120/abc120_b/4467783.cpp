// URL: https://atcoder.jp/contests/abc120/submissions/4467783
// Date: Mon, 04 Mar 2019 18:04:46 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int A, B, K;
  cin >> A >> B >> K;
  int cnt = 0;
  for (int i = A; 0 < i; i--)
  {
    if (A % i == 0 && B % i == 0)
      cnt++;
    if (cnt == K)
    {
      cout << i << endl;
      break;
    }
  }

  return 0;
}
