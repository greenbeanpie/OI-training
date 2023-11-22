#include<bits/stdc++.h>
#define re register
using namespace std;
const int N=3010;
int n,m,flag,a[30];
char s[N];
string ansmax,ansmin,maxx[N],minn[N];
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==1)
	{
		putchar('1');
		return 0;
	}
	for(re int i=1;i<=n;i++)
	{
		ansmin="",ansmax="";
		memset(a,0,sizeof(a));
		scanf("%s",s+1);
		for(re int j=1;j<=m;j++)a[s[j]-'a']++;
		for(re int j=0;j<=25;j++)
		{
			while(a[j]--)
			{
				ansmin+=(char)('a'+j);
				ansmax=(char)('a'+j)+ansmax;
			}
		}
		maxx[i]=ansmax,minn[i]=ansmin;
    }
    for(re int i=1;i<=n;i++)
    {
    	flag=1;
    	for(re int j=1;j<=n;j++)
    	{
    		if(i==j)continue;
    		if(minn[i]>=maxx[j])
    		{
    			flag=0;
    			break;
			}
		}
		putchar('0'+flag);
	}
	return 0;
}
