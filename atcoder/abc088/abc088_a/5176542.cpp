// URL: https://atcoder.jp/contests/abc088/submissions/5176542
// Date: Sun, 28 Apr 2019 21:00:58 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
    i64 n, a;
    cin >> n >> a;
    if (n % 500 <= a)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
