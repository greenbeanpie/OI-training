#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll n,m,k,d;
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
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ll c=read();
	ll t=read();
	while(t--)
	  {
	  	  n=read();m=read();k=read();d=read();
	  	  ll maxn=0;
	  	  for(int i=1;i<=m;i++)
	  	    {
	  	    ll x=read();
	  	    ll y=read();
	  	    ll v=read();
	  	      maxn=maxn+max(0LL,v-y*k);	
			}
	  	  cout<<max(maxn,0LL)<<endl;
	  }
	fclose(stdin);
	fclose(stdout);
	return 0;
}
