#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int s=0;
	bool f=false;
	char c=getchar();
	while(!isdigit(c))
	{
		f=(c=='-');
		c=getchar();
	}
	while(isdigit(c))
	{
		s=(s<<3)+(s<<1)+c-'0';
		c=getchar();
	}
	return f?-s:s;
}
void write(int x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9)
	{
		write(x/10);
	}
	putchar(x%10+'0');
}
int n,m;
string s[3005],b[3005];
signed main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		b[i]=s[i];
		sort(s[i].begin(),s[i].end());
		for(int j=0;j<m;j++)
		{
			b[i][j]=s[i][m-j-1];
		}
	}
	for(int i=1;i<=n;i++)
	{
		bool flag=true;
		for(int j=1;j<=n;j++)
		{
			if(j==i)
			{
				continue;
			}
			if(s[i]>=b[j])
			{
				flag=false;
				break;
			}
		}
		if(flag)
		{
			putchar('1');
		}
		else
		{
			putchar('0');
		}
	}
	return 0;
}