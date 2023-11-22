#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,q,n,m;
ll a[100010],f[100010];
map<char,int>ch;
ll fa(ll x){
	if(f[x]==x)
	return x;
	return f[x]=fa(f[x]);
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%lld%lld",&c,&q);
	ch['U']=2;
	ch['T']=1;
	ch['F']=0;
	if(c==5||c==6){
		while(q--){
			scanf("%lld%lld",&n,&m);
			memset(a,0,sizeof(a));
			for(int i=1;i<=n;i++)
			f[i]=i;
			for(int i=1;i<=m;i++){
				char v;
				cin>>v;
				if(v=='U'){
					ll num;
					cin>>num;
					a[num]=2;
				}
				else{
					ll x,y;
					cin>>x>>y;
					f[fa(x)]=f[y];
				}
			}
			ll t=0;
			for(int i=1;i<=n;i++){
				if(a[f[i]]==2)
				t++;
			}
			cout<<t;
			return 0;
		}
	}
	while(q--){
		scanf("%lld%lld",&n,&m);
		memset(a,0,sizeof(a));
		int t=0,t1=0;
		for(int i=1;i<=m;i++){
			char v;
			cin>>v;
			if(v=='U'||v=='T'||v=='F'){
				ll num;
				scanf("%lld",&num);
				a[num]=ch[v];
				t1++;
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i]==2)
			t++;
		}
		if(t1==m){
			cout<<t<<endl;
			continue;
		}
	}
	
}
