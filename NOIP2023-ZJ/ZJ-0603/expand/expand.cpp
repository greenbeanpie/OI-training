#include<bits/stdc++.h>
using namespace std;
int n,m,Ans;
int a[250],b[250];
void f()
{
	if((a[1]-b[1])*(a[2]-b[2])>0) cout<<1;
	else cout<<0;
	return;
}
void change(int kx,int ky)
{
	for(int i=1;i<=kx;i++)
		{
			int x,y;
			cin>>x>>y;
			a[x]=y;
		}
	for(int j=1;j<=ky;j++)
		{
			int x,y;
			cin>>x>>y;
			b[x]=y;
		}
	return;
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int c,q;
	bool p=1;
	cin>>c>>n>>m>>q;
	while(q--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=m;i++)
			cin>>b[i];
		if(c==1)
		{
			if(p)
			{
				if(a[1]!=b[1]) cout<<1;
				else cout<<0;
				p=0;
			}
			int kx,ky;
			cin>>kx>>ky;
			change(kx,ky);
			if(a[1]!=b[1]) cout<<1;
			else cout<<0;
		}
		if(c==2)
		{
			if(p)
			{
				f();
				p=0;
			}
			int kx,ky;
			cin>>kx>>ky;
			change(kx,ky);
			f();
		}
	}
	
	fclose(stdin); fclose(stdout);
	return 0;
}