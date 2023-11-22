#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
int C,T;
int n,m;
int u=0;
int a[102023];
bool q[102023];
int r[102023];
bool w[102023];
bool z[102023];
vector<int>p[102023];
void bl(int x)
{
	for(int i=0;i<p[x].size();i++)
	{
		int y=p[x][i];
		if(!q[y])
		{
			q[y]=1;
			bl(y);
		}
	}
	return;
}
bool abr=0;
bool check(int x)
{
	bool k=true;
	for(int i=0;i<p[x].size();i++)
	{
		int y=p[x][i];
//		printf("[%d]->[%d]\n",x,y);
		if(w[y])continue;
		if(r[y]!=0)
		{
//			printf("FIND A LOOP BETWEEN [%d] and [%d]\n",x,y);
			if((a[y]<0&&r[y]==r[x])||(a[y]>0&&r[y]!=r[x]))
			{
				w[y]=1;
				return false;
			}
			else
			{
				w[y]=1;
				return true;
			}
		}
		if(a[y]<0)r[y]=-r[x];
		else r[y]=r[x];
		k=k&&check(y);
		if(!k)
		{
			w[y]=1;
			return false;
		}
		w[y]=1;
	}
	w[x]=1;
	return k;
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&C,&T);
	while(T--)
	{
		u=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			a[i]=i;q[i]=0;r[i]=0;w[i]=0;z[i]=0;
			p[i].clear();
		}
		char ty;int x,y;
		for(int i=1;i<=m;i++)
		{
			cin>>ty;
			if(ty=='+')
			{
				scanf("%d%d",&x,&y);
				a[x]=a[y];
				z[x]=1;
				z[y]=1;
			}
			else
			if(ty=='-')
			{
				scanf("%d%d",&x,&y);
				a[x]=-a[y];
				z[x]=1;
				z[y]=1;
			}
			else
			if(ty=='U')
			{
				scanf("%d",&x);
				a[x]=0;
				z[x]=1;
			}
			else
			if(ty=='T')
			{
				scanf("%d",&x);
				a[x]=n+1;
				z[x]=1;
			}
			else
			if(ty=='F')
			{
				scanf("%d",&x);
				a[x]=-n-1;
				z[x]=1;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(!z[i])continue;
			int x=i;
			int y=abs(a[i]);
//			printf("[x=%d][y=%d]\n",x,a[i]);
			if((y==0)||(y==n+1)||(y==x))continue;
			p[y].push_back(x);
//			printf("\n[%d] -> [%d]\n\n",y,x);
		}
		for(int i=1;i<=n;i++)
		{
			if(!z[i])continue;
			if(a[i]==0||a[i]==-i)
			{
				q[i]=1;
//				printf("[%d] is Unknow for sure\n",i);
			}
			else
			if(r[i]==0)
			{
				if(w[i])continue;
				r[i]=1;
//				printf("Check[%d]: \n",i);
				abr=0;
				if(!check(i))
				{
//					printf("False!");
					q[i]=1;
				}
//				printf("\n");
			}
		}
//		for(int i=1;i<=n;i++)
//		{
//			printf("r[%d]=%d\n",i,r[i]);
//		}
		for(int i=1;i<=n;i++)
		{
			if(!z[i])continue;
			if(q[i])bl(i);
		}
		for(int i=1;i<=n;i++)
		{
			if(!z[i])continue;
			if(q[i])
			{
//				printf("[%d] MUST be Unknow !\n",i);
				u++;
			}
		}
		printf("%d\n",u);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}