// URL: https://atcoder.jp/contests/agc004/submissions/2935905
// Date: Fri, 03 Aug 2018 00:44:54 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int h, w;
	cin >> h >> w;
	string a[500];
	for (int i = 0; i < h; i++)
		cin >> a[i];
	for (int i = 0; i < h; i++)
	{
		if (i % 2 == 0)
		{
			for (int j = 0; j < w - 1; j++)
				cout << "#";
			if (a[i][w] == '#')
				cout << "#" << endl;
			else
				cout << "." << endl;
		}
		else
		{
			cout << "#";
			for (int j = 1; j < w; j++)
				if (a[i][j] == '#')
					cout << "#";
				else
					cout << ".";
			cout << endl;
		}
	}
	cout << endl;
	for (int i = 0; i < h; i++)
	{
		if (i % 2 == 0)
		{
			for (int j = 0; j < w - 1; j++)
				if (a[i][j] == '#')
					cout << "#";
				else
					cout << ".";
			cout << "#" << endl;
		}
		else
		{
			if (a[i][0] == '#')
				cout << "#";
			else
				cout << ".";
			for (int i = 1; i < w; i++)
				cout << "#";
			cout << endl;
		}
	}

	return 0;
}
