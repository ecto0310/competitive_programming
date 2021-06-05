// URL: https://atcoder.jp/contests/joi2019yo/submissions/23181509
// Date: Sat, 05 Jun 2021 15:24:52 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int n;
vector<int> a;

int cnt(int t) {
    if (t < 0)
        return -1;
    int ret = 0;
    for (int i = 0; i < n; i++)
        if (t < a[i]) {
            if (i == 0 || a[i - 1] <= t)
                ret++;
        }
    return ret;
}

int main() {
    cin >> n;
    a.resize(n);
    map<int, bool> m;
    vector<int> vec;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (!m[a[i] - 1]) {
            vec.push_back(a[i] - 1);
            m[a[i] - 1] = true;
        }
    }
    sort(vec.begin(), vec.end());
    int left = 0, right = vec.size() - 1;
    while (500 < right - left) {
        if (cnt(vec[(left * 2 + right) / 3]) > cnt(vec[(left + right * 2) / 3]))
            right = (left + right * 2) / 3;
        else
            left = (left * 2 + right) / 3;
    }
    int ans = 0;
    for (int i = left; i <= right; i++)
        ans = max(ans, cnt(vec[i]));
    cout << ans << endl;

    return 0;
}
