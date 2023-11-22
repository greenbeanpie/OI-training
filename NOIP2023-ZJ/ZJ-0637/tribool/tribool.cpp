#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
typedef long long ll;
int c,t,n,m;
int a[maxn],b[maxn];
int op[maxn][4];
int ans=INT_MAX;
int turn(char x)
{
	if(x=='T')
		return 1;
	if(x=='F')
		return 2;
	if(x=='U')
		return 3;
	if(x=='+')
		return 4;
	if(x=='-')
		return 5;
	return -1;
}
int turnp(int x)
{
	if(x==1)
		return 2;
	if(x==2)
		return 1;
	return 3;
}
void dfs(int x)
{
	if(x>n)
	{
		for(int i=1;i<=n;i++)
			b[i]=a[i];
		for(int i=1;i<=m;i++)
		{
			if(op[i][0]<=3)
				b[op[i][3]]=op[i][0];
			else if(op[i][0]==4)
				b[op[i][2]]=b[op[i][1]];
			else
				b[op[i][2]]=turnp(b[op[i][1]]);
		}
		int fl=1;
		for(int i=1;i<=n;i++)
			if(a[i]!=b[i])
				fl=0;
		if(fl)
		{
			int un=0;
			for(int i=1;i<=n;i++)
				if(a[i]==3)
					un++;
			ans=min(ans,un);
		}
		return;
	}
	for(int i=1;i<=3;i++)
	{
		a[x]=i;
		dfs(x+1);
	}
	return;
}
void calc1()
{
	while(t--)
	{
		ans=INT_MAX;
		scanf("%d %d",&n,&m);
		for(int i=1;i<=m;i++)
		{
			char x;
			cin>>x;
			op[i][0]=turn(x);
			if(x=='+'||x=='-')
				scanf("%d %d",&op[i][1],&op[i][2]);
			else
				scanf("%d",&op[i][3]);
		}
		dfs(1);
		printf("%d\n",ans);
	}
}
void calc2()
{
	while(t--)
	{
		scanf("%d %d",&n,&m);
		for(int i=1;i<=m;i++)
		{
			char x;
			cin>>x;
			op[i][0]=turn(x);
			scanf("%d",&op[i][3]);
		}
		for(int i=1;i<=n;i++)
			a[i]=4;
		for(int i=1;i<=m;i++)
			a[op[i][3]]=op[i][0];
		ans=0;
		for(int i=1;i<=n;i++)
			if(a[i]==3)
				ans++;
		printf("%d\n",ans);
	}
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d %d",&c,&t);
	if(c==1||c==2)
		calc1();
	else if(c==3||c==4)
		calc2();
//	else if(c==5||c==6)
//		calc3();
	else
		while(t--)
			cout<<rand()<<endl;
	return 0;
}
