#include <bits/stdc++.h>
using namespace std;
char v[100005];
struct N
{
	int i;
	char op;
};
vector<N> mp[100005];

char trva(char m,char ov)
{
	char res=0;
	if(m=='+')
		res=ov;
	else
	{
		if(ov=='T')
			res='F';
		else if(ov=='F')
			res='T';
		else if(ov=='U')
			res='U';
		else
			res=0;
	}
//	printf("trva:%c %c %c\n",m,ov,res);
	return res;
}
bool vis[100005];
void fill1(int c,char _v)
{
	vis[c]=true;
	v[c]=_v;
	for(int i=0;i<mp[c].size();i++)
	{
		if(!vis[mp[c][i].i])
			fill1(mp[c][i].i,trva(mp[c][i].op,_v));
	}
	mp[c].clear();
	vis[c]=false;
}
void fill2(int c,char _v)
{
//	printf("fill2:%d %c\n",c,_v);
	vis[c]=true;
	v[c]=_v;
	for(int i=0;i<mp[c].size();i++)
	{
		if(!vis[mp[c][i].i])
			fill2(mp[c][i].i,trva(mp[c][i].op,_v));
	}
	vis[c]=false;
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	for(int I=0;I<t;I++)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;i++)
		{
			char c;
			scanf(" %c",&c);
//			printf("%d:%c\n",__LINE__,c);
			if(c=='U'||c=='T'||c=='F')
			{
				int u;
				scanf("%d",&u);
				if(v[u]==0)
				{
					fill1(u,c);
				}
				v[u]=c;
			}
			else
			{
				int a,b;
				scanf("%d%d",&a,&b);
				if(v[b]==0)
				{
					mp[b].push_back({a,c});
					v[a]=0;
				}
				else
				{
					v[a]=trva(c,v[b]);
				}
			}
		}
		for(int u=1;u<=n;u++)
		{
			if(v[u]==0)
			{
				const char st='T';
				v[u]=st;
				int c=u;
				for(int i=0;i<mp[c].size();i++)
				{
					fill2(mp[c][i].i,trva(mp[c][i].op,st));
				}
				if(v[u]!=st)
					fill1(u,'U');
			}
		}
		int res=0;
		for(int u=1;u<=n;u++)
		{
			if(v[u]=='U')
				res++;
		}
		for(int u=1;u<=n;u++)
		{
			mp[u].clear();
			v[u]=0;
		}
		printf("%d\n",res);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
