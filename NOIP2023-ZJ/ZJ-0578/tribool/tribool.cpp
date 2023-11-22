#include<bits/stdc++.h>
using namespace std;
#define ll int 
ll c,n,m,k,t;
char v;
const int N=1e5+10;
int fa[N];
ll ans;
ll a[N];
ll id;

ll read() {
	ll uu=0;
	char c;
	c=getchar();
	while(!isdigit(c))
		c=getchar();
	while(isdigit(c)) {
		uu=(uu<<3)+(uu<<1)+(c^48);
		c=getchar();
	}
	return uu;
}
ll get(ll x,ll bs) {
	if(fa[x]==x||bs>=n) return x;
	else
		return fa[x]=get(fa[x],++bs);
}
int main() {
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	c=read();
	t=read();
	if(c>=5&&c<=6)
		while(t--) {
			n=read();
			m=read();
			ans=0;
			for(int i=1; i<=N-1; i++)
				a[i]=0;
			for(int i=1; i<=N-1; i++)
				fa[i]=i;
			for(int i=1; i<=m; i++) 
			{
				cin>>v;
				if(v=='U') {
					id=read();
					a[id]=2;
				//	fa[id]=id;
				}
				else
				if(v=='+') {
				   int 	x=read();
				   int 	y=read();
                    a[x]=a[y];
                    if(a[x]!=2)
                      fa[x]=get(y,0);
				}
			}
			for(int i=1; i<=n; i++)
			  {
			  	if(a[i]==2||a[get(i,0)]==2) 
				  {
				    ans++;
				  }
			  }
			printf("%lld\n",ans);

		}
	else 
	if(c==3||c==4)
	{
		while(t--) {
			n=read();
			m=read();
			ans=0;
			for(int i=1; i<=N-1; i++)
				a[i]=0;
			for(int i=1; i<=m; i++) {
				cin>>v;
				int x,y;
				if(v=='U') {
					id=read();
					a[id]=2;
				}
				if(v=='F') {
					id=read();
					a[id]=0;
				}
				if(v=='T') {
					id=read();
					a[id]=1;
				}
			}
			for(int i=1; i<=n; i++)
				if(a[i]==2) ans++;
			printf("%lld\n",ans);

		}
	}
	else
	{
		while(t--)
		  {
		  	  cout<<0<<endl;
		  }
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//Y@T2L32#
