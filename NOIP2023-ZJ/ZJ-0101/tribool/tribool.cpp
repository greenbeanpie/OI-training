#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll _=2e5+5;
ll ID,N,n,q,x,y,s,a[_],b[_],c[_],d[_],i;char ch;
void p(ll x){b[x]==x?x:(p(b[x]),c[x]^=c[b[x]],b[x]=b[b[x]]);}
void p2(ll x,ll y,ll z){
	p(x);p(y);
	if(b[x]!=b[y])c[b[y]]=c[x]^c[y]^z,d[b[x]]|=d[b[y]],d[b[y]]=0,b[b[y]]=b[x];
	else if(c[x]^c[y]^z)d[b[x]]=1;
}
void P(){
	cin>>n>>q;s=0;
	for(i=1;i<=n;i++)a[i]=i+1;
	while(q--){
		cin>>ch;
		if(ch=='T')cin>>x,a[x]=1;
		if(ch=='U')cin>>x,a[x]=0;
		if(ch=='F')cin>>x,a[x]=-1;
		if(ch=='+')cin>>x>>y,a[x]=a[y];
		if(ch=='-')cin>>x>>y,a[x]=-a[y];
	}
	for(i=0;i<=n+2;i++)b[i]=i,c[i]=d[i]=0;
	d[0]=1;
	for(i=1;i<=n;i++)p2(i+1,abs(a[i]),a[i]<0);
	for(i=1;i<=n;i++)p(i+1),s+=d[b[i+1]];
	cout<<s<<'\n';
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>ID>>N;while(N--)P();
}