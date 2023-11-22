#include<bits/stdc++.h>
#define F(i,l,r) for(int i=(l),i##end=(r);i<=i##end;++i)
#define x first
#define y second
#define pii pair<int,int>
#define mp make_pair
using namespace std;
pair<int,int> fa[100009];
int _1=100001,_0=100002,_U=100003;
int n,m;
bool vis[100009];
int oh[100009];
int nw[100009];
int asd[100009];
void Solve()
{
	scanf("%d%d",&n,&m);
	F(i,1,n) fa[i]=mp(i,0),vis[i]=0,oh[i]=-1,asd[i]=0;
	fa[_0]=mp(_0,0);fa[_1]=mp(_1,0);fa[_U]=mp(_U,0);getchar();
	F(i,1,m)
	{
		char ch;int x,y;
		cin>>ch;
		switch(ch)
		{
			case 'T': scanf("%d",&x);fa[x]=mp(_1,0);break;
			case 'F': scanf("%d",&x);fa[x]=mp(_0,0);break;
			case 'U': scanf("%d",&x);fa[x]=mp(_U,0);break;
			case '+': scanf("%d%d",&x,&y);fa[x]=fa[y];break;
			case '-': scanf("%d%d",&x,&y);fa[x]=mp(fa[y].x,fa[y].y^1);break;
		}
	}
	int ans=0;
	F(i,1,n)
	{
		if(fa[i].x>100000)
		{
			vis[i]=true;
			oh[i]=1;
			if(fa[i].x==_U) oh[i]=0,asd[i]=-1,ans++;
			continue;
		}
	}
	F(i,1,n)
	{
		if(!vis[i])
		{
			int x=i,tot=0;
			while(1)
			{
				nw[++tot]=x;
				vis[x]=true;
				if(!vis[fa[x].x]) asd[fa[x].x]=asd[x]^(fa[x].y),x=fa[x].x;
				else break;
			}
			if(((asd[fa[x].x]!=(asd[x]^fa[x].y)) && (oh[fa[x].x]==-1)) || asd[fa[x].x]==-1)
			{
				F(i,1,tot)asd[nw[i]]=-1;
				ans+=tot;
			}
			F(i,1,tot) oh[nw[i]]=0;
		}
	}
	printf("%d\n",ans);
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c,T;
	scanf("%d%d",&c,&T);
	while(T--)Solve();
}
/*
1 1
10 10
- 7 6
+ 4 1
+ 6 4
T 1
+ 2 9
- 9 10
U 10
+ 5 5
U 8
T 3




*/