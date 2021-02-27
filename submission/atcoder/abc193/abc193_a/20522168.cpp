// URL: https://atcoder.jp/contests/abc193/submissions/20522168
// Date: Sat, 27 Feb 2021 21:03:54 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main() {
    i64 A, B;
    cin >> A >> B;
    cout << fixed << setprecision(3) << (double) (A - B) / A * 100 << endl;
    return 0;
}
