#include<bits/stdc++.h>
using namespace std;
int c,n,m,q,kx,ky,flag=0;
int a[500001],b[500001];
int ax[500001],by[500001],maxa=-1,maxb=-1;
void mems()
{
	maxa=-1,maxb=-1;
	for(int i=1;i<=n;i++)
		ax[i]=a[i],maxa=max(maxa,a[i]);
	for(int i=1;i<=m;i++)
		by[i]=b[i],maxb=max(maxb,b[i]);
}
int solve()
{
	if(ax[1]==by[1])return 0;
	if(ax[1]>by[1])flag=1;
	else flag=-1;
	if((ax[n]-by[m])*flag<=0)return 0;
	if(maxa>=maxb&&flag==-1)return 0;
	if(maxa<=maxb&&flag==1)return 0;
	return 1;
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
		cin>>b[i];
	if(c==1)
	{
		for(int i=1;i<=q;i++)
			cout<<1;
		return 0;
	}
	mems();
	cout<<solve();
	while(q--)
	{
		mems();
		cin>>kx>>ky;
		for(int i=1;i<=kx;i++)
		{
			int x,y;
			cin>>x>>y;
			ax[x]=y;
			maxa=max(maxa,y);
		}
		for(int i=1;i<=ky;i++)
		{
			int x,y;
			cin>>x>>y;
			by[x]=y;
			maxb=max(maxb,y);
		}
		cout<<solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}