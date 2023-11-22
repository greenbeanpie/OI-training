#include<bits/stdc++.h>
#define ri int
using namespace std;
const int N=500005;
int C,n,m,q,la[N],lb[N],a[N],b[N],c[N],d[N],LA[N*3],LB[N*3],pr[N];
vector<pair<int,int> >q1[N],q2[N];
int f[N*3],s;
bool ck(){
	ri mna=2e9,mnb=2e9,mxa=-1,mxb=-1;
	for(ri i=1;i<=n;++i)mna=min(mna,a[i]),mxa=max(mxa,a[i]);
	for(ri i=1;i<=m;++i)mnb=min(mnb,b[i]),mxb=max(mxb,b[i]);
	if(mxa>=mxb)return 0;if(mna>=mnb)return 0;
	for(ri i=1,j=0;i<=s;++i){
		while(i>=b[j+1]&&j<m)++j;
		LA[i]=j;
	}
	for(ri i=1;i<=n;++i)la[i]=LA[a[i]];
	for(ri i=s,j=0;i;--i){
		while(i<=a[j+1]&&j<n)++j;
		LB[i]=j;
	}
	for(ri i=1;i<=m;++i)lb[i]=LB[b[i]];
	for(ri i=1;i<=m;++i)pr[i]=max(pr[i-1],lb[i]);
	for(ri i=1;i<=n;++i)if(pr[la[i]]>=i)return 0;
	for(ri i=1,j=m+1;i<=s;++i){
		while(i>=b[j-1]&&j>1)--j;
		LA[i]=j;
	}
	for(ri i=1;i<=n;++i)la[i]=LA[a[i]];
	for(ri i=s,j=n+1;i;--i){
		while(i<=a[j-1]&&j>1)--j;
		LB[i]=j;
	}
	for(ri i=1;i<=m;++i)lb[i]=LB[b[i]];pr[m+1]=n+1;
	for(ri i=m;i;--i)pr[i]=min(pr[i+1],lb[i]);
	for(ri i=1;i<=n;++i)if(pr[la[i]]<=i)return 0;
	return 1;
}
void sol(){
	ri o=ck();if(o){printf("1");return;}
	swap(n,m);for(ri i=1;i<=max(n,m);++i)swap(a[i],b[i]);
	o=ck();swap(n,m);printf("%d",o);
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>C>>n>>m>>q;
	for(ri i=1;i<=n;++i)cin>>a[i],f[++s]=a[i];
	for(ri i=1;i<=m;++i)cin>>b[i],f[++s]=b[i];
	for(ri u,v,i=1;i<=q;++i){
		cin>>u>>v;
		for(ri x,y;u--;)cin>>x>>y,q1[i].push_back({x,y}),f[++s]=y;
		for(ri x,y;v--;)cin>>x>>y,q2[i].push_back({x,y}),f[++s]=y;
	}
	sort(f+1,f+1+s);s=unique(f+1,f+1+s)-f-1;
	for(ri i=1;i<=n;++i)c[i]=a[i]=lower_bound(f+1,f+1+s,a[i])-f;
	for(ri i=1;i<=m;++i)d[i]=b[i]=lower_bound(f+1,f+1+s,b[i])-f;
	sol();
	for(ri j=1;j<=q;++j){
		for(ri i=1;i<=n;++i)a[i]=c[i];
		for(ri i=1;i<=m;++i)b[i]=d[i];
		for(auto i:q1[j])a[i.first]=lower_bound(f+1,f+1+s,i.second)-f;
		for(auto i:q2[j])b[i.first]=lower_bound(f+1,f+1+s,i.second)-f;
		sol();
	}
	return 0;
}
