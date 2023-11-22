#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int c,t,n,m,ai,aj;
char v;
int x[N];
char x2[N];
bool book[N],fu;
int tong[N];
int huan[N],tail;
int ans=0;
int jdz(int kk) {return max(kk,0-kk);}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&c,&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d%d",&n,&m);
		for(int j=1;j<=n;j++) book[j]=true;
		for(int j=1;j<=n;j++) x[j]=j;
		for(int j=1;j<=m;j++)
		{
			scanf("%c",&v);
			if(v=='-')
			{
				scanf("%d%d",&ai,&aj);
				x[ai]=0-x[aj];
				x2[ai]=' ';
			}
			else if(v=='+')
			{
				scanf("%d%d",&ai,&aj);
				x[ai]=x[aj];
				x2[ai]=' ';
			}
			else
			{
				scanf("%d",&ai);
				x2[ai]=v;
				x[ai]=0;
			}
		}
		for(int j=1;j<=n;j++)
		{
			if(book[j]&&x[j]!=0)
			{
				if(j>0) fu=true;
				if(j<0) fu=false;
				huan[1]=j;
				tail=2;
				tong[huan[1]]=1;
				while(1)
				{
					huan[tail]=jdz(x[huan[tail-1]]);
					if(tong[huan[tail]]!=0)
					{
						if(tong[huan[tail]]!=1)
						{
							for(int o=1;o<tong[huan[tail]];o++)
							book[o]=false;
						}
						else
						{
							if(!fu) ans=ans+tail-1;
							for(int o=1;o<=tail;o++)
							book[huan[o]]=false;
						}
						break;
					}
					if(huan[tail]==0)
					{
						for(int o=1;o<=tail;o++)
						{
							book[huan[o]]=false;
						}
						if(x2[huan[tail-1]]=='U') ans=ans+tail-1;
						break;
					}
					tong[huan[tail]]=tail;
					tail++;
				}
			}
		}
		printf("%d",ans);
		ans=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}