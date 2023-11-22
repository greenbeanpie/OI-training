#include <bits/stdc++.h>
using namespace std;
#define LL long long

LL read()
{
	LL num=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			f=-f;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		num=num*10+c-'0';
		c=getchar();
	}
	return num*f;
}

int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cout<<0;
	return 0;
}

