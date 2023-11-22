#include<bits/stdc++.h>
using namespace std;
const int maxn=3e3+10;
typedef long long ll;
bool begin;
int n,m;
int t[maxn][30];
char c[maxn][maxn],p[maxn][maxn];//c small p bigggg
bool comp(int x,int y)
{
	for(int i=0;i<m;i++)
	{
		if(p[x][i]<p[y][i])
			return 1;
		if(p[x][i]>p[y][i])
			return 0;
	}
	return 0;
}
bool comt(int x,int y)
{
	for(int i=0;i<m;i++)
	{
		if(c[x][i]<p[y][i])
			return 1;
		if(c[x][i]>p[y][i])
			return 0;
	}
	return 0;
}
int ans[maxn];
bool end;
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		ans[i]=1;
		cin>>c[i];
		for(int j=0;j<m;j++)
			t[i][c[i][j]-'a'+1]++;
	}
	for(int i=1;i<=n;i++)
	{
		int tot1=-1,tot2=m;
		for(int k=1;k<=26;k++)
		{
			while(t[i][k]>0)
			{
				t[i][k]--;
				c[i][++tot1]=char(k+'a'-1);
				p[i][--tot2]=char(k+'a'-1);
			}
		}
//		cout<<c[i]<<endl<<p[i]<<endl<<endl;
	}
	int mni=1;
	for(int i=2;i<=n;i++)
	{
		if(comp(i,mni)==1)
			mni=i;
	}
	for(int i=1;i<=n;i++)
	{
		if(i==mni)
			continue;
		if(comt(i,mni)==0)
			ans[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		if(i==mni)
			continue;
		if(comt(mni,i)==0)
			ans[mni]=0;
	}
	for(int i=1;i<=n;i++)
		printf("%d",ans[i]);
	return 0;
}

