#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,b[3010][30];
string s;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int x,flag;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		for(int j=0;j<s.length();j++)
		{
			x=s[j]-'a'+1;
			b[i][x]++;
		}
	}
	if(n==1) cout<<1;
	else 
	{
		for(int i=1;i<=n;i++)
		{
			x=0,flag=0;
			for(int j=1;j<=26;j++) 
				if(b[i][j]>0) 
				{
					x=j;
					break ;
				}
			for(int j=1;j<=n;j++)
			{
				if(j!=i) 
				{
					for(int k=26;k>=1;k--)
					{
						if(b[j][k]>0)
						{
							if(k<=x) flag=1;
							//if(k==x&&b[i][x]>=b[j][k]) flag=1;
							break ;
						}
					}
				}
				if(flag==1) break ;
			}
			if(flag==1) cout<<0;
			else cout<<1;
		}		
	}
	return 0;
}
