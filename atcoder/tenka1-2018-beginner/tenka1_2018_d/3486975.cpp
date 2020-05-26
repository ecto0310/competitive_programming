// URL: https://atcoder.jp/contests/tenka1-2018-beginner/submissions/3486975
// Date: Sat, 27 Oct 2018 22:34:36 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int tmp = 0, k;
	for (int i = 1; tmp < n; i++)
	{
		tmp += i;
		k = i + 1;
	}
	if (n != tmp)
	{
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	cout << k << endl;
	vector<vector<int>> s(k);
	int next = 1;
	for (int i = 0; i < k; i++)
		for (int j = i + 1; j < k; j++)
		{
			s[i].push_back(next);
			s[j].push_back(next);
			next++;
		}
	int size = s[0].size();
	for (int i = 0; i < k; i++)
	{
		cout << size << " ";
		for (int j = 0; j < size; j++)
			cout << s[i][j] << (j == size - 1 ? "" : " ");
		cout << endl;
	}

	return 0;
}
