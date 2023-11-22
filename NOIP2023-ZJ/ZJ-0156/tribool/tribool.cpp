#include<bits/stdc++.h>
#define N 100005
/*
	n+1->T
	0->U
	-(n+1)->F
	i is included in [1,n] ->xi
	+ the same - the diffrent
*/
int read()
{
	char ch=getchar();
	int x=0;
	while(ch<'0'||ch>'9')
		ch=getchar();
	while(ch>='0'&ch<='9')
		x=(x<<3)+(x<<1)+(ch&15),ch=getchar();
	return x;
}
int c,T,n,m,ans;
int ed[N],cho[N];
int len[N];
bool vis[N];
std::deque<int> q;
void get(int x)
{
	if(~cho[x])
		return;
	int now=x,L=0;
	while(!vis[now])
	{
		q.push_back(now);
		vis[now]=1;
		if(!ed[now]||ed[now]==-now)
			cho[now]=1;
		if(ed[now]>n||ed[now]==now)
			cho[now]=0;
		if(~cho[now])
			break;
		len[now]=L;
		L^=ed[now]<0;
		now=std::abs(ed[now]);
	}
	if(!~cho[now])
		cho[now]=L^len[now];
	while(!q.empty())
	{
		int tmp=q.front();
		q.pop_front();
		cho[tmp]=cho[now];
	}
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	c=read();
	T=read();
	while(T--)
	{
		n=read(),m=read();
		ans=0;
		for(int i=1;i<=n;++i)
			ed[i]=i,cho[i]=-1,vis[i]=0;
		char op;
		int x,y;
		for(int i=1;i<=m;++i)
		{
			do
				op=getchar();
			while(op!='T'&&op!='F'&&op!='U'&&op!='+'&&op!='-');
			if(op=='+'||op=='-')
			{
				x=read(),y=read();
				if(op=='+')
					ed[x]=ed[y];
				else
					ed[x]=-ed[y];
			}
			else
			{
				x=read();
				if(op=='T'||op=='F')
					ed[x]=n+1;
				if(op=='U')
					ed[x]=0;
			}
		}
		for(int i=1;i<=n;++i)
		{
			if(~cho[i])
				continue;
			get(i);
		}
		for(int i=1;i<=n;++i)
			ans+=cho[i];
		printf("%d\n",ans);
	}
	return 0;
}
