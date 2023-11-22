#include<bits/stdc++.h>
using namespace std;
char o[100005],ch;
int p[100005][5],n,m,c,t,we,w[100005],u[100005],tt[100005],a[100005],px[100005],h[100005],KK[100005],ans=0,x,y,minn=100000005,pp,p1[100005],p2[100005];
void dfs(int x,int y)
{
	if(x>=n)
	{
		ans=0;
		for(int i=1;i<=n;i++)w[i]=a[i];
		for(int i=1;i<=m;i++)
		{
			if(o[i]=='+')
			{
				w[p[i][1]]=w[p[i][2]];
			}
			else
			{
				if(o[i]=='-') 
				{
					if(w[p[i][2]]!=2)w[p[i][1]]=abs(w[p[i][2]]-1);
						else w[p[i][1]]=2;
				}
				else
				{
					if(o[i]=='U')w[p[i][1]]=2;
					if(o[i]=='T')w[p[i][1]]=1;
					if(o[i]=='F')w[p[i][1]]=0;
				}
			}
		}
		for(int i=1;i<=n;i++)
			if(a[i]!=w[i])return;
		for(int i=1;i<=n;i++)
			if(a[i]==2)ans++;
		if(ans<minn)minn=ans;
		return;
	}
	for(int i=0;i<3;i++)
	{
		a[x+1]=i;
		dfs(x+1,i);
	}
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>t;
	for(int zth=1;zth<=t;zth++)
	{
		cin>>n>>m;
		if(c==1 || c==2)
		{
			for(int i=1;i<=n;i++)a[i]=0;
			ans=0;
			for(int i=1;i<=m;i++)
			{
				cin>>ch;
				o[i]=ch;
				if(ch=='+') cin>>p[i][1]>>p[i][2];
					else if(ch=='-') cin>>p[i][1]>>p[i][2];
							else cin>>p[i][1];
			}
			minn=100000005;
			for(int i=0;i<3;i++)
			{
				a[1]=i;
				dfs(1,i);
			}
			cout<<minn<<endl;
		}
		if(c==3 || c==4)
		{
			for(int i=1;i<=n;i++)a[i]=0;
			ans=0;
			for(int i=1;i<=m;i++)
			{
				cin>>ch>>x;
				if(ch=='U')a[x]++;
			}
			for(int i=1;i<=n;i++)
				if(a[x]>0)ans++;
			cout<<ans<<endl;
		}
		if(c==5 || c==6)
		{
			for(int i=1;i<=m;i++)
			{
				cin>>ch;
				o[i]=ch;
				if(ch=='+') cin>>p[i][1]>>p[i][2];
					else if(ch=='-') cin>>p[i][1]>>p[i][2];
							else cin>>p[i][1];
			}
			for(int i=1;i<=n;i++)w[i]=0;
			ans=0;
			for(int j=1;j<=100;j++)
			{
				for(int i=1;i<=m;i++)
				{
					if(o[i]=='+') w[p[i][1]]=w[p[i][2]];
					else if(o[i]=='U')w[p[i][1]]=2;
				}
			}
			for(int i=1;i<=n;i++)
				if(w[i]==2)ans++;
			cout<<ans<<endl;
		}
		if(c==7 || c==8)
		{
			for(int i=1;i<+n;i++)
			{
				a[i]=1;
				u[i]=0;
				tt[i]=0;
			}
			for(int i=1;i<=m;i++)
			{
				cin>>ch;
				if(ch=='+')
				{
					cin>>x>>y;
					u[x]=y;
					a[x]=a[y];
				}
				else
				{
					cin>>x>>y;
					u[x]=y;
					a[x]=-a[y];
				}
			}
			for(int i=1;i<=n;i++)
			{
				if(u[i]!=0&&tt[i]!=1)
				{
					ans=i;
					tt[i]=1;
					if(a[i]==-1)
					{
						while(u[ans]!=0)
						{
							ans=u[ans];
							a[ans]=-1;
							tt[ans]=1;
						}
					}
					else 
					{
						int sum=0;
						while(u[ans]!=0)
						{
							ans=u[ans];
							if(a[ans]==-1)
							{
								sum=-1;
								break;
							}
						}
						if(sum!=0)
						{
							ans=i;
							while(u[ans]!=0&&tt[ans]!=1)
							{
								ans=u[ans];
								a[ans]=-1;
								tt[ans]=1;
							}
						}
					}
				}
			}
			for(int i=1;i<=n;i++)if(a[i]==-1)ans++;
			cout<<ans<<endl;
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}


/*
cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			a[i]=-1;
			v[i]=0;b[i]=0;
		}
		for(int i=1;i<=m;i++)
		{
			cin>>ch;
			if(ch=='-')
			{
				cin>>x>>y;
				b[x]=-1;
				v[x]=y;
				if(a[y]!=-1)a[x]=abs(a[y]-1);
			}
			else
			{
				if(ch=='+')
				{
					cin>>x>>y;
					b[x]=1;
					v[x]=y;
					if(a[y]!=-1)a[x]=a[y];
				}
				else
				{
					cin>>x;
					b[x]=0;
					v[x]=0;
					if(ch=='U')a[x]=-2;
					if(ch=='T')a[x]=1;
					if(ch=='F')a[x]=0;
				}
			}
		}
		for(int i=1;i<=m;i++)dfs(i);

*/



			/*for(int i=1;i<=n;i++)
			{
				a[i]=0;
				px[i]=0;
				h[i]=0;
				KK[i]=0;
				p1[i]=0;
				p2[i]=0;
			}
			pp=0;
			we=0;
			ans=0;
			for(int i=1;i<=m;i++)
			{
				cin>>ch;
				if(ch=='U')
				{
					cin>>x;
					a[x]=1;
					if(px[x]==0)
					{
						we++;
						px[x]=we;
						h[we]=1;
					}
					KK[px[x]]=1;
				}
				else
				{
					cin>>x>>y;
					if(px[y]==0&&px[x]==0)
					{
						we++;
						px[y]=we;px[x]=we;
						h[we]=2;
						if(a[y]==1 || a[x]==1)
						{
							a[y]=1;a[x]=1;
							KK[we]=1;
						}
					}
					else
					if(px[y]!=0&&px[x]==0)
					{
						h[px[y]]++;
						px[x]=px[y];
						if(a[x]==1)KK[px[x]]=1;
					}
					else
					if(px[y]==0&&px[x]!=0)
					{
						h[px[x]]++;
						px[y]=px[x];
						if(a[y]==1)KK[px[x]]=1;
					}else
					{
						//h[px[x]]+=h[px[y]];
					//	h[px[y]]=0;
						pp++;
						p1[pp]=x;p2[pp]=y;
						if(KK[px[y]]==1)KK[px[x]]=1;
						if(KK[px[x]]==1)KK[px[y]]=1;
					}
				}
			}
			for(int i=1;i<=100;i++)
			{
				for(int j=1;j<=pp;j++)
				{
					//h[px[p1[j]]]+=h[px[p2[j]]];
					//h[px[p2[j]]]=0;
					if(KK[px[p2[j]]]==1)KK[px[p1[j]]]=1;
					if(KK[px[p1[j]]]==1)KK[px[p2[j]]]=1;
				}
			}
			for(int i=1;i<=we;i++)
				if(KK[i])ans+=h[i];
			cout<<ans<<endl;5/6*/