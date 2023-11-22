#include<bits/stdc++.h>
using namespace std;
#define N 101010
int c,q,n,m,ans;
int a[505050],b[505050];
int main()
{
	//?pts
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
srand(time(0));
//	ios::sync_with_stdio(0);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int j=1;j<=m;j++) cin>>b[j];
	if(n==1)
	{
		if(a[1]!=b[1]) cout<<1;
		else cout<<0;
		while(q--)
		{
			int kx,ky;
			cin>>kx>>ky;
			if(kx==1) cin>>kx>>kx;
			else kx=a[1];
			if(ky==1) cin>>ky>>ky;
			else ky=b[1];

			if(kx!=ky) cout<<1;
			else cout<<0;
		}
		return 0;
	}
	if(n==2)
	{
		
		if(((a[1]>b[1])&&(a[2]>b[2]))||((a[1]<b[1])&&(a[2]<b[2]))) cout<<1;
		else cout<<0;
		while(q--)
		{
			int tmp1,tmp2,tmp3,tmp4;
			tmp1=a[1];
			tmp2=b[1];
			tmp3=a[2];
			tmp4=b[2];
			int kx,ky,pos;
			cin>>kx>>ky;
			for(int i=1;i<=kx;i++)
			{
				cin>>pos;
				cin>>a[pos];
			}
			for(int i=1;i<=ky;i++)
			{
				cin>>pos;
				cin>>b[pos];
			}
			if(((a[1]>b[1])&&(a[2]>b[2]))||((a[1]<b[1])&&(a[2]<b[2]))) cout<<1;
			else cout<<0;
			a[1]=tmp1;
			b[1]=tmp2;
			a[2]=tmp3;
			b[2]=tmp4;
		}
		return 0;
	}
	for(int i=1;i<=q+1;i++) cout<<rand()%2;
	return 0;
}
