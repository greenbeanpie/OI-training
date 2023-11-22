#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

#define N 100010
#define INF 0x7fffffff
#define ISDEF(v) (v=='T'||v=='F'||v=='U')
#define PRINT for(int i=0;i<stmt.size();i++)cout<<stmt[i].v<<" "<<stmt[i].i<<" "<<stmt[i].j<<" "<<stmt[i].used<<endl;

typedef struct{
	char v;
	int i,j;
	bool used;
}Stmt;

int n,m,ans,appear[N];
char x[N],nx[N],fix[N];
vector<Stmt> stmt;
bool first[N];

inline char _not(char v)
{
	switch(v)
	{
		case 'T':return 'F';
		case 'F':return 'T';
		case 'U':return 'U';
	}
	return '\0';
}

void dfs(int xi)
{
	if(xi==n+1)
	{
		for(int i=1;i<=n;i++)nx[i]=x[i];
		for(int i=0;i<stmt.size();i++)
		{
			Stmt s=stmt[i];
			switch(s.v)
			{
				case 'T':
				case 'F':
				case 'U':
				{
					nx[s.i]=s.v;
					break;
				}
				case '+':
				{
					nx[s.i]=nx[s.j];
					break;
				}
				case '-':
				{
					nx[s.i]=_not(nx[s.j]);
					break;
				}
			}
		}
		int unkown=0;
		for(int i=1;i<=n;i++)
		{
			if(x[i]!=nx[i])return;
			if(x[i]=='U')unkown++;
		}
		ans=min(ans,unkown);
		return;
	}
	if(appear[xi]==1)
	{
		x[xi]=fix[xi];
		dfs(xi+1);
		return;
	}
	x[xi]='T';
	dfs(xi+1);
	x[xi]='F';
	dfs(xi+1);
	x[xi]='U';
	dfs(xi+1);
}

void _main()
{
	ans=INF;
	stmt.clear();
	memset(first,1,sizeof(first));
	memset(appear,0,sizeof(appear));
	
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		Stmt s;
		s.used=false;
		cin>>s.v>>s.i;
		if(!ISDEF(s.v))cin>>s.j;
		stmt.push_back(s);
	}
	for(int i=0;i<stmt.size()-1;i++)
	{
		if(!ISDEF(stmt[i].v))
		{
			if(!ISDEF(stmt[i+1].v))
			{
				if(stmt[i].i==stmt[i+1].j)
				{
					stmt[i+1].j=stmt[i].j;
					if(stmt[i].v==stmt[i+1].v)stmt[i+1].v='+';
					else stmt[i+1].v='-';
				}
			}
		}
		else
		{
			if(!ISDEF(stmt[i+1].v))
			{
				if(stmt[i].i==stmt[i+1].j)
				{
					if(stmt[i+1].v=='+')stmt[i+1].v=stmt[i].v;
					else stmt[i+1].v=_not(stmt[i].v);
				}
			}
		}
	}
	for(int i=stmt.size()-1;i>=0;i--)
	{
		Stmt s=stmt[i];
		if(first[s.i])
		{
			first[s.i]=false;
			stmt[i].used=true;
		}
		if(!ISDEF(s.v))
		{
			for(int j=i-1;j>=0;j--)
			{
				if(stmt[j].i==s.j)
				{
					stmt[j].used=true;
					break;
				}
			}
		}
	}
	for(int i=0;i<stmt.size();i++)if(!stmt[i].used)stmt.erase(stmt.begin()+i),i--;
	for(int i=0;i<stmt.size();i++)
	{
		Stmt s=stmt[i];
		if(ISDEF(s.v))
		{
			fix[s.i]=s.v;
			appear[s.i]++;
		}
	}
	dfs(1);
	cout<<ans<<endl;
}

int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)_main();
	return 0;
}