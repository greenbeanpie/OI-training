#include<bits/stdc++.h>
using namespace std;
	int c,t,n,m,mini=100005;
	int a[1005],tmp[1005],op[1005][3],f[4]={-1,2,1,3};
bool judge()
{
	for(int i=1;i<=n;i++)
		tmp[i]=a[i];
	for(int i=1;i<=m;i++)
	{
		if(op[i][0]==1) tmp[op[i][1]]=1;
		else if(op[i][0]==2) tmp[op[i][1]]=2;
		else if(op[i][0]==3) tmp[op[i][1]]=3;
		else if(op[i][0]==4) tmp[op[i][1]]=tmp[op[i][2]];
		else if(op[i][0]==5) tmp[op[i][1]]=f[tmp[op[i][2]]];
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=tmp[i]) return false;
	}
	return true;
}
void count()
{
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==3) cnt++;
	}
	if(cnt<=mini) mini=cnt;
}
void dfs(int k)
{
	if(k==n)
	{
		if(judge())
		{
			count();
		}
		return;
	}
	else
	{
		for(int i=1;i<=3;i++)
		{
			a[k+1]=i;
			dfs(k+1);
			a[k+1]=0;
		}
	}
}
void init()
{
	memset(op,0,sizeof(op));
	memset(a,0,sizeof(a));
	cin>>n>>m;
	mini=100005;
	for(int i=1;i<=m;i++)
	{
		char x;
		cin>>x;
		if(x=='T'){
			op[i][0]=1;
			int d;
			cin>>d;
			op[i][1]=d;
		}
		else if(x=='F'){
			op[i][0]=2;
			int d;
			cin>>d;
			op[i][1]=d;
		}
		else if(x=='U'){
			op[i][0]=3;
			int d;
			cin>>d;
			op[i][1]=d;
		}
		else if(x=='+'){
			op[i][0]=4;
			int d,e;
			cin>>d>>e;
			op[i][1]=d;op[i][2]=e;
		}
		else if(x=='-'){
			op[i][0]=5;
			int d,e;
			cin>>d>>e;
			op[i][1]=d;op[i][2]=e;
		}
	}
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		init();
		dfs(0);
		cout<<mini<<endl;
	}
	return 0;
}
