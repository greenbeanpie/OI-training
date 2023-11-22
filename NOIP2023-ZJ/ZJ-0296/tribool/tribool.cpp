#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int x,y,c,t,n,m,f[100001][3];//
char ch;
vector<int> aa;
int ans,anss,v[100001],vv[100001];
int nex[100001],pre[100001];
int head[100001],nx[100001],node[100001],cnt;
int check()
{
	for (int i=1;i<=n;i++)
	{
//		cout<<"i="<<i<<" nex="<<nex[i]<<" "<<f[i][0]*f[i][2]<<" "<<f[nex[i]][0]<<endl;
		if (f[i][0]*f[i][2]!=f[nex[i]][0]&&nex[i]!=0) return 0;
	}
	return 1;
}
void dfs1(int x)
{
//	for (int i=1;i<=n;i++) f[i][0]=0;
//	f[3][0]=0;
//	if (check()) cout<<"AAAAAAAAAA"<<endl;
//	cout<<"x="<<x<<endl;
	if (x==n+1)
	{
	if (check()==1) 
		{
			anss=min(ans,anss);
//			int kkk;cin>>kkk;
//			for (int i=1;i<=n;i++) cout<<f[i][0]<<" AA ";
//			cout<<endl;
		}
		return;
	}
	if (f[x][0]==2)
	{
		for (int i=-1;i<=1;i++)
		{
			f[x][0]=i;
			if (i==0) ans++;
			dfs1(x+1);
			if (i==0) ans--;
			f[x][0]=2;
		}
	}
	else 
	{
		if (f[x][0]==0) ans++;
		dfs1(x+1);
		if (f[x][0]==0) ans--;
	}
}
void go(int x)
{
	v[x]=1;ans++;
	int q1=head[x];
	while(q1!=-1)
	{
		if (v[node[q1]]==0)
		{
			go(node[q1]);
		}
		q1=nx[q1];
	}
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m;ans=0;anss=n;cnt=0;
		for (int i=1;i<=n;i++) nex[i]=0,pre[x]=0,vv[i]=0,v[i]=0,f[i][1]=i,f[i][2]=1,f[i][0]=2,head[i]=-1,nx[i]=-1;
		
		for (int i=1;i<=m;i++)
		{
			ch=getchar();
			while(ch!='+'&&ch!='-'&&ch!='T'&&ch!='F'&&ch!='U') ch=getchar();
			if (ch=='+')
			{
				scanf("%d%d",&x,&y);
				if (f[y][0]==2)
				{
					f[x][1]=f[y][1];
					f[x][2]=f[y][2];	
					f[x][0]=2;
				}
				else f[x][0]=f[y][0];
			}
			else if (ch=='-')
			{
				scanf("%d%d",&x,&y);
				if (f[y][0]==2)
				{
					f[x][1]=f[y][1];
					f[x][2]=-f[y][2];	
					f[x][0]=2;
				}
				else f[x][0]=-f[y][0];
			}
			else
			{
				scanf("%d",&x);
				if (ch=='T') f[x][0]=1;
				if (ch=='F') f[x][0]=-1;
				if (ch=='U') f[x][0]=0;
			}
		}
//		for (int i=1;i<=n;i++) 
//		{
//			if (f[i][0]==2) cout<<f[i][1]*f[i][2]<<endl;
//			else cout<<f[i][0]<<endl;
//		}	
		for (int i=1;i<=n;i++)
		{
			if (f[i][0]==2) 
			{
				nex[i]=f[i][1];
//				pre[f[i][1]]=i;
			}
		}
		if (c==1||c==2)
		{
			dfs1(1);
			cout<<anss<<endl;
		}
		else if (c==5||c==6)
		{
			for (int i=1;i<=n;i++)
			{
				if (f[i][0]==2) 
				{
					cnt++;
					nx[cnt]=head[i];
					node[cnt]=f[i][1];
					head[i]=cnt;
					cnt++;
					nx[cnt]=head[f[i][1]];
					node[cnt]=i;
					head[f[i][1]]=cnt;	
//					a[i].push_back(f[i][1]);
//					a[f[i][1]].push_back(i);
//					
				}
			}
			for (int i=1;i<=n;i++)
			{
				if (f[i][0]==0)
				{
					go(i);
				}
			}
			cout<<ans<<endl;
			
		} 
		else if (c==3||c==4)
		{
			for (int i=1;i<=n;i++)
			{
				if (f[i][0]==0) ans++;
			}
			cout<<ans<<endl;
		}
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
