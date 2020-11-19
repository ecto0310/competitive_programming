// URL: https://atcoder.jp/contests/abc001/submissions/4640004
// Date: Wed, 20 Mar 2019 18:01:43 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  double Deg, Dis;
  cin >> Deg >> Dis;
  Dis = round(Dis / 6) / 10;
  if (Dis <= 0.2)
    cout << "C 0" << endl;
  else
  {
    if (3487.5 <= Deg || Deg < 112.5)
      cout << "N";
    else if (Deg < 337.5)
      cout << "NNE";
    else if (Deg < 562.5)
      cout << "NE";
    else if (Deg < 787.5)
      cout << "ENE";
    else if (Deg < 1012.5)
      cout << "E";
    else if (Deg < 1237.5)
      cout << "ESE";
    else if (Deg < 1462.5)
      cout << "SE";
    else if (Deg < 1687.5)
      cout << "SSE";
    else if (Deg < 1912.5)
      cout << "S";
    else if (Deg < 2137.5)
      cout << "SSW";
    else if (Deg < 2362.5)
      cout << "SW";
    else if (Deg < 2587.5)
      cout << "WSW";
    else if (Deg < 2812.5)
      cout << "W";
    else if (Deg < 3037.5)
      cout << "WNW";
    else if (Deg < 3262.5)
      cout << "NW";
    else
      cout << "NNW";
    cout << " ";
    cerr << Dis << endl;
    if (Dis <= 1.5)
      cout << 1;
    else if (Dis <= 3.3)
      cout << 2;
    else if (Dis <= 5.4)
      cout << 3;
    else if (Dis <= 7.9)
      cout << 4;
    else if (Dis <= 10.7)
      cout << 5;
    else if (Dis <= 13.8)
      cout << 6;
    else if (Dis <= 17.1)
      cout << 7;
    else if (Dis <= 20.7)
      cout << 8;
    else if (Dis <= 24.4)
      cout << 9;
    else if (Dis <= 28.4)
      cout << 10;
    else if (Dis <= 32.6)
      cout << 11;
    else
      cout << 12;
    cout << endl;
  }

  return 0;
}
