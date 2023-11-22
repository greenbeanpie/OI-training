#include<bits/stdc++.h>
using namespace std;
struct sent
{
	char c;
	int ai,aj;
}s[100010];
int test,num,t;
int n,m,unum=100010,head[100010],cntt,lf[100010];
bool walk[100010];
char v[100010],vt[100010],vf[100010];
struct Edge
{
	int to,next;
}E[200020];
void AddEdge(int x,int y)
{
	E[++cntt].to=y;
	E[cntt].next=head[x];
	head[x]=cntt;
}
char fan(char cf)
{
	if(cf=='T') return 'F';
	if(cf=='F') return 'T';
	if(cf=='U') return 'U';
}
void dfs(int now,int end)
{
	if(now==end+1)
	{
		for(int i=1;i<=num;i++)
		{

			if(s[i].c=='T'||s[i].c=='F'||s[i].c=='U')
			{
				vf[s[i].ai]=s[i].c;
			}
			if(s[i].c=='+') vf[s[i].ai]=vf[s[i].aj];
			if(s[i].c=='-') vf[s[i].ai]=fan(vf[s[i].aj]);
		}
		int an=0,flag=1;
		for(int i=1;i<=end;i++)
		{
			if(vt[i]!=vf[i]) flag=0;
			if(vt[i]=='U') an++;
			vf[i]=vt[i];
		}
		if(flag==0) return;
		unum=min(unum,an);
		return;
	}
	vf[now]=vt[now]='T';
	dfs(now+1,end);
	vf[now]=vt[now]='F';
	dfs(now+1,end);
	vf[now]=vt[now]='U';
	dfs(now+1,end);
}
void dfsc(int no)
{
	walk[no]=1;
	v[no]='U';
	for(int i=head[no];i;i=E[i].next)
	{
		int ne=E[i].to;
		if(walk[ne]==0&&ne!=0) dfsc(ne);
	}
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>test>>t;
	if(test==3||test==4)
	{
		int cnt=0;
		while(t--)
		{
			cin>>n>>m;
			for(int i=1;i<=n;i++) v[i]=' ';
			for(int i=1;i<=m;i++)
			{
				char cl;
				int a1;
				cin>>cl>>a1;
				v[a1]=cl;
			}
			for(int i=1;i<=n;i++) if(v[i]=='U') cnt++;
			cout<<cnt<<endl;
		}
		return 0;
	}
	if(test==1||test==2)
	{
		while(t--)
		{
			cin>>n>>m;
			num=0;
			unum=100010;
			for(int i=1;i<=n;i++) v[i]=' ';
			for(int i=1;i<=n;i++) vf[i]=vt[i]=' ';
			for(int i=1;i<=m;i++) s[i].c=' ';
			for(int i=1;i<=m;i++)
			{
				char cl;
				int a1,a2;
				cin>>cl;
				if(cl=='U'||cl=='F'||cl=='T')
				{
					cin>>a1;
					s[++num].ai=a1;
					s[num].c=cl;
					continue;
				}
				else
				{
					cin>>s[++num].ai>>s[num].aj;
					s[num].c=cl;
				}
			}
			dfs(1,n);
			cout<<unum<<endl;
		}
		return 0;
	}
	if(test==5||test==6)
	{
		int aa[10],h=0;
		while(t--)
		{
			cin>>n>>m;
			num=0;
			unum=100010;
			cntt=0;
			for(int i=1;i<=n;i++) v[i]=' ';
			for(int i=1;i<=n;i++) head[i]=0;
			for(int i=1;i<=n;i++) walk[i]=0;
			for(int i=1;i<=2*n;i++) E[i].next=E[i].to=0;
			for(int i=1;i<=m;i++)
			{
				char cl;
				int a1,a2;
				cin>>cl;
				if(cl=='U')
				{
					cin>>a1;
					v[a1]=cl;
					lf[a1]=0;
					continue;
				}
				else
				{
					cin>>a1>>a2;
					lf[a1]=a2;
					if(a1!=a2) v[a1]=' ';
				}
			}
			int cnt=0;
			for(int i=1;i<=n;i++) AddEdge(lf[i],i);
			for(int i=1;i<=n;i++)
			{
				if(walk[i]==0&&v[i]=='U') dfsc(i);
			}
			for(int i=1;i<=n;i++)
			{
				if(v[i]=='U') cnt++;
			}
			cout<<cnt<<endl;
		}
		return 0;
	}
	else
	{
		cout<<"0"<<endl;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
