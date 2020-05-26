// URL: https://atcoder.jp/contests/agc012/submissions/3221124
// Date: Tue, 18 Sep 2018 21:23:28 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  long long n;
  cin >> n;
  n++;
  int cnt = 0;
  long long tmp = n;
  while (tmp)
  {
    tmp /= 2;
    cnt++;
  }
  deque<int> deq;
  long long now = 1;
  int t = 1;
  for (int i = cnt - 2; i >= 0; i--)
  {
    deq.push_back(t);
    now *= 2;
    t++;
    if ((now + 1) << i <= n)
    {
      deq.push_front(t);
      now++;
      t++;
    }
  }
  int size = deq.size();
  cout << size * 2 << endl;
  for (int i = 1; i <= size; i++)
    cout << i << " ";
  for (int i = 0; i < size; i++)
    cout << deq[i] << (i + 1 == size ? "\n" : " ");

  return 0;
}
