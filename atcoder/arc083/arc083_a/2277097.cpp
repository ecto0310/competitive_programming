// URL: https://atcoder.jp/contests/arc083/submissions/2277097
// Date: Thu, 29 Mar 2018 22:28:53 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
	int A,B,C,D,E,F;
	cin>> A>> B>> C>> D>> E>> F;

	
	int sugar,water;
	float par=0;
	for(int a=0;a<=F;a+=100*A)
	for(int b=0;a+b<=F;b+=100*B)
	for(int c=0;a+b+c<=F;c+=C)
	for(int d=0;a+b+c+d<=F;d+=D)
	{
		float x=a+b,y=c+d;
		if(x+y!=0&&(float)E/100>=y/x&&par<=(y)/(x+y))
		{
			par=y/(x+y);
			water=x+y;
			sugar=y;
		}
	}
	cout<< water<< " "<< sugar<< endl;
	
	return 0;
}
