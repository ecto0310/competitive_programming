// URL: https://atcoder.jp/contests/abc199/submissions/21996857
// Date: Sat, 24 Apr 2021 21:03:00 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main() {
    i64 N;
    cin >> N;
    vector<i64> A(N), B(N);
    for (i64 i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (i64 i = 0; i < N; i++) {
        cin >> B[i];
    }
    cout << max(0LL, *min_element(B.begin(), B.end()) - *max_element(A.begin(), A.end()) + 1) << endl;
    return 0;
}
