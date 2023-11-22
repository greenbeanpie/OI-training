#include<bits/stdc++.h>
#define F(i,l,r) for(int i=l,i##end=r;i<=i##end;++i)
using namespace std;
char s[509][509];
char t[509][509];
mt19937 rnd(time(0));
int main()
{
	freopen("dict.in","w",stdout);
	int n=1000,m=500;
	cout<<n<<" "<<m<<endl;
	F(i,1,n)
	{
		F(i,1,m)
		{
			cout<<(char)(rnd()%26+'a');
		}
		cout<<endl;
	}
}
/*
4 7
abandon
bananaa
baannaa
notnotn

*/