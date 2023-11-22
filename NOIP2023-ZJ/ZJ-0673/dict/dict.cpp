#include<bits/stdc++.h>
using namespace std;

int n,m;
int smin[3010][3010],smax[3010][3010];
int cnt,fa[9000010];
bool flag[3010];
vector< pair<int,int> > son[9000010];
//int minson[9000010];

void buildtree(int u,int dep,int x)
{
	if(dep>m)
		return;
	//minson[u]=2147000000;
	pair<int,int> p;
	int ck=-1;
	for(vector< pair<int,int> >::iterator it=son[u].begin();it!=son[u].end();it++)
	{
		p=*it;
		if(p.second==smax[x][dep])
		{
			ck=p.first;
			break;
		}
	}
	if(ck==-1)
	{
		p.first=++cnt;
		p.second=smax[x][dep];
		son[u].push_back(p);
		//minson[u]=min(p.second,minson[u]);
		buildtree(cnt,dep+1,x);
	}
	else
		buildtree(ck,dep+1,x);
}

/*void compare(int x)
{
	priority_queue< pair<int,pair<int,int> > > q;
	pair<int,int> p;
	pair<int,pair<int,int> > node,tmp;
	node.first=-minson[0];
	node.second.first=0;
	node.second.second=1;
	q.push(node);
	while(!q.empty())
	{
		node=q.top();
		q.pop();
		if(-node.first<smin[x][node.second.second])
		{
			flag[x]=false;
			return;
		}
		for(vector< pair<int,int> >::iterator it=son[node.second.first].begin();it!=son[node.second.first].end();it++)
		{                                                                                           
			p=*it;
			if(p.second<smin[x][node.second.second])
			{
				flag[x]=false;
				return;
			}
			if(p.second==smin[x][node.second.second] && node.second.second<m)
			{
				tmp.first=-minson[p.first];
				tmp.second.first=p.first;
				tmp.second.second=node.second.second+1;
				q.push(tmp);
			}
		}
	}
}*/

void compare(int u,int dep,int x)
{
	if(dep>m)
		return;
	pair<int,int> p;
	for(vector< pair<int,int> >::iterator it=son[u].begin();it!=son[u].end();it++)
	{                                                                                           
		p=*it;
		if(p.second<smin[x][dep])
		{
			flag[x]=false;
			return;
		}
		if(p.second==smin[x][dep])
			compare(p.first,dep+1,x);
	}
}

int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	string str;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		flag[i]=true;
		cin>>str;
		for(int j=0;j<m;j++)
			smin[i][j+1]=(int)(str[j]-'a');
		sort(smin[i]+1,smin[i]+m+1);
		for(int j=1;j<=m;j++)
			smax[i][j]=smin[i][m-j+1];
	}
	for(int i=1;i<=n;i++)
		buildtree(0,1,i);
	for(int i=1;i<=n;i++)
	{
		//compare(i);
		compare(0,1,i);
		if(flag[i])
			printf("1");
		else
			printf("0");
	}
	printf("\n");
	return 0;
}