#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 A, B;
  cin >> A >> B;
  if (A < B)
    cout << "Error" << endl;
  else
    cout << A - B << endl;
  return 0;
}
