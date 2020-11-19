// URL: https://atcoder.jp/contests/arc026/submissions/16618114
// Date: Thu, 10 Sep 2020 23:47:19 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N;
  cin >> N;
  i64 sum = -N;
  for (i64 i = 1; i * i <= N; i++)
    if (N % i == 0)
    {
      sum += i;
      if (N / i != i)
        sum += N / i;
    }
  if (N == sum)
    cout << "Perfect" << endl;
  else if (N < sum)
    cout << "Abundant" << endl;
  else
    cout << "Deficient" << endl;
  return 0;
}
