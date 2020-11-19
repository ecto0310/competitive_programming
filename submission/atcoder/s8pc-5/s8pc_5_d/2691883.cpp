// URL: https://atcoder.jp/contests/s8pc-5/submissions/2691883
// Date: Sun, 17 Jun 2018 09:35:14 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>
#include<assert.h>

using namespace std;


int main()
{
	int h, w;
	cin >> h >> w;
	int hand = ((h > 1 && w > 1 && h * w % 2 == 1) || ((h == 1 || w == 1) && (h + w) % 2 == 1) ? 1 : 0);
	if(hand == 1)cout << "First" << endl;
	else cout << "Second" << endl;
	bool map[50][50] = {};
	map[0][0] = true;
	while(true)
	{
		if(hand == 1)
		{
			for(int i = 0; i < h; i++)
				for(int j = 0; j < w; j++)
				{
					if(hand == 1 && !(i == h - 2 && j == w - 1) && !(i == h - 1 && j == w - 2) && !map[i][j])
					{
						map[i][j] = true;
						cout << i + 1 << " " << j + 1 << endl;
						hand = 0;
					}
				}
		}
		else
		{
			int x, y;
			cin >> x >> y;
			if(x == -1)return 0;
			map[x - 1][y - 1] = true;
			hand = 1;
		}
	}

	return 0;
}
