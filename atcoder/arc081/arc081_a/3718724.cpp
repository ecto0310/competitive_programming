// URL: https://atcoder.jp/contests/arc081/submissions/3718724
// Date: Wed, 05 Dec 2018 02:09:01 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	map<int, int> cnt;
	vector<int> vec;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		cnt[a]++;
		if (cnt[a] % 2 == 0)
			vec.push_back(a);
	}
	sort(vec.begin(), vec.end(), greater<int>());
	cout << (vec.size() < 2 ? 0 : (long long)vec[0] * vec[1]) << endl;

	return 0;
}
