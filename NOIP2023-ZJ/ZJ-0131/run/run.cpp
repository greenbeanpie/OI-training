#include<bits/stdc++.h>
#define rd read()
#define ll long long
#define ve vector<ll>
#define pa pair<ll,ll>
using namespace std;
inline ll read(){
	ll x=0,f=1;char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
ll n,m,k,t,d,ans,o;
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	rd;t=rd;
	while(t--){
		n=rd;m=rd;k=rd;d=rd;ans=0;
		for(int i=1;i<=m;i++){
			ll x=rd,y=rd,z=rd;
			if(z-y*d>0){
				ans+=z-y*d;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
