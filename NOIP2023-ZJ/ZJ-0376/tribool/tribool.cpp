#include<bits/stdc++.h>
using namespace std;
const int N=10020;
int f[N];
int step[N][3];
int t,n,m,p,ans;
bool check()
{
	int ne[20];
	for(int i=1;i<=n;i++) ne[i]=f[i];
	for(int i=1;i<=m;i++){
		if(step[i][0]==0)
		{
			ne[step[i][1]]=step[i][2];
		}
		else if(step[i][0]==1)
		{
			ne[step[i][1]]=ne[step[i][2]];
		}
		else{
			if(ne[step[i][2]]==2)
			{
				ne[step[i][1]]=2;
			}
			else{
				ne[step[i][1]]=ne[step[i][2]]^1;
			}
		}
	}/*
	for(int i=1;i<=n;i++)
	{
		cout<<f[i]<<" ";
	}
	cout<<endl;
	for(int j=1;j<=n;j++)
	{
		cout<<ne[j]<<" ";
	}
	cout<<endl;*/
	for(int i=1;i<=n;i++)
	{
		if(ne[i]!=f[i]) return 0;
	}
	return 1;
 } 
void dfs(int now)
{
	if(now>n){
		if(check()){
			int num=0;
			for(int o=1;o<=n;o++)
			{
				if(f[o]==2) num++;
			}
			ans=min(ans,num);
		}
		return;
    }
	for(int k=0;k<3;k++)
	{
		f[now]=k;
		dfs(now+1);
	}
}
void solve1()
{
	memset(f,0,sizeof(f));
	dfs(1);
    printf("%d\n",ans);
}
void solve2()
{
	memset(f,0,sizeof(f));
	for(int i=1;i<=m;i++){
		if(step[i][0]==0)
		{
			f[step[i][1]]=step[i][2];
		}
	}
	int num=0;
	for(int i=1;i<=n;i++)
	{
		if(f[i]==2) num++;
	}
	printf("%d\n",num);
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&p,&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d%d",&n,&m);
		ans=1e9;
		for(int j=1;j<=m;j++)
		{
			char in;
			int a,b;
			cin>>in;
			if(in=='F')
			{
				scanf("%d",&a);
				step[j][0]=0;
				step[j][1]=a;
				step[j][2]=0;
			}
			else if(in=='T')
			{
				scanf("%d",&a);
				step[j][0]=0;
				step[j][1]=a;
				step[j][2]=1;
			}
			else if(in=='U')
			{
				scanf("%d",&a);
				step[j][0]=0;
				step[j][1]=a;
				step[j][2]=2;
			}
			else{
				scanf("%d%d",&a,&b);
				if(in=='+')
				{
					step[j][0]=1;step[j][1]=a;step[j][2]=b;
				}
			    else{
					step[j][0]=2;step[j][1]=a;step[j][2]=b;
				}
			}
		}
		if(n<=10) solve1();
		else if(p==4||p==3)
		{
			solve2();
		}
		//printf("%d\n",ans);
	}
	return 0;
}
