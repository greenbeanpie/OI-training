#include<bits/stdc++.h>
#define ll long long
#define N 100005
#define M 20
using namespace std;
int n,m,a[N];
int ori[N];
int b[N];
int op,T;
int sum;
int fa[N];
int cz[M][M];
//T:1 F:2 U:3 +:4 1:5
int find(int xx)
{
	if (fa[xx]==xx) return xx;
	else return fa[xx]=find(fa[xx]);
}
bool check()
{
	for (int i=1;i<=n;i++)
		b[i]=ori[i];
	for (int i=1;i<=m;i++)
	{
		int xx=cz[i][1];
		int opp=cz[i][0];
		if (opp<=3&&opp>=1)
		{
			b[xx]=opp;
		}
		else
		{
			int yy=cz[i][2];
			if (opp==4) b[xx]=b[yy];
			else
			{
				if (b[yy]==3) b[xx]=b[yy];
				else b[xx]=3-b[yy];
			}
		}
	}
	for (int i=1;i<=n;i++)
		if (b[i]!=ori[i]) return false;
	return true;
}
void dfs(int gs)
{
	if (gs==n)
	{
		if (check()){
			int nowwww=0;
			for (int i=1;i<=n;i++)
				if (ori[i]==3) nowwww+=1;
			sum=min(sum,nowwww);
		}
		return ;
	}
	for (int i=1;i<=3;i++)
	{
		ori[gs+1]=i;
		dfs(gs+1);
		ori[gs+1]=0;
	}
	return ;
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&op,&T);
	sum=0;
	//cout<<op<<T;
	if (op==1||op==2)
	{
		while (T>0)
		{
			sum=104623;
			scanf("%d%d",&n,&m);
			for (int i=1;i<=n;i++)
				a[i]=0;
			for (int i=1;i<=m;i++)
			{
				char ch;
				cin>>ch;
				//cout<<ch;
				int x,y;
				scanf("%d",&x);
				if (ch=='T') cz[i][0]=1;
				if (ch=='F') cz[i][0]=2;
				if (ch=='U') cz[i][0]=3;
				cz[i][1]=x;
				if (ch=='+')
				{
					scanf("%d",&y);
					cz[i][0]=4;
					cz[i][2]=y;
				}
				if (ch=='-')
				{
					scanf("%d",&y);
					cz[i][0]=5;
					cz[i][2]=y;
				}
			}
			dfs(0);
			cout<<sum<<endl;
			T--;
		}
		return 0;
	}
	if (op==3||op==4)
	{
		//cout<<T;
		while (T>0)
		{
			scanf("%d%d",&n,&m);
			for (int i=1;i<=n;i++)
				a[i]=0;
			for (int i=1;i<=m;i++)
			{
				char ch;
				cin>>ch;
				//cout<<ch;
				int x;
				scanf("%d",&x);
				if (ch=='T') a[x]=1;
				if (ch=='F') a[x]=2;
				if (ch=='U') a[x]=3;
			}
			sum=0;
			for (int i=1;i<=n;i++)
			if (a[i]==3) sum+=1;
			cout<<sum<<endl;
			T--;
		}
		return 0;
	}
	if (op==5||op==6)
	{
		while (T>0)
		{
			scanf("%d%d",&n,&m);
			for (int i=1;i<=n;i++)
				a[i]=0,fa[i]=i;
			for (int i=1;i<=m;i++)
			{
				char ch;
				cin>>ch;
				//cout<<ch;
				int x,y;
				scanf("%d",&x);
				if (ch=='U') a[x]=3;
				if (ch=='+'){//a[x]=a[y];
					scanf("%d",&y);
					int fx=find(x);
					int fy=find(y);
					fa[fx]=fa[fy];
					a[fx]=0;
				}
			}
//			for (int i=1;i<=n;i++)
//				cout<<fa[i]<<" ";
//			cout<<endl;
			sum=0;
			for (int i=1;i<=n;i++)
			if (a[i]==3) sum+=1;
			else if (find(i)==3) sum+=1;
			cout<<sum<<endl;
			T--;
		}
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//long long!! empty!!
