// URL: https://atcoder.jp/contests/agc020/submissions/4037699
// Date: Fri, 18 Jan 2019 23:15:00 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int N, A, B;
  cin >> N >> A >> B;
  if ((B - A) % 2 == 0)
    cout << "Alice" << endl;
  else
    cout << "Borys" << endl;

  return 0;
}
