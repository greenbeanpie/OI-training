#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int op,T,n,m,ans,a[N],b[N],c[N],f[N],ff[N],fir[N],vis[N];
char ch;
int read()
{
	int x=0,p=1;
	ch=getchar();
	while(ch!='-'&&(ch<'0'||ch>'9'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*p;
}
void dfs(int x)
{
	if(x>n)
	{
		int cnt=0;
		for(int i=1;i<=n;i++){ff[i]=f[i];if(f[i]==2)cnt++;}
		for(int i=1;i<=m;i++)
		{
			if(a[i]<4)ff[b[i]]=a[i];
			if(a[i]==4)ff[b[i]]=ff[c[i]];
			if(a[i]==5)ff[b[i]]=4-ff[c[i]];
		}
		bool flag=1;
		for(int i=1;i<=n;i++)
			if(f[i]!=ff[i]){flag=0;break;}
//		if(flag)cout<<cnt<<endl;
		if(flag)ans=min(ans,cnt);
		return;
	}
	for(int i=1;i<4;i++)
		f[x]=i,dfs(x+1);
}
void init1()
{
	while(T--)
	{
		cin>>n>>m;
		ch=getchar();ans=n+1;
		for(int i=1;i<=m;i++)
		{
			while(ch!='U'&&ch!='T'&&ch!='F'&&ch!='+'&&ch!='-')ch=getchar();
			if(ch=='T'){a[i]=1;cin>>b[i];}
			if(ch=='U'){a[i]=2;cin>>b[i];}
			if(ch=='F'){a[i]=3;cin>>b[i];}
			if(ch=='+'){a[i]=4;cin>>b[i]>>c[i];}
			if(ch=='-'){a[i]=5;cin>>b[i]>>c[i];}
			ch=getchar();
		}
		dfs(1);
		cout<<ans<<'\n';
	}
}
void init2()
{
	while(T--)
	{
		cin>>n>>m;
		ch=getchar();
		for(int i=1;i<=m;i++)
		{
			while(ch!='U'&&ch!='T'&&ch!='F'&&ch!='+'&&ch!='-')ch=getchar();
			if(ch=='T'){a[i]=1;b[i]=read();}
			if(ch=='U'){a[i]=2;b[i]=read();}
			if(ch=='F'){a[i]=3;b[i]=read();}
		}
		ans=0;
		for(int i=1;i<=n;i++)
			f[i]=0;
		for(int i=1;i<=m;i++)
			f[b[i]]=a[i];
		for(int i=1;i<=n;i++)
			if(f[i]==2)ans++;
		cout<<ans<<'\n';
	}
}
void init3()
{
	while(T--)
	{
		cin>>n>>m;
		ch=getchar();
		for(int i=1;i<=m;i++)
		{
			while(ch!='U'&&ch!='T'&&ch!='F'&&ch!='+'&&ch!='-')ch=getchar();
			if(ch=='U'){a[i]=1;b[i]=read();}
			if(ch=='+'){a[i]=2;b[i]=read();c[i]=read();}
		}
		ans=0;
		for(int i=1;i<=n;i++)
			f[i]=0;
		for(int i=1;i<=m;i++)
		{
			if(a[i]==1)f[b[i]]=1;
			if(a[i]==2)f[b[i]]=f[c[i]];
		}
//		for(int i=1;i<=n;i++)
//			for(int j=1;j<=m;j++)
//				if(a[j]==2)
//					f[b[j]]=f[c[j]];
		for(int i=1;i<=n;i++)
			if(f[i])ans++;
		cout<<ans<<'\n';
	}
}
int fnd(int x,int y)
{
	if(fir[x]>0)return fir[x];
	if(f[x]==0)return fir[x]=1;
	if(f[x]==x&&ff[x]==1)return fir[x]=1;
	if(f[x]==x&&ff[x]==2)return fir[x]=2;
	if(vis[x]+y==3)return fir[x]=2;
	if(vis[x]==y)return fir[x]=1;
	vis[x]=y;
	if(ff[x]==1)
		{int z=fnd(f[x],y);return z;vis[x]=0;}
	else
		{int z=4-fnd(f[x],3-y);return z;vis[x]=0;}
}
void init4()
{
	while(T--)
	{
		cin>>n>>m;
		ch=getchar();
		for(int i=1;i<=m;i++)
		{
			while(ch!='U'&&ch!='T'&&ch!='F'&&ch!='+'&&ch!='-')
				ch=getchar();
			if(ch=='+'){a[i]=1;b[i]=read();c[i]=read();}
			if(ch=='-'){a[i]=2;b[i]=read();c[i]=read();}
		}
		ans=0;
		for(int i=1;i<=n;i++)f[i]=0,ff[i]=0,fir[i]=0;
		for(int i=1;i<=m;i++)
			if(a[i]==1)
				{f[b[i]]=c[i];ff[b[i]]=a[i];}
			else
				{f[b[i]]=c[i];ff[b[i]]=a[i];}
		for(int i=1;i<=n;i++)
		{
			if(f[i]==0)
				fir[i]=1;
			else
				if(ff[i]==1)
					fir[i]=fnd(f[i],1);
				else
					fir[i]=4-fnd(f[i],1);
			if(fir[i]==2)ans++;
		}
		cout<<ans<<'\n';
	}
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>op>>T;
	if(op==1||op==2){init1();return 0;}
	if(op==3||op==4){init2();return 0;}
	if(op==5||op==6){init3();return 0;}
	if(op==7||op==8){init4();return 0;}
	return 0;
}