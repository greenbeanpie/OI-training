#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
int s[3001][27],t;
string ans;
int read()
{
	char c;c=getchar();
	while(c<'a'||c>'z'){c=getchar();}
	return c-'a'+1;
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			t=read();
			s[i][t]++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		bool d=1;
		for(int j=1;j<=n;j++)
		{
			if(i==j)
			{
				continue;
			}
			int mt=m;
			for(int k=1;k<=26;k++)
			{
				
				if(s[i][k])
				{
					if(s[j][k]==mt)
					{
						d=0;
					}
					break;
				}else{
					mt-=s[j][k];
				}
			}
			if(!d)
			{
				break;
			}
		}
		if(d){ans+="1";}
		else{ans+="0";}
	}
	cout<<ans;
	return 0;
}