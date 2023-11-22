#include <queue>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
vector <int> g[100001];
bool visu[100001];
bool visb[100001];
int x[100001];
queue <int> q;

void lll34()
{
	memset(x,0,sizeof(x));
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i = 1;i <= m;i++)
	{
		string s;
		cin >> s;
		int a;
		scanf("%d",&a);
		if(s == "T")
		{
			x[a] = 1;
		}
		else if(s == "F")
		{
			x[a] = 2;
		}
		else
		{
			x[a] = 3;
		}
	}
	int cnt = 0;
	for(int i = 1;i <= n;i++)
	{
		if(x[i] == 3)
		{
			cnt++;
		}
	}
	printf("%d\n",cnt);
}

void lll56()
{
	memset(x,0,sizeof(x));
	memset(visu,false,sizeof(visu));
	memset(visb,false,sizeof(visb));
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i = 1;i <= n;i++)
	{
		g[i].clear();
	}
	for(int i = 1;i <= m;i++)
	{
		string s;
		cin >> s;
		if(s == "U")
		{
			int a;
			scanf("%d",&a);
			x[a] = 1;
			visu[a] = true;
		}
		else
		{
			int a,b;
			scanf("%d %d",&a,&b);
			if(a == b)
			{
				continue;
			}
			x[a] = x[b];
			if(visu[b] == false)
			{
				g[b].push_back(a);
			}
			visu[a] = true;
		}
	}
	for(int i = 1;i <= n;i++)
	{
		if(x[i] == 1)
		{
			q.push(i);
			visb[i] = true;
		}
	}
	while(!q.empty())
	{
		int id = q.front();
		q.pop();
		for(int i = 0;i < g[id].size();i++)
		{
			int u = g[id][i];
			if(visb[u] == false)
			{
				x[u] = 1;
				visb[u] = true;
				q.push(u);
			}
		}
	}
	int cnt = 0;
	for(int i = 1;i <= n;i++)
	{
		if(x[i] == 1)
		{
			cnt++;
		}
	}
	printf("%d\n",cnt);
}

int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c,t;
	scanf("%d %d",&c,&t);
	if(c == 3||c == 4)
	{
		while(t--)
		{
			lll34();
		}
	}
	else if(c == 5||c == 6)
	{
		while(t--)
		{
			lll56();
		}
	}
	return 0;
}

//已知问题:第 94~108 行的更新中可能覆盖更之后的更新
//例:5 1
//   3 3
//   + 2 1
//   + 2 3
//   U 1
//正确答案:1,会错错误为 2 

//已知问题:第 79~83 行的少记录边中可能会被第 94~108 行用到 
//例:5 1
//   4 4
//   + 2 4
//   + 2 1
//   + 3 2
//   U 1
//正确答案:3,会错错误为 2 
