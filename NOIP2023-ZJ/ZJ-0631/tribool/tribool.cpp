#include <bits/stdc++.h>
using namespace std;
#define LL long long
int c,t;
int n,m;
int caozuo[100100][3];
int ans;
int meiju[100100];
int tmp[100100];
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
bool isok()
{
	for(int i=1;i<=n;i++)
		tmp[i]=meiju[i];
	for(int i=1;i<=m;i++)
	{
		if(caozuo[i][0]=='T')
			tmp[caozuo[i][1]]=1;
		if(caozuo[i][0]=='F')
			tmp[caozuo[i][1]]=0;
		if(caozuo[i][0]=='U')
			tmp[caozuo[i][1]]=2;
		if(caozuo[i][0]=='+')
			tmp[caozuo[i][1]]=tmp[caozuo[i][2]];
		if(caozuo[i][0]=='-')
		{
			if(tmp[caozuo[i][2]]==2)
				tmp[caozuo[i][1]]=2;
			else
				tmp[caozuo[i][1]]=!tmp[caozuo[i][2]];
		}
	}
	for(int i=1;i<=n;i++)
		if(tmp[i]!=meiju[i])
			return 0;
	return 1;
}
void baoli(int deep,int un)
{
	if(deep==n+1)
	{
		if(isok())
			ans=min(ans,un);
		return;
	}
	meiju[deep]=0;
	baoli(deep+1,un);
	meiju[deep]=1;
	baoli(deep+1,un);
	meiju[deep]=2;
	baoli(deep+1,un+1);
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	c=read(),t=read();
	while(t--)
	{
		memset(caozuo,0,sizeof(caozuo));
		n=read();
		m=read();
		for(int i=1;i<=m;i++)
		{
			caozuo[i][0]=getchar();
			if(caozuo[i][0]=='T'||caozuo[i][0]=='F'||caozuo[i][0]=='U')
				caozuo[i][1]=read();
			else
				caozuo[i][1]=read(),caozuo[i][2]=read();
		}
		ans=n;
		if(c<=2)
			baoli(1,0),printf("%d\n",ans);
		else
			cout<<"0\n";
	}
	return 0;
}
