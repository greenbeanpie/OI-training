#include <bits/stdc++.h>
using namespace std;
#define N 3005
inline int read()
{
	int s=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=s*10+ch-48;ch=getchar();}
	return s*f;
}
int n,m;
int t[N][30],ma[2][30],ind[2];
char s[N][N];
void change(int p)
{
	for(int i=25;i>=0;i--)
	{
		if(p==1||t[p][i]<t[ind[0]][i])
		{
			ind[1]=ind[0];
			ind[0]=p;
			return;
		}
		if(t[p][i]>t[ind[0]][i]) break;
	}
	for(int i=25;i>=0;i--)
	{
		if(p==2||t[p][i]<t[ind[1]][i])
		{
			ind[1]=p;
			return;
		}
		if(t[p][i]>t[ind[1]][i]) break;
	}
}
bool judge(int p)
{
	int l=0,r=25,s1=0,s2=0,tot=0;
	if(p!=ind[0])
	{
		while(tot<m)
		{
			while(t[p][l]<=s1) l++,s1=0;
			while(t[ind[0]][r]<=s2) r--,s2=0;
			if(l<r) return 1;
			if(l>r) return 0;
			s1++;s2++;tot++;
		} 
	}
	else
	{
		while(tot<m)
		{
			while(t[p][l]<=s1) l++,s1=0;
			while(t[ind[1]][r]<=s2) r--,s2=0;
			if(l<r) return 1;
			if(l>r) return 0;
			s1++;s2++;tot++;
		} 
	}
	return 0;
}
signed main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d %d",&n,&m);
	memset(ma[0],0x3f,sizeof(ma[0]));
	memset(ma[1],0x3f,sizeof(ma[1]));
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s[i]+1);
		for(int j=1;j<=m;j++) t[i][s[i][j]-'a']++;
		change(i);
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d",judge(i));
	}
	return 0;
}