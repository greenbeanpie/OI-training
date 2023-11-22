#include<bits/stdc++.h>
using namespace std;

int maxx[3005],minn[3005],n,m;
char a[3005][3005];

int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	if(n==1){cout<<"1";return 0;}
	
	for(int i=1;i<=n;i++) minn[i]=100;
	
	for(int i=1;i<=n;i++)
	{
		char ch=getchar();
		for(int j=1;j<=m;j++)
		{
			a[i][j]=getchar();
			maxx[i]=max(maxx[i],a[i][j]-'a'+1);
			minn[i]=min(minn[i],a[i][j]-'a'+1);
		}
	}
		
	for(int i=1;i<=n;i++)
	{	
		int flag=1;
		for(int j=1;j<=n;j++)
			if(j!=i)
			{
				if(minn[i]>=maxx[j])
				{
					flag=0;
					break;
				}
			}
		printf("%d",flag);
	}
}
/*
4 7
abandon
bananaa
baannaa
notnotn
*/
/*
15 2
zx
qn
wn
nd
pl
pd
vm
ff
mh
ql
zi
yv
md
ji
oc
*/