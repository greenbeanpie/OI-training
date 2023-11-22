//几相逢，难回首。行将陌路，同归殊途 
#include<bits/stdc++.h>
using namespace std;
int n;
int m;
int ch[3005][3005];
string s[3005];
string sb;
char ccf;
bool flag;
priority_queue<char,vector<char>,greater<char> > q[3005];
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==1)
	{
		printf("1");
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		sb+="z";
	}
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		sb=min(sb,s[i]);
		for(int j=0;j<m;j++)
		{
			q[i].push(s[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		flag=true;
		for(int j=0;j<m;j++)
		{
			ccf=q[i].top();
			if(ccf<sb[j])
			{
				break;
			}
			if(ccf>sb[j])
			{
				flag=false;
				break;
			}
		}
		if(flag)
		{
			printf("1");
		}else{
			printf("0");
		}
	}
 	return 0;
}

